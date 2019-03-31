//
// Created by yzy on 2019/3/31.
//

#include "mydiv.h"
#include <cmath>
MyDiv::MyDiv(std::string &s, int x, int y) : Operator_2(s, x, y){}

int MyDiv::Calc(Node **v) {
    if(fabsf(v[num2]->Val())<1E-8)return 1;
    val = v[num1]->Val() * v[num2]->Val();
    return 0;
}
