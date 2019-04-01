//
// Created by hwy on 2019/4/1.
//
#include "MyCond.h"

MyCond::MyCond(std::string& s, int x, int y, int z):Operator_3(s,x,y,z) {}

int MyCond::Calc(const MyGraph& g)
{
    if(g[num1].NodePos->Val() > 0) val = g[num2].NodePos->Val();
    else val = g[num3].NodePos->Val();
    return 0;
}