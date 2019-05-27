//
// Created by player0 on 2019/3/31.
//

#include "mysin.h"

MySin::MySin(std::string &s, int x): Operator_1(s, x){}

int MySin::Calc(MyGraph &v) {
    val = ts::sin(v[num].NodePos->Val());
    return 0;
}

int MySin::Derivate(MyGraph& v){
    v[num].NodePos-> add_der(cos(v[num].NodePos->Val())*der);
    return 0;
}