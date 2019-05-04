//
// Created by yzy on 2019/5/1.
//

#ifndef OOP_LAYER_H
#define OOP_LAYER_H

#include "../Node.h"
class Neural_network;

class Layer {
protected:
    int in_num, out_num;
    std::vector<int>out_vec;

public:
    Layer(int _in, int _out): in_num(_in), out_num(_out){}

    int get_size(){return out_num;}
    int output(int num){return out_vec[num];}
    virtual void change_input(const std::vector<double> &input, MyGraph &G){};
};


#endif //OOP_LAYER_H
