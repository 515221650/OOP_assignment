//
// Created by yzy on 2019/3/31.
//

#include "mylog.h"

MyLog::MyLog(std::string &s, int x): Operator_1(s, x){}

int MyLog::Calc(Node **v) {
    if(v[num]->Val()<=1E-8)return 2;
    val = logf(v[num]->Val());
    return 0;
}