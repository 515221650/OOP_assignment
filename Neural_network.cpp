//
// Created by player0 on 2019/5/3.
//

#include "Neural_network.h"
#include "Utils/Data.h"
#include <algorithm>
#include <iostream>
#include <ctime>

#define INF 1E9

int Neural_network::outputpos()
{
    return seq[seq.size() - 1]->output();
}

int Neural_network::cripos()
{
    return cri->output();
}

void Neural_network::add_Input(int num, MyGraph& G)
{
    seq.push_back(new Input(num, G));
}
void Neural_network::add_Dense(int num, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new Dense(tmp->get_size(), num, *tmp, G));
}

void Neural_network::add_target(int num, MyGraph &G)
{
    tar = new Input(num, G);
}

void Neural_network::add_MSELoss(MyGraph &G)//必须在最后add
{
    cri = new MSELoss(*seq.back(), *tar, G);
}

void Neural_network::add_ReLU(MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new ReLU(*tmp, G));
}

void Neural_network::add_Sigmoid(MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new Sigmoid(*tmp, G));
}

void Neural_network::add_conv(int _in, int _out, MyGraph &G, int _kernel, bool _bias, int _stride, int _padding)
{
    Layer* tmp = seq.back();
    seq.push_back(new Conv(_in, _out, *tmp, G, _kernel, _bias, _stride, _padding));
}

void Neural_network::add_maxpool(int _in, int _out, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new MaxPool(_in, _out, *tmp, G));
}


void Neural_network::train(Dataloader& DataLoader, MyGraph &G, bool need_accu, int epoch, double learn_rate) // batchsize放到dataloaderl里
{
    for(int time = 1; time <= epoch; time++)
    {
        double cnt_correct = 0.0;
        double sum_loss = 0.0;
        //double cnt2 = 0.0; //used if you want to see the process more details
        std::vector<Tensor> InputData;
        std::vector<Tensor> TargetData;
        //要把target变成（0，0，0，1，0，0，0，0，0，0，）的形式
        while(DataLoader.get_data(InputData, TargetData)) //warning : each loop may take fairly long time
        {
            //int batchsize = TargetData.size();
            for(int num=0; num<InputData.size(); num++)
            {

                seq[0]->change_input(InputData[num], G);    //input the image's data
                tar->change_input(TargetData[num], G);

                for (auto i: G.NodeInfoVec)
                {
                    i.NodePos->rev_der(Tensor(0.0));
                }

                G.erase_mark();
                //double mx = -INF; int id = 0;

                Node *OutputNode = G.NodeInfoVec[outputpos()].NodePos;
                Node *CriNode = G.NodeInfoVec[cripos()].NodePos; //criterion
                CriNode->Compt(G, cripos());
                Tensor outputval = OutputNode->Val();

                if(need_accu)   //check if the answer is correct
                {
                    int outputmax = ts::get_max_pos_2d(outputval);
                    int targetmax = ts::get_max_pos_2d(TargetData[num]);
                    if(outputmax == targetmax)
                    {
                        cnt_correct += 1.0;
                        //cnt2 += 1.0;
                    }
                }
                sum_loss += Scalar(CriNode->Val()).get_val();

                //evaluation function: sigma((outputvalue-standard_outputvalue)^2)

                CriNode->rev_der(Tensor(1.0));
                CriNode->Derivate(G);
                for(int p = seq.size()-1; p>=0; p--)
                {
                    G.NodeInfoVec[seq[p]->output()].NodePos->Derivate(G);
                    G.NodeInfoVec[seq[p]->output()].NodePos->add_dersum(G.NodeInfoVec[seq[p]->output()].NodePos->Der());
                }
            }
            //gradient descent algorithm
            for (std::size_t i = 1; i < seq.size(); i++)
            {
                auto nowd = dynamic_cast<Dense *>(seq[i]);
                Node *nown = G.NodeInfoVec[nowd->W].NodePos;
                nown->add_val(-nown->DerSum() * learn_rate / InputData.size());
                nown = G.NodeInfoVec[nowd->B].NodePos;
                nown->add_val(-nown->DerSum() * learn_rate / InputData.size());
            }
            for (auto i: seq) G.NodeInfoVec[i->output()].NodePos->rev_dersum(0);
            //std::cout << "nownum:" << num << " " << "accuracy:" << cnt2/batchsize<< std::endl;
            //cnt2 = 0;

        }
        learn_rate *= 0.9;
        if(need_accu) std::cout << "epoch:" << time << " " << "accuracy:" << cnt_correct/InputData.size() << std::endl;
        std::cout << "epoch:" << time << " " << "loss:" << sum_loss/InputData.size() << std::endl;

        //save(time, G);
    }
}


void Neural_network::test(Dataloader& DataLoader, MyGraph &G, bool need_accu) //test
{
    double cnt_correct = 0.0;
    double loss_sum = 0.0;
    std::vector<Tensor> InputData;
    std::vector<Tensor> TargetData;
    int testsize = 0;
    while(DataLoader.get_data(InputData, TargetData))
    {
        testsize += InputData.size();
        for(int num=0; num<InputData.size(); num++)
        {
            seq[0]->change_input(InputData[num], G);
            G.erase_mark();
            Node *OutputNode = G.NodeInfoVec[outputpos()].NodePos;
            Node *CriNode = G.NodeInfoVec[cripos()].NodePos; //criterion
            CriNode->Compt(G, cripos());
            Tensor outputval = OutputNode->Val();

            if(need_accu)   //check if the answer is correct
            {
                int outputmax = ts::get_max_pos_2d(outputval);
                int targetmax = ts::get_max_pos_2d(TargetData[num]);
                if(outputmax == targetmax)
                {
                    cnt_correct += 1.0;
                    //cnt2 += 1.0;
                }
            }
            loss_sum += Scalar(CriNode->Val()).get_val();
        }
    }
    if (need_accu) std::cout << "accuracy:" << cnt_correct/testsize << std::endl;
    std::cout << "loss:" << loss_sum/testsize << std::endl;
}


void Neural_network::save(int cnt, MyGraph& G)  //save the val of each node
{
    char file[100];
    sprintf(file, "epoch%d_time=%ld.txt", cnt, clock());
    G.save(file);
    //freopen("/dev/tty","w",stdout);   //for Linux
}

int Neural_network::load(std::string filename, MyGraph& G)  //load the data of each node( to continue the process)
{
    freopen(filename.c_str(), "r", stdin);
    G.load(filename);
    return 0;
}