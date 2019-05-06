//
// Created by yzy on 2019/4/1.
//

#ifndef OOP_MYPRINT_H
#define OOP_MYPRINT_H

#include "operator_1.h"
class MyPrint : public Operator_1{
public:
    MyPrint(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);

    virtual ~MyPrint(){}
};


#endif //OOP_MYPRINT_H
