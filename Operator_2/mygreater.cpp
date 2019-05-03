//
// Created by yzy on 2019/4/1.
//

#include "mygreater.h"
MyGreater::MyGreater(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyGreater::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() - v[num2].NodePos->Val() > EPS ? 1.0 : 0.0;
    return 0;
}
int MyGreater::Derivate(MyGraph &v) {
    return 1;
}