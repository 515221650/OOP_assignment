//
// Created by hwy on 2019/6/21.
//

#include "myreshape.h"
#include "../Scalar.h"
#include <iostream>
#include <iomanip>

MyReshape::MyReshape(std::string &s, int x, std::initializer_list<int> bs, std::initializer_list<int> as):
    Operator_1(s, x), beforesize(bs), aftersize(as) {}

int MyReshape::Calc(MyGraph &v) {
    val = v[num].NodePos->Val();
    val.reshape(aftersize);
    return 0;
}
int MyReshape::Derivate(MyGraph& v){
    auto resder = der;
    resder.reshape(beforesize);
    v[num].NodePos-> add_der(resder);
    return 0;
}