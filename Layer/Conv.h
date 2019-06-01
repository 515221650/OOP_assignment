//
// Created by yzy on 2019/6/1.
//

#ifndef OOP_CONV_H
#define OOP_CONV_H

#include "layer.h"

class Conv : public Layer{
private:
    int padding, stride, kernel_size;
    bool bias;
    int K, B;
    Layer& pre_layer;
public:
    Conv(int _in, int _out, Layer& _prelayer, MyGraph& G, int _kernel = 3, bool _bias= false, int _stride=1, int _padding=0):
        Layer(_in, _out), pre_layer(_prelayer), padding(_padding), stride(_stride), bias(_bias), kernel_size(_kernel)
    {
        build(G);
    }

    void build(MyGraph &G);
};


#endif //OOP_CONV_H
