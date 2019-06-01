//
// Created by hwy on 2019/6/1.
//

#ifndef OOP_MYCRITERION_H
#define OOP_MYCRITERION_H

#include "Operator_2.h"

class MyMSELoss : public Operator_2{//num1是输出，num2是target
public:
    MyMSELoss(std::string &s, int x, int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);

    virtual ~MyMSELoss(){}
};

#endif //OOP_MYCRITERION_H
