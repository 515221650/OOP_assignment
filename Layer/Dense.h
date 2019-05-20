//
// Created by player0 on 2019/5/1.
//

#ifndef OOP_DENSE_H
#define OOP_DENSE_H

#include "layer.h"
#include <vector>
class Dense : public Layer {
private:
    std::vector<int>W;  //record wij's index in NodeInfoVec
    std::vector<int>B;  //record bias's index in NodeInfoVec
    Layer& pre_layer;   //the layer before it
    void build(MyGraph& G);
public:
    friend Neural_network;
    Dense(int _in, int _out, Layer& pre, MyGraph &G): Layer(_in, _out), pre_layer(pre)
    {
        build(G);
    }
    int id_w(int i,int j){return W[j*out_num+i];}   //get wij's index in NodeInfoVec
    int id_b(int j){return B[j];}   //get the jth bias's index in NodeInfoVec
};


#endif //OOP_DENSE_H
