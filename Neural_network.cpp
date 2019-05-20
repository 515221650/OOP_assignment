//
// Created by player0 on 2019/5/3.
//

#include "Neural_network.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#define INF 1E9
int Neural_network::output(int j)
{
    return seq[seq.size() - 1]->output(j);
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

void Neural_network::train(const std::vector<std::vector<double>> &InputData, const std::vector<double> &TargetData, MyGraph &G, int epoch, int batchsize)
{
    double learn_rate = 3;
    int out_num = seq[seq.size() - 1]->get_size();  // the number of outputs
    for(int time = 1; time <= epoch; time++)
    {
        double cnt_correct = 0.0;
        double cnt2 = 0.0; //used if you want to see the process more details
        for(std::size_t num = 0; num < InputData.size(); num++) //warning : each loop may take fairly long time
        {
            std::vector<double>labels(out_num);
            labels[TargetData[num]] = 1.0;  //label the right answer

            seq[0]->change_input(InputData[num], G);    //input the image's data
            for (auto i: G.NodeInfoVec)
            {
                i.NodePos->rev_der(0);
            }

            G.erase_mark();
            double mx = -INF; int id = 0;
            for (int i = 0; i < out_num; i++)   //compute the val of all the nodes in the network
            {
                int pos = output(i);
                Node *OutputNode = G.NodeInfoVec[pos].NodePos;
                OutputNode->Compt(G, pos);
                G.clear_DerVec();
                if(OutputNode->Val() > mx)
                {
                    mx = OutputNode->Val(); //pick out the largest val among output nodes
                    id = i;
                }
            }

            if(id == TargetData[num])   //check if the answer is correct
            {
                cnt_correct += 1.0;
                cnt2 += 1.0;
            }

            //evaluation function: sigma((outputvalue-standard_outputvalue)^2)
            for (int i = 0; i < out_num; i++)   //calc output-node's derivative to each node
            {
                int pos = output(i);
                G.erase_der();
                Node *OutputNode = G.NodeInfoVec[pos].NodePos;
                OutputNode->rev_der(1);
                int sz_info = G.NodeInfoVec.size();
                for (int j=sz_info-1;j>=0;j--)
                {
                    G.NodeInfoVec[j].NodePos->Derivate(G);
                }
                double delta = G.NodeInfoVec[pos].NodePos->Val() - labels[i];
                for (auto j: G.NodeInfoVec)
                {
                    j.NodePos->add_dersum(delta * j.NodePos->Der());    //and add them up to get evaluation function's derivative to each node
                }
            }

            if((num + 1) % batchsize == 0 || std::size_t(num) == InputData.size() - 1)   //gradient descent algorithm
            {
                for (std::size_t i = 1; i < seq.size(); i++)
                {
                    auto nowd = dynamic_cast<Dense *>(seq[i]);
                    for (auto j: nowd->W)
                    {
                        Node *nown = G.NodeInfoVec[j].NodePos;
                        nown->add_val(-nown->DerSum() * learn_rate / batchsize);
                    }
                    for (auto j: nowd->B)
                    {
                        Node * nown = G.NodeInfoVec[j].NodePos;
                        nown->add_val(-nown->DerSum() * learn_rate / batchsize);
                    }
                }
                for (auto i: G.NodeInfoVec)i.NodePos->rev_dersum(0);
                std::cout << "nownum:" << num << " " << "accuracy:" << cnt2/batchsize<< std::endl;
               cnt2 = 0;
            }

        }
        learn_rate *= 0.9;
        std::cout << "epoch:" << time << " " << "accuracy:" << cnt_correct/InputData.size() << std::endl;
        save(time, G);
    }
}

void Neural_network::test(const std::vector<std::vector<double>> &InputData, const std::vector<double> &TargetData, MyGraph &G) //test
{
    double cnt_correct = 0.0;int out_num = seq[seq.size() - 1]->get_size();
    for(std::size_t num = 0; num < InputData.size(); num++)
    {
        seq[0]->change_input(InputData[num], G);
        G.erase_mark();
        double mx = -INF; int id = 0;
        for (int i = 0; i < out_num; i++)
        {
            int pos = output(i);
            Node *OutputNode = G.NodeInfoVec[pos].NodePos;
            OutputNode->Compt(G, pos);
            G.clear_DerVec();
            if(OutputNode->Val() > mx)
            {
                mx = OutputNode->Val();
                id = i;
            }
        }
        if(id == TargetData[num])cnt_correct += 1.0;
    }
    std::cout << "accuracy:" << cnt_correct/InputData.size() << std::endl;
}

void Neural_network::save(int cnt, MyGraph& G)  //save the val of each node
{
    char file[100];
    sprintf(file, "epoch%d_time=%ld.txt", cnt, clock());
    freopen(file, "w", stdout);
    std::cout<<cnt<<std::endl;
    for(std::size_t i = 1; i < seq.size(); i++)
    {
        auto nowd = dynamic_cast<Dense *>(seq[i]);
        for(auto j : nowd->W)
        {
            Node *nown = G.NodeInfoVec[j].NodePos;
            std::cout<<nown->Val()<<' ';
        }std::cout<<std::endl;
        for(auto j : nowd->B)
        {
            Node *nown = G.NodeInfoVec[j].NodePos;
            std::cout<<nown->Val()<<' ';
        }std::cout<<std::endl;
    }
    fclose(stdout);
    freopen("CON","w",stdout);  //for Windows
    //freopen("/dev/tty","w",stdout);   //for Linux
}

int Neural_network::load(std::string filename, MyGraph& G)  //load the data of each node( to continue the process)
{
    freopen(filename.c_str(), "r", stdin);
    int cnt; std::cin>>cnt;
    for(std::size_t i = 1; i < seq.size(); i++)
    {
        auto nowd = dynamic_cast<Dense *>(seq[i]);
        for(auto j : nowd->W)
        {
            Node *nown = G.NodeInfoVec[j].NodePos;
            float tmp;std::cin>>tmp;
            nown->rev_val(tmp);
        }
        for(auto j : nowd->B)
        {
            Node *nown = G.NodeInfoVec[j].NodePos;
            float tmp;std::cin>>tmp;
            nown->rev_val(tmp);
        }
    }
    fclose(stdin);
    return cnt;
}