//
// Created by player0 on 2019/3/31.
//

#include "mytanh.h"
#include "../Scalar.h"

MyTanh::MyTanh(std::string &s, int x): Operator_1(s, x){}

int MyTanh::Calc(MyGraph &v) {
    val = ts::tanh(v[num].NodePos->Val());
    return 0;
}

int MyTanh::Derivate(MyGraph& v){
    v[num].NodePos-> add_der(4.0/(::ts::exp(-(Scalar(2)*v[num].NodePos->Val()))+::ts::exp(Scalar(2)*v[num].NodePos->Val())+2)*der);
    return 0;
}