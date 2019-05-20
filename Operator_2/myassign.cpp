//
// Created by yzy on 2019/5/18.
//

#include "myassign.h"
MyAssign::MyAssign(std::string &s, int x, int y) : Operator_2(s, x, y){}

int MyAssign::Calc(MyGraph &v)
{
    val = v[num2].NodePos->Val();
    v.push_assign(num1, val);
    return 0;
}

int MyAssign::Derivate(MyGraph &v)
{
    v[num2].NodePos-> add_der(der);
    return 0;
}
