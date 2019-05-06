//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYMUL_H
#define OOP_MYMUL_H

#include "operator_2.h"


class MyMul: public Operator_2{
public:
    MyMul(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyMul(){}
};

#endif //OOP_MYMUL_H
