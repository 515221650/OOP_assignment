//
// Created by yzy on 2019/3/30.
//

#include "myplus.h"
MyPlus::MyPlus(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyPlus::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() + v[num2].NodePos->Val();
    return 0;
}