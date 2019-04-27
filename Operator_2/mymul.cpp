//
// Created by yzy on 2019/3/31.
//

#include "mymul.h"

MyMul::MyMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMul::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() * v[num2].NodePos->Val();
    return 0;
}
int MyMul::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(v[num2].NodePos->Der()*der);
    v[num2].NodePos->add_der(v[num1].NodePos->Der()*der);
    return 0;
}