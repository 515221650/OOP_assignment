//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_MYBIND_H
#define OOP_MYBIND_H

#include "Operator_2.h"

class MyBind : public Operator_2{
public:
    MyBind(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyBind(){}
};


#endif //OOP_MYBIND_H
