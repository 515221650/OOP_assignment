//
// Created by player1 on 2019/4/1.
//
#include "MyCond.h"
#include "../Scalar.h"

MyCond::MyCond(std::string& s, int x, int y, int z):Operator_3(s,x,y,z) {}

int MyCond::Calc(MyGraph& g)
{
    if(Scalar(g[num1].NodePos->Val()).get_val() > 0) val = g[num2].NodePos->Val();
    else val = g[num3].NodePos->Val();
    return 0;
}
int MyCond::Derivate(MyGraph& g)
{
    return 1;
}


