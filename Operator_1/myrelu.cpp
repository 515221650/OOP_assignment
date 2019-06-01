//
// Created by hwy on 2019/6/1.
//

#include "myrelu.h"

MyReLU::MyReLU(std::string &s, int x): Operator_1(s, x){}

int MyReLU::Calc(MyGraph &v) {
    val = ts::max_T(v[num].NodePos->Val(), Tensor(0.0));
    return 0;
}

int MyReLU::Derivate(MyGraph& v){
    v[num].NodePos-> add_der((v[num].NodePos->Val() >= Tensor(0.0)) * der);
    return 0;
}
