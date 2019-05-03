//
// Created by yzy on 2019/5/3.
//

#include "Neural_network.h"
void Neural_network::add_Input(int num, MyGraph& G)
{
    seq.push_back(new Input(num, G));
}
void Neural_network::add_Dense(int num, MyGraph &G)
{
    Layer* tmp = seq.back();
    seq.push_back(new Dense(tmp->get_size(), num, *tmp, G));
}