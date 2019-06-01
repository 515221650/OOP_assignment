//
// Created by player0 on 2019/5/1.
//

#ifndef OOP_LAYER_H
#define OOP_LAYER_H

#include "../Node.h"
class Neural_network;

class Layer {
protected:
    int in_num, out_num;    //number of input nodes, number of output nodes in the layer
    int out_pos;    //the index of output node in NodeInfoVec

public:
    Layer(int _in, int _out) : in_num(_in), out_num(_out) {}

    int get_size() { return out_num; }

    int output() { return out_pos;}

    virtual void change_input(const Tensor &input, MyGraph &G) {};
};

/*class Layer {
protected:
    int in_num, out_num;    //number of input nodes, number of output nodes in the layer
    std::vector<int>out_vec;    //the index of each output node in NodeInfoVec

public:
    Layer(int _in, int _out): in_num(_in), out_num(_out){}

    int get_size(){return out_num;}
    int output(int num){return out_vec[num];}
    virtual void change_input(const std::vector<double> &input, MyGraph &G){};  //used in class Input
};*/


#endif //OOP_LAYER_H
