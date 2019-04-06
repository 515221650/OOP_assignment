//
// Created by yzy on 2019/3/30.
//
#include <iostream>
#include "operator_2.h"

Operator_2::Operator_2(std::string &s, int x = 0,int y = 0):Node(s), num1(x), num2(y){};


int Operator_2::Compt(MyGraph& g, int x)
{
    int status = 0;
    if(!g[num1].vis) status = (g[num1].NodePos)->Compt(g, num1);
    if(status) return status;
    if(!g[num2].vis) status = (g[num2].NodePos)->Compt(g, num2);
    if(status) return status;
    status = Calc(g);
    g.Mark(x);
    return status;
}