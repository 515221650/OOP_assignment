//
// Created by player1 on 2019/4/1.
//
#include "MyVar.h"

MyVar::MyVar(std::string &name, int _index):Operator_0(name),index(_index) {}


int MyVar::Calc(MyGraph& g)
{
    Tensor tmp = g.GetVR(index);
    val = tmp;
    return 0;
}

