//
// Created by hwy on 2019/4/1.
//

#ifndef BIGHOMEWORK_OPERATOR_0_H
#define BIGHOMEWORK_OPERATOR_0_H

#include "../Node.h"

class Operator_0 : public Node{
public:
    Operator_0(std::string& name, float x);
    virtual void Calc(const MyGraph &g) ;
    virtual int Compt(MyGraph &g, int x);
};




#endif //BIGHOMEWORK_OPERATOR_0_H

