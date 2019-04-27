//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYSIGMOID_H
#define OOP_MYSIGMOID_H

#include "operator_1.h"
class MySigmoid: public Operator_1{
public:
    MySigmoid(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual void Derivate(MyGraph& g);
};

#endif //OOP_MYSIGMOID_H
