//
// Created by WLY on 2019/6/1.
//

#ifndef OOP_CRITERION_H
#define OOP_CRITERION_H

#include "layer.h"

class Criterion : public Layer{
protected:
    Layer* pre_layer;
    Layer* tar_layer;//target
    virtual void build(MyGraph& G) = 0;
public:
    friend Neural_network;
    explicit Criterion(Layer& pre_layer, Layer& tar_layer): Layer(pre_layer.get_size(), 1), pre_layer(&pre_layer), tar_layer(&tar_layer){}
};


class MSELoss : public Criterion{
private:
    virtual void build(MyGraph& G);
public:
    friend Neural_network;
    MSELoss(Layer& pre_layer, Layer& tar_layer, MyGraph& G);
};

#endif //OOP_CRITERION_H
