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
    virtual int Compt(const MyGraph& g);
    virtual void Calc(const MyGraph &g) ;
    Operator_3(std::string& s, int x, int y, int z);
};

#endif //BIGHOMEWORK_OPERATOR_3_H
