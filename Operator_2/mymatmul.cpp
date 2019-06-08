//
// Created by hwy on 2019/6/8.
//
#include "mymatmul.h"

MyMatMul::MyMatMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMatMul::Calc(MyGraph &v) { //默认的mul应该是哪个？？
    val = v[num1].NodePos->Val().mat_mul(v[num2].NodePos->Val());
    return 0;
}
int MyMatMul::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(der*ts::trans(v[num2].NodePos->Val()));
    v[num2].NodePos->add_der(der*ts::trans(v[num1].NodePos->Val()));
    return 0;
}