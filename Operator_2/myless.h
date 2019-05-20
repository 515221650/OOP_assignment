//
// Created by player0 on 2019/4/1.
//

#ifndef OOP_MYLESS_H
#define OOP_MYLESS_H

#include "operator_2.h"
class MyLess : public Operator_2 {
public:
    MyLess(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyLess(){};
};



#endif //OOP_MYLESS_H
