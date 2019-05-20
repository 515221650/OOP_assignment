//
// Created by player0 on 2019/3/30.
//

#include "myplus.h"
MyPlus::MyPlus(std::string &s, int x = 0, int y = 0) :Operator_2(s, x, y){}

int MyPlus::Calc(MyGraph &v) {
    val = v[num1].NodePos->Val() + v[num2].NodePos->Val();
    return 0;
}
int MyPlus::Derivate(MyGraph &v) {
    v[num1].NodePos->add_der(der);
    v[num2].NodePos->add_der(der);
    return 0;
}