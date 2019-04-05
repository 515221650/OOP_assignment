//
// Created by hwy on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYVAR_H
#define BIGHOMEWORK_MYVAR_H

#include "Operator_0.h"

class MyVar : public Operator_0{
public:
    virtual int Calc(MyGraph& a);
    MyVar(std::string& name, float x);
};

#endif //BIGHOMEWORK_MYVAR_H
