//
// Created by WLY on 2019/4/1.
//
#include "MyPlaceholder.h"

MyPlaceholder::MyPlaceholder(std::string &name, int RevRank):Operator_0(name), RevRank(RevRank) {}

int MyPlaceholder::Calc(const MyGraph& g)
{
    auto tmp = g.GetPH(this->name);
    if(!tmp.first) return 3;
    val = tmp.second;
    return 0;
}