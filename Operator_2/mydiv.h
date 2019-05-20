//
// Created by player0 on 2019/3/31.
//

#ifndef OOP_MYDIV_H
#define OOP_MYDIV_H

#include "operator_2.h"

class MyDiv : public Operator_2{
public:
    MyDiv(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyDiv(){}
};


#endif //OOP_MYDIV_H
