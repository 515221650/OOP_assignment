//
// Created by yzy on 2019/3/30.
//

#include "operator_1.h"

Operator_1::Operator_1(std::string &s, int x = 0):Node(s), num(x){};
int Operator_1::Compt(MyGraph& g, int x)
{
    int status = 0;
    if(!g[num].vis) status = (g[num].NodePos)->Compt(g, num);
    if(status) return status;
    status = Calc(g);
    g.Mark(x);
    return status;
}