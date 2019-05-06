//
// Created by yzy on 2019/5/3.
//

#ifndef OOP_INPUT_H
#define OOP_INPUT_H


#include "layer.h"
class Input : public Layer {
private:
    void build(MyGraph &G);
public:
    Input(int num, MyGraph &G) : Layer(num, num)
    {
        build(G);
    }
    virtual void change_input(const std::vector<double> &input, MyGraph &G);    //change the node's val in Input Layer (namely input the data of images)
};


#endif //OOP_INPUT_H
