//
// Created by yzy on 2019/6/1.
//

#include "maxpool.h"
#include "../Operator_1/mymaxpool.h"

void MaxPool::build(int kernel_size, int stride, MyGraph &G)
{
    std::string M_name;
    auto newNode = new MyMaxPool(M_name, pre_layer.output(), kernel_size, stride);
    G.insert_node(newNode, M_name);
    out_pos = G.str_to_int(M_name);
};