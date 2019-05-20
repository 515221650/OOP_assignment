//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_MYASSIGN_H
#define OOP_MYASSIGN_H

#include "Operator_2.h"

class MyAssign : public Operator_2{
public:
    MyAssign(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyAssign(){}
};



#endif //OOP_MYASSIGN_H
