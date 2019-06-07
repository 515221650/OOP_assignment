//
// Created by player0 on 2019/4/1.
//

#include "myprint.h"
#include "../Scalar.h"
#include <iostream>
#include <iomanip>
MyPrint::MyPrint(std::string &s, int x): Operator_1(s, x){}

int MyPrint::Calc(MyGraph &v) {
    std::cout<<"PRINT operator: "<<v[num].NodePos->Name()<<" = "<<std::fixed<<std::setprecision(4)<<Scalar(v[num].NodePos->Val()).get_val()<<std::endl;
    val = v[num].NodePos->Val();
    return 0;
}
int MyPrint::Derivate(MyGraph& v){
    v[num].NodePos-> add_der(der);
    return 0;
}