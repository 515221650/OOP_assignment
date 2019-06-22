//
// Created by hwy on 2019/6/21.
//

#ifndef OOP_RESHAPE_H
#define OOP_RESHAPE_H

#include "layer.h"
#include "../Operator_1/myreshape.h"

class Reshape : public Layer{
private:
    virtual void build(MyGraph& G);
    Layer& pre_layer;
    std::initializer_list<int> beforesize;
    std::initializer_list<int> aftersize;

public:
    friend Neural_network;
    Reshape(Layer& pre_layer, MyGraph& G, int in_num, int out_num, std::initializer_list<int> beforesize, std::initializer_list<int> aftersize);
};

#endif //OOP_RESHAPE_H
