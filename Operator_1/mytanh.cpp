//
// Created by yzy on 2019/3/31.
//

#include "mytanh.h"
MyTanh::MyTanh(std::string &s, int x): Operator_1(s, x){}

int MyTanh::Calc(MyGraph &v) {
    val = tanhf(v[num].NodePos->Val());
    return 0;
}

void MyTanh::Derivate(MyGraph& v){
    v[num].NodePos-> add_der((4.0/(expf(-2*v[num].NodePos->Val())+expf(2*v[num].NodePos->Val())+2)+der);
}