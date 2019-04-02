//
// Created by yzy on 2019/4/1.
//

#ifndef OOP_MYLESS_H
#define OOP_MYLESS_H

#include "operator_2.h"
class MyLess : public Operator_2 {
public:
    MyLess(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
};



#endif //OOP_MYLESS_H
