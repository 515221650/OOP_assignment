//
// Created by yzy on 2019/3/31.
//

#include "myexp.h"
MyExp::MyExp(std::string &s, int x) : Operator_1(s, x){}

int MyExp::Calc(Node **v) {
    val = expf(v[num]->Val());
    return 0;
}