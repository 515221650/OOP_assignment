//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYSIN_H
#define OOP_MYSIN_H

#include "operator_1.h"

class MySin : public Operator_1 {
public:
    MySin(std::string &s, int x);
    virtual int Calc(Node **v);
};


#endif //OOP_MYSIN_H
