//
// Created by hwy on 2019/6/21.
//
#include "Reshape.h"

Reshape::Reshape(Layer &pre_layer, MyGraph &G, int in_num, int out_num, std::initializer_list<int> beforesize, std::initializer_list<int> aftersize)
    :Layer(in_num, out_num), pre_layer(pre_layer), beforesize(beforesize), aftersize(aftersize)
    {
        build(G);
    }

void Reshape::build(MyGraph &G)
{
    std::string name;
    auto newnode = new MyReshape(name, pre_layer.output(), beforesize, aftersize);
    G.insert_node(newnode, name);
    out_pos = G.str_to_int(name);
}

