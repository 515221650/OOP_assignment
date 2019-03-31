//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYSIGMOID_H
#define OOP_MYSIGMOID_H

#include "operator_1.h"
class mysigmoid: public Operator_1{
public:
    mysigmoid(std::string &s, int x);
    virtual int Calc(Node **v);
};

#endif //OOP_MYSIGMOID_H
