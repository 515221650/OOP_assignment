//
// Created by hwy on 2019/4/1.
//
#include "MyPlaceholder.h"
#include <iostream>
MyPlaceholder::MyPlaceholder(std::string &name):Operator_0(name) {}


int MyPlaceholder::Calc(MyGraph& g)
{
    auto tmp = g.GetPH(this->name);
    if(!tmp.first) return 3;
    val = tmp.second;
    return 0;
}