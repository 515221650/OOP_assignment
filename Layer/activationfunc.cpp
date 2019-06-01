//
// Created by hwy on 2019/6/1.
//
#include "activationfunc.h"
#include "../Operator_1/mysigmoid.h"
#include "../Operator_1/myrelu.h"

ReLU::ReLU(Layer& pre_layer, MyGraph& G): Activation(pre_layer)
{
    build(G);
}

void ReLU::build(MyGraph &G)
{
    std::string name;
    auto newnode = new MyReLU(name, pre_layer->output());
    G.insert_node(newnode, name);
    out_pos = G.str_to_int(name);
}



Sigmoid::Sigmoid(Layer& pre_layer, MyGraph &G):  Activation(pre_layer)
{
    build(G);
}

void Sigmoid::build(MyGraph &G)
{
    std::string name;
    auto newnode = new MySigmoid(name, pre_layer->output());
    G.insert_node(newnode, name);
    out_pos = G.str_to_int(name);
}