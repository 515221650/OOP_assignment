//
// Created by yzy on 2019/5/26.
//

#include "mygrad.h"

MyGrad::MyGrad(std::string &s, int x): Operator_1(s, x){}

int MyGrad::Calc(MyGraph &v)
{
    DerVec.clear();
    v.erase_der();
    v[num].NodePos->rev_der(1);
    for(int i = num; i >= 0; i --)v[i].NodePos->Derivate(v);
    for(int i = 0; i <= num ; i++)DerVec.push_back(v[i].NodePos->Der());
    return 0;
}

int MyGrad::Derivate(MyGraph& v){
    return 1;
}