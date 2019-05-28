//
// Created by player0 on 2019/4/1.
//

#include "mygreater.h"
MyGreater::MyGreater(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyGreater::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() > v[num2].NodePos->Val();
    return 0;
}
int MyGreater::Derivate(MyGraph &v) {
    return 1;
}