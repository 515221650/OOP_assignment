//
// Created by hwy on 2019/6/1.
//
#include "criterion.h"
#include "../Operator_2/mycriterion.h"

MSELoss::MSELoss(Layer &pre_layer, Layer &tar_layer, MyGraph &G): Criterion(pre_layer, tar_layer)
{
    build(G);
}

void MSELoss::build(MyGraph &G)
{
    std::string name;
    auto newnode = new MyMSELoss(name, pre_layer->output(), tar_layer->output());
    G.insert_node(newnode, name);
    out_pos = G.str_to_int(name);
}
