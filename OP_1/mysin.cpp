//
// Created by yzy on 2019/3/31.
//

#include "mysin.h"

MySin::MySin(std::string &s, int x): Operator_1(s, x){}

int MySin::Calc(Node **v) {
    val = sinf(v[num]->Val());
    return 0;
}
