//
// Created by yzy on 2019/3/30.
//

#ifndef OOP_MYPLUS_H
#define OOP_MYPLUS_H

#include "operator_2.h"

class MyPlus: public  Operator_2{
public:
    MyPlus(std::string &s, int x, int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);
};


#endif //OOP_MYPLUS_H
