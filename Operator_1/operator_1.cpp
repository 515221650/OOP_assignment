//
// Created by player0 on 2019/3/30.
//

#include "operator_1.h"

int Operator_1::Compt(MyGraph& g, int x)
{
    int status = 0;
    if(!g[num].vis) status = (g[num].NodePos)->Compt(g, num);
    if(status) return status;
    status = Calc(g);
    g.Mark(x);
    g.push_der(x);
    return status;
}