//
// Created by hwy on 2019/6/1.
//

#ifndef OOP_ACTIVATIONFUNC_H
#define OOP_ACTIVATIONFUNC_H

#include "layer.h"

class Activation : public Layer{
protected:
    Layer* pre_layer;
    virtual void build(MyGraph& G) = 0;
public:
    friend Neural_network;
    explicit Activation(Layer& pre_layer): Layer(pre_layer.get_size(), pre_layer.get_size()), pre_layer(&pre_layer){}
};


class ReLU : public Activation{
private:
    virtual void build(MyGraph& G);
public:
    friend Neural_network;
    ReLU(Layer& pre_layer, MyGraph& G);
};

class Sigmoid : public Activation{
private:
    virtual void build(MyGraph& G);
public:
    friend Neural_network;
    Sigmoid(Layer& pre_layer, MyGraph& G);
};

#endif //OOP_ACTIVATIONFUNC_H
