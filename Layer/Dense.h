//
// Created by yzy on 2019/5/1.
//

#ifndef OOP_DENSE_H
#define OOP_DENSE_H

#include "layer.h"
#include <vector>
class Dense : public Layer {
private:
    std::vector<int>W;
    std::vector<int>B;
    Layer& pre_layer;
    void build(MyGraph& G);
public:
    friend Neural_network;
    Dense(int _in, int _out, Layer& pre, MyGraph &G): Layer(_in, _out), pre_layer(pre)
    {
        build(G);
    }
    int id_w(int i,int j){return W[j*out_num+i];}
    int id_b(int j){return B[j];}
};


#endif //OOP_DENSE_H
