//
// Created by yzy on 2019/3/31.
//

#include "mytanh.h"
MyTanh::MyTanh(std::string &s, int x): Operator_1(s, x){}

int MyTanh::Calc(Node **v) {
    val = tanhf(v[num]->Val());
    return 0;
}
