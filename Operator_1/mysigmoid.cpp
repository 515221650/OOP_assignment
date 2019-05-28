//
// Created by player0 on 2019/3/31.
//

#include "mysigmoid.h"
MySigmoid::MySigmoid(std::string &s, int x): Operator_1(s, x){}

int MySigmoid::Calc(MyGraph &v) {
    val = ts::sigmoid(v[num].NodePos->Val());
    return 0;
}

int MySigmoid::Derivate(MyGraph& v){
    v[num].NodePos-> add_der((1.0/(1.0+ts::exp(-v[num].NodePos->Val()))/(1.0+ts::exp(v[num].NodePos->Val()))) * der);
    return 0;
}
