//
// Created by yzy on 2019/3/31.
//

#include "mylog.h"

MyLog::MyLog(std::string &s, int x): Operator_1(s, x){}

int MyLog::Calc(MyGraph &v) {
    if(v[num].NodePos->Val() <= EPS)return 2;
    val = logf(v[num].NodePos->Val());
    return 0;
}