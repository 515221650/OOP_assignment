//
// Created by hwy on 2019/6/1.
//

#include "myrelu.h"

MyReLU::MyReLU(std::string &s, int x): Operator_1(s, x){}

int MyReLU::Calc(MyGraph &v) {
    //std::cout<<"num"<<num<<std::endl;
    //std::cout<<"v[num].NodePos->Val()"<<v[num].NodePos->Val()<<std::endl;
    val = ts::max_T(v[num].NodePos->Val(), Tensor(0.0));
    //std::cout<<"out!!"<<std::endl;
    return 0;
}

int MyReLU::Derivate(MyGraph& v){
    v[num].NodePos-> add_der((v[num].NodePos->Val() >= Tensor(0.0)) * der);
    return 0;
}
