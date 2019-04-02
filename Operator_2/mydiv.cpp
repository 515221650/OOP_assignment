//
// Created by yzy on 2019/3/31.
//

#include "mydiv.h"
#include <cmath>
MyDiv::MyDiv(std::string &s, int x, int y) : Operator_2(s, x, y){}

int MyDiv::Calc(MyGraph &v) {
    if(fabsf(v[num2].NodePos->Val()) < EPS)return 1;
    val = v[num1].NodePos->Val() * v[num2].NodePos->Val();
    return 0;
}
