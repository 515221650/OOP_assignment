//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYCONST_H
#define BIGHOMEWORK_MYCONST_H
#include "Operator_0.h"

class MyConst : public Operator_0{
public:
    virtual int Calc(MyGraph& g);
    MyConst(std::string& name, Tensor x);

    virtual ~MyConst(){}
};

#endif //BIGHOMEWORK_MYCONST_H
