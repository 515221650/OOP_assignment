//
// Created by player0 on 2019/3/31.
//

#include "mymul.h"

MyMul::MyMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMul::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() * v[num2].NodePos->Val();
    return 0;
}
int MyMul::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(v[num2].NodePos->Val()*der);
    v[num2].NodePos->add_der(v[num1].NodePos->Val()*der);
    return 0;
}