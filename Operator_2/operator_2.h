//
// Created by yzy on 2019/3/30.
//

#ifndef OOP_OPERATOR_2_H
#define OOP_OPERATOR_2_H

#include "../node.h"

class Operator_2:public Node{
protected:
    int num1,num2;
public:
    virtual int Compt(MyGraph& g, int x);
    virtual int Derivate(MyGraph& g);
    virtual int Calc(MyGraph &v) = 0;
    Operator_2(std::string &s, int x, int y);
};

#endif //OOP_OPERATOR_2_H
