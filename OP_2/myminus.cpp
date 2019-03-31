//
// Created by yzy on 2019/3/31.
//

#include "myminus.h"
MyMinus::MyMinus(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyMinus::Calc(Node **v) {
    val = v[num1]->Val() - v[num2]->Val();
    return 0;
}