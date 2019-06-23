//
// Created by player0 on 2019/5/1.
//

#ifndef OOP_DENSE_H
#define OOP_DENSE_H

#include "layer.h"
#include <vector>

class Dense : public Layer {
private:
    int W;  //record wij's index in NodeInfoVec
    int B;  //record bias's index in NodeInfoVec
    Layer& pre_layer;   //the layer before it
    void build(MyGraph& G);
public:
    friend Neural_network;
    Dense(int _in, int _out, Layer& pre, MyGraph &G): Layer(_in, _out), pre_layer(pre)
    {
        build(G);
    }
};


#endif //OOP_DENSE_H
