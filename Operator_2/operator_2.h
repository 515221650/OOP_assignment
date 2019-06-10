//
// Created by player0 on 2019/3/30.
//

#ifndef OOP_OPERATOR_2_H
#define OOP_OPERATOR_2_H

#include "../Node.h"
#include "../ts.h"

class Operator_2:public Node{
protected:
    int num1,num2;

public:
    Operator_2(std::string &s, int x ,int y):Node(s), num1(x), num2(y){};

    virtual int Calc(MyGraph &v) = 0;
    virtual int Derivate(MyGraph& g) = 0;
    virtual int Compt(MyGraph& g, int x);

    virtual ~Operator_2(){};
};

#endif //OOP_OPERATOR_2_H
