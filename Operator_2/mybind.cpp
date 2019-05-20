//
// Created by yzy on 2019/5/18.
//

#include "mybind.h"
MyBind::MyBind(std::string &s, int x, int y) : Operator_2(s, x, y){}

int MyBind::Calc(MyGraph &v)
{
    val = v[num1].NodePos->Val();
    return 0;
}

int MyBind::Derivate(MyGraph &v)
{
    v[num1].NodePos-> add_der(der);
    return 0;
}
