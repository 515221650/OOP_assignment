//
// Created by player0 on 2019/5/1.
//

#ifndef OOP_LAYER_H
#define OOP_LAYER_H

#include "../Node.h"
#include "../CreateFunc.h"
class Neural_network;

class Layer {
protected:
    int in_num, out_num;    //x in input/output Tensor; if dense, x = number of elements; if conv, x = height;
    int out_pos;    //the index of output node in NodeInfoVec

public:
    Layer(int _in, int _out) : in_num(_in), out_num(_out) {}

    int get_size() { return out_num; }

    int output() { return out_pos;}

    virtual void change_input(const Tensor &input, MyGraph &G) {};
};

#endif //OOP_LAYER_H
