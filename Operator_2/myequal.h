//
// Created by player0 on 2019/4/1.
//

#ifndef OOP_MYEQUAL_H
#define OOP_MYEQUAL_H

#include "operator_2.h"
class MyEqual : public Operator_2 {
public:
    MyEqual(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyEqual(){}
};


#endif //OOP_MYEQUAL_H
