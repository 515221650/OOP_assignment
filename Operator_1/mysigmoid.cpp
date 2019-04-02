//
// Created by yzy on 2019/3/31.
//

#include "mysigmoid.h"
MySigmoid::MySigmoid(std::string &s, int x): Operator_1(s, x){}

int MySigmoid::Calc(MyGraph &v) {
    val = 1.0/(1+expf(-v[num].NodePos->Val()));
    return 0;
}
