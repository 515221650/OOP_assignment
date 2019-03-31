//
// Created by yzy on 2019/3/31.
//

#include "mysigmoid.h"
mysigmoid::mysigmoid(std::string &s, int x): Operator_1(s, x){}

int mysigmoid::Calc(Node **v) {
    val = 1.0/(1+expf(-v[num]->Val()));
    return 0;
}
