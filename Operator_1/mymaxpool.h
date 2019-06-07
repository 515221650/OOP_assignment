//
// Created by hwy on 2019/6/7.
//

#ifndef OOP_MYMAXPOOL_H
#define OOP_MYMAXPOOL_H

#include "operator_1.h"

class MyMaxPool : public Operator_1{
private:
    int kernel_size, stride;
public:
    explicit MyMaxPool(std::string &s, int x, int kernel_size = 2, int _stride = 2);
    virtual int Calc(MyGraph &G);
    virtual int Derivate(MyGraph &G);

    virtual ~MyMaxPool(){}

};

#endif //OOP_MYMAXPOOL_H
