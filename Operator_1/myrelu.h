//
// Created by hwy on 2019/6/1.
//

#ifndef OOP_MYRELU_H
#define OOP_MYRELU_H

#include "operator_1.h"

class MyReLU : public Operator_1
{
public:
    MyReLU(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);

    virtual ~MyReLU(){}
};

#endif //OOP_MYRELU_H
