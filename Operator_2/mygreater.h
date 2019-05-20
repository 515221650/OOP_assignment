//
// Created by player0 on 2019/4/1.
//

#ifndef OOP_MYGREATER_H
#define OOP_MYGREATER_H

#include "operator_2.h"
class MyGreater : public Operator_2 {
public:
    MyGreater(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyGreater(){}
};


#endif //OOP_MYGREATER_H
