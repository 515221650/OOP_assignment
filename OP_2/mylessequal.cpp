//
// Created by yzy on 2019/4/1.
//

#include "mylessequal.h"
MyLessEqual::MyLessEqual(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyLessEqual::Calc(MyGraph &v) {
    val = v[num2].NodePos->Val() - v[num1].NodePos->Val() > EPS ? 1.0 : 0.0;
    return 0;
}