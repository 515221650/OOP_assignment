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
    auto ptr = new Input(num, G);
    seq.push_back(ptr);
}
void Neural_network::add_Dense(int num, MyGraph &G)
{
    Layer* tmp = seq.back();
    Dense* ptr = new Dense(tmp->get_size(), num, *tmp, G);
    seq.push_back(ptr);
    parameter.push_back(ptr->W);
    parameter.push_back(ptr->B);
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
    Conv* ptr = new Conv(_in, _out, *tmp, G, _kernel, _bias, _stride, _padding);
    seq.push_back(ptr);
    parameter.push_back(ptr->K);
    parameter.push_back(ptr->B);
}

void Neural_network::add_maxpool(int _in, int _out, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new MaxPool(_in, _out, *tmp, G));
}

using namespace std;
void Neural_network::train(Dataloader& DataLoader, MyGraph &G, bool need_accu, int epoch, double learn_rate) // batchsize放到dataloaderl里
{
    for(int time = 1; time <= epoch; time++)
    {
        double cnt_correct = 0.0;
        double sum_loss = 0.0;
        double cnt2 = 0.0; //used if you want to see the process more details
        std::vector<Tensor> InputData;
        std::vector<Tensor> TargetData;
        int totalsize = 0;
        int Num = 0;
        while(DataLoader.get_data(InputData, TargetData)) //warning : each loop may take fairly long time
        {
            totalsize += InputData.size();
            Num++;
            cnt2=0;
            for(int num=0; num<InputData.size(); num++)
            {
                seq[0]->change_input(InputData[num], G);    //input the image's data
                tar->change_input(TargetData[num], G);

                for (auto i: G.NodeInfoVec)
                {
                    i.NodePos->rev_der(Tensor(0.0));
                }

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
                        cnt2 += 1.0;
                    }
                }
                sum_loss += Scalar(CriNode->Val()).get_val();

                //evaluation function: sigma((outputvalue-standard_outputvalue)^2)
                CriNode->rev_der(Tensor(1.0));
                CriNode->Derivate(G);

                for(int i = G.NodeInfoVec.size()-1; i >= 0; i--)
                {
                    G[i].NodePos->Derivate(G);
                    G[i].NodePos->add_dersum(G[i].NodePos->Der());
                }
            }
            //gradient descent algorithm
            int c = 0;
            for(auto i : parameter)
            {
                c++;
                G.add_var(i, -G[i].NodePos->DerSum() * learn_rate / InputData.size());
            }
            for (auto i : parameter) G[i].NodePos->rev_dersum(0);
            std::cout << "nownum:" << Num << " " << "accuracy:" << (double)cnt2/InputData.size()<< std::endl; //改成batchsize
        }
        learn_rate *= 0.9;
        if(need_accu) std::cout << "epoch:" << time << " " << "accuracy:" << cnt_correct/totalsize << std::endl;
        std::cout << "epoch:" << time << " " << "loss:" << sum_loss/(Num*InputData.size()) << std::endl;

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
            tar->change_input(TargetData[num], G);

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
           // loss_sum += Scalar(CriNode->Val()).get_val();
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