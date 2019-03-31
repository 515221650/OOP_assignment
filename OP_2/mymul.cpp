//
// Created by yzy on 2019/3/31.
//

#include "mymul.h"

MyMul::MyMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMul::Calc(Node **v) {
    val = v[num1]->Val() * v[num2]->Val();
    return 0;
}
