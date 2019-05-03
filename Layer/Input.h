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
    void change_input(std::vector<int> &input, MyGraph &G);
};


#endif //OOP_INPUT_H
