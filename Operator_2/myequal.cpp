//
// Created by player0 on 2019/4/1.
//

#include "myequal.h"
#include "../Scalar.h"

MyEqual::MyEqual(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyEqual::Calc(MyGraph &v) {
    val = ts::abs(v[num1].NodePos->Val() - v[num2].NodePos->Val()) < Tensor(2*EPS);//NEED BROADCAST!


    return 0;
}

int MyEqual::Derivate(MyGraph &v) {
    return 1;
}