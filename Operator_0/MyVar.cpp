//
// Created by player1 on 2019/4/1.
//
#include "MyVar.h"

MyVar::MyVar(std::string &name):Operator_0(name) {}


int MyVar::Calc(MyGraph& g)
{
    Tensor tmp = g.GetVR(this->name);
    val = tmp;
    return 0;
}

