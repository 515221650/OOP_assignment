//
// Created by WLY on 2019/4/1.
//
#include "MyPlaceholder.h"

MyPlaceholder::MyPlaceholder(std::string &name, int RevRank):Operator_0(name), RevRank(RevRank) {}

int MyPlaceholder::Calc(const MyGraph& g)
{
    if(!g.ph_if_rev(g.str_to_int(this->name))) return 3;
    return 0;
}

void MyPlaceholder::rev_val(float x) {val = x;}