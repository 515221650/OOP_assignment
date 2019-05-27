//
// Created by yzy on 2019/5/26.
//

#ifndef OOP_MYAT_H
#define OOP_MYAT_H

#include "operator_2.h"
class MyAt : public Operator_2{
public:
    MyAt(std::string &s, int x, int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyAt();
};


#endif //OOP_MYAT_H
