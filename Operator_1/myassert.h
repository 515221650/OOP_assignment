//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_MYASSERT_H
#define OOP_MYASSERT_H

#include "Operator_1.h"
class MyAssert : public Operator_1{
public:
    MyAssert(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyAssert(){}
};


#endif //OOP_MYASSERT_H
