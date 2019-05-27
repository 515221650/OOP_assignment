//
// Created by yzy on 2019/5/26.
//

#include "myat.h"
#include "../Operator_1/mygrad.h"

MyAt::MyAt(std::string &s, int x, int y): Operator_2(s, x, y){}

int MyAt::Calc(MyGraph &v) {
    auto it = dynamic_cast<MyGrad*>(v[num1].NodePos);
    val = it->GetDer(num2);
    return 0;
}

int MyAt::Derivate(MyGraph &v) {
    return 1;
}