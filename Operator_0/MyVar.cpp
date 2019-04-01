//
// Created by hwy on 2019/4/1.
//
#include "MyVar.h"

MyVar::MyVar(std::string &name, float x):Operator_0(name, x) {}


int MyVar::Calc(const MyGraph& g)
{
    return 0;
}

void MyVar::rev_val(float x)
{
    val = x;
}

