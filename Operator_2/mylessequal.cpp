//
// Created by player0 on 2019/4/1.
//

#include "mylessequal.h"
MyLessEqual::MyLessEqual(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyLessEqual::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() <= v[num2].NodePos->Val();
    return 0;
}
int MyLessEqual::Derivate(MyGraph &v) {
    return 1;
}