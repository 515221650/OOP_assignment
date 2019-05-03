//
// Created by yzy on 2019/4/1.
//

#include "myprint.h"
#include <iostream>
#include <iomanip>
MyPrint::MyPrint(std::string &s, int x): Operator_1(s, x){}

int MyPrint::Calc(MyGraph &v) {
    std::cout<<"Print Operator: "<<v[num].NodePos->Name()<<"="<<std::fixed<<std::setprecision(4)<<v[num].NodePos->Val()<<std::endl;
    val = v[num].NodePos->Val();
    return 0;
}
int MyPrint::Derivate(MyGraph& v){
    v[num].NodePos-> add_der(der);
    return 0;
}