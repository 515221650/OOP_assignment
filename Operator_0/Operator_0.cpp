//
// Created by HWY on 2019/4/1.
//

#include "Operator_0.h"

Operator_0::Operator_0(std::string &name, float x = 0.0):Node(name,x){}

int Compt(MyGraph &g, int x)
{
    int status = 0;
    status = Calc(g);
    g.Mark(x);
    return status;
}



