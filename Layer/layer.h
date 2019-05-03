//
// Created by yzy on 2019/5/1.
//

#ifndef OOP_LAYER_H
#define OOP_LAYER_H

#include "../Node.h"

class Layer {
protected:
    int in_num, out_num;
    std::vector<int>out_vec;
public:
    Layer(int _in, int _out): in_num(_in), out_num(_out){}
    int output(int num){return out_vec[num];}
    int get_size(){return out_num;}
};


#endif //OOP_LAYER_H
