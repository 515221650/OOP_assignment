//
// Created by player0 on 2019/4/1.
//

#ifndef OOP_MYGREATEREQUAL_H
#define OOP_MYGREATEREQUAL_H

#include "operator_2.h"
class MyGreaterEqual : public Operator_2 {
public:
    MyGreaterEqual(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyGreaterEqual(){}
};



#endif //OOP_MYGREATEREQUAL_H
