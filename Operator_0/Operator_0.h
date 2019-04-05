//
// Created by hwy on 2019/4/1.
//

#ifndef BIGHOMEWORK_OPERATOR_0_H
#define BIGHOMEWORK_OPERATOR_0_H

#include "../Node.h"

class Operator_0 : public Node{
public:
    Operator_0(std::string& name, float x = 0.0);
    virtual int Compt(MyGraph &g, int x);
    virtual int Calc(MyGraph &g) = 0;
};




#endif //BIGHOMEWORK_OPERATOR_0_H

