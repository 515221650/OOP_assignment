//
// Created by yzy on 2019/5/3.
//

#include "Neural_network.h"
#include <algorithm>
void Neural_network::add_Input(int num, MyGraph& G)
{
    seq.push_back(new Input(num, G));
}
void Neural_network::add_Dense(int num, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new Dense(tmp->get_size(), num, *tmp, G));
}

void Neural_network::train(const std::vector<double> &InputData, const std::vector<double> &TargetData, MyGraph &G)
{
    double learn_rate = 0.5;
    seq[0]->change_input(InputData, G);
    //cal_Output(G);
    for(auto i: G.NodeInfoVec)
    {
        i.NodePos->rev_der(0);
        i.NodePos->rev_dersum(0);
    }
    for(auto i: seq[0]->out_vec) G.NodeInfoVec[i].NodePos->rev_der(1);
    for(int i=0;i<seq[seq.size()-1]->out_vec.size();i++)
    {
        int pos = seq[seq.size()-1]->out_vec[i];
        G.erase_mark();
        G.DerVec.clear();
        Node* OutputNode = G.NodeInfoVec[pos].NodePos;
        OutputNode->Compt(G, pos);
        G.erase_der();
        OutputNode->rev_der(1);
        reverse(G.DerVec.begin(),G.DerVec.end());
        for(auto j: G.DerVec)
        {
            G.NodeInfoVec[j].NodePos->Derivate(G);
        }
        double delta = G.NodeInfoVec[pos].NodePos->Val() - TargetData[i];
        for(auto j: G.NodeInfoVec)
        {
            j.NodePos->add_dersum(delta * j.NodePos->Der());
        }
    }
    for(int i=1;i<seq[seq.size()-1]->out_vec.size();i++)
    {
        Dense* nowd = dynamic_cast<Dense*>(seq[i]);
        for(auto j: nowd->W)
        {
            Node* nown = G.NodeInfoVec[j].NodePos;
            nown->add_val(-nown->DerSum()*learn_rate);
        }
    }
}