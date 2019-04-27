//
// Created by yzy on 2019/3/30.
//

#ifndef OOP_OPERATOR_1_H
#define OOP_OPERATOR_1_H

#include "../node.h"
#include <cmath>
class Operator_1:public Node{
protected:
    int num;
public:
    Operator_1(std::string &s, int x);
    virtual int Calc(MyGraph &g) = 0;
    virtual int Compt(MyGraph &g, int x);
    virtual int Derivate(MyGraph& g) = 0;
};


#endif //OOP_OPERATOR_1_H
