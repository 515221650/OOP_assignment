//
// Created by WLY on 2019/4/1.
//

#ifndef BIGHOMEWORK_OPERATOR_3_H
#define BIGHOMEWORK_OPERATOR_3_H
#include<string>
#include "../Node.h"

class Operator_3: public Node{
protected:
    int num1, num2, num3;
public:
    virtual int Compt(MyGraph& g, int x);
    virtual int Calc(MyGraph &g) = 0;
    Operator_3(std::string& s, int x, int y, int z);
};

#endif //BIGHOMEWORK_OPERATOR_3_H
