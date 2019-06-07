//
// Created by player0 on 2019/3/30.
//
#include <iostream>
#include "operator_2.h"

int Operator_2::Compt(MyGraph& G, int x)
{
    int status = 0;
    if(!G[num1].vis) status = (G[num1].NodePos)->Compt(G, num1);
    if(status) return status;
    if(!G[num2].vis) status = (G[num2].NodePos)->Compt(G, num2);
    if(status) return status;

    status = Calc(G);
    G.Mark(x);
    G.push_der(x);
    return status;
}
