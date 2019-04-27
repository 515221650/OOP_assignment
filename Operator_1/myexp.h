//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYEXP_H
#define OOP_MYEXP_H

#include "operator_1.h"
class MyExp : public Operator_1 {
public:
    MyExp(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);
};


#endif //OOP_MYEXP_H
