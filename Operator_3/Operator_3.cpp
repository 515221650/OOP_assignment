//
// Created by HWY on 2019/4/1.
//
#include "Operator_3.h"
#inclu
Operator_3::Operator_3(std::string &s, int x, int y, int z): Node(s), num1(x), num2(y), num3(z){}

int Operator_3::Compt(const MyGraph& g,int x)
{
    int status = 0;
    if(!g[num1].vis) status = (g[num1].NodePos)->Compt(g, num1);
    if(status) return status;
    if(!g[num2].vis) status = (g[num2].NodePos)->Compt(g, num2);
    if(status) return status;
    if(!g[num3].vis) status = (g[num3].NodePos)->Compt(g);
    if(status) return status;
    status = Calc(g);
    g.Mark(x);
    return status;
}