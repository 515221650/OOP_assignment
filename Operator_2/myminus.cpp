//
// Created by yzy on 2019/3/31.
//

#include "myminus.h"
MyMinus::MyMinus(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyMinus::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() - v[num2].NodePos->Val();
    return 0;
}

void MyMinus::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(der);
    v[num2].NodePos->add_der(-der);
    return ;
}