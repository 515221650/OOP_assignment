//
// Created by yzy on 2019/6/1.
//

#ifndef OOP_MYCONV_H
#define OOP_MYCONV_H

#include "operator_2.h"

class MyConv : public Operator_2{
private:
    int padding, stride;
public:
    MyConv(std::string &s, int x,int y, int _padding = 0, int _stride = 1);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyConv(){}
};


#endif //OOP_MYCONV_H
