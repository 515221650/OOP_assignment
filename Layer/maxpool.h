//
// Created by yzy on 2019/6/1.
//

#ifndef OOP_MAXPOOL_H
#define OOP_MAXPOOL_H

#include "layer.h"

class MaxPool : public Layer{
private:
    Layer& pre_layer;
public:
    friend Neural_network;
    MaxPool(int _in, int _out, Layer& pre, MyGraph& G, int kernel_size = 2, int stride = 2) : Layer(_in, _out), pre_layer(pre)
    {
        build(kernel_size, stride, G);
    }
    void build(int kernel_size, int stride, MyGraph &G);
};


#endif //OOP_MAXPOOL_H
