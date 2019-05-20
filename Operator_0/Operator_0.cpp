//
// Created by player1 on 2019/4/1.
//

#include "Operator_0.h"

int Operator_0::Compt(MyGraph &g, int x)
{
    int status = 0;
    status = Calc(g);
    g.Mark(x);
    return status;
}



