//
// Created by hwy on 2019/6/8.
//

#ifndef OOP_MYMATMUL_H
#define OOP_MYMATMUL_H

#include "operator_2.h"

class MyMatMul: public Operator_2{
public:
    MyMatMul(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyMatMul(){}
};

#endif //OOP_MYMATMUL_H
