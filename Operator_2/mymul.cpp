//
// Created by player0 on 2019/3/31.
//

#include "mymul.h"

MyMul::MyMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMul::Calc(MyGraph &v) { //默认的mul应该是哪个？？
    val = v[num1].NodePos->Val() * v[num2].NodePos->Val();
    return 0;
}
int MyMul::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(der*ts::trans(v[num2].NodePos->Val()));
    v[num2].NodePos->add_der(der*ts::trans(v[num1].NodePos->Val()));
    return 0;
}