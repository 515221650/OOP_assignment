//
// Created by player0 on 2019/3/31.
//

#ifndef OOP_MYMINUS_H
#define OOP_MYMINUS_H

#include "operator_2.h"

class MyMinus: public Operator_2{
public:
    MyMinus(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyMinus(){};
};


#endif //OOP_MYMINUS_H
