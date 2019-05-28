//
// Created by yzy on 2019/5/18.
//

#include "myassert.h"
#include "../Scalar.h"


MyAssert::MyAssert(std::string &s, int x) : Operator_1(s, x){}

int MyAssert::Calc(MyGraph &v) {
    if(Scalar(v[num].NodePos->Val()).get_val() < -EPS) return 4;
    val = 0;
    return 0;
}

int MyAssert::Derivate(MyGraph &v) {
    return 1;
}
