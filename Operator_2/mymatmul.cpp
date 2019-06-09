//
// Created by hwy on 2019/6/8.
//
#include "mymatmul.h"

MyMatMul::MyMatMul(std::string &s, int x, int y) : Operator_2(s, x, y) {}

int MyMatMul::Calc(MyGraph &v) { //默认的mul应该是哪个？？
    val = v[num1].NodePos->Val().mat_mul(v[num2].NodePos->Val());
    return 0;
}
int MyMatMul::Derivate(MyGraph &v) {
//    std::cout<<v[num1].NodePos->Val().size[0]<<' '<<v[num1].NodePos->Val().size[1]<<std::endl;
//    std::cout<<v[num2].NodePos->Val().size[0]<<' '<<v[num2].NodePos->Val().size[1]<<std::endl;
//    std::cout<<der.size[0]<<' '<<der.size[1]<<std::endl;

    //    std::cout<<v[num1].NodePos->Val().get_size(0)<<' '<<std::cout<<v[num1].NodePos->Val().get_size(1)<<std::endl;
    //    std::cout<<v[num2].NodePos->Val().get_size(0)<<' '<<std::cout<<v[num2].NodePos->Val().get_size(1)<<std::endl;
    //    std::cout<<der.get_size(0)<<' '<<std::cout<<der.get_size(1)<<std::endl;
//    while(1);
    v[num1].NodePos->add_der(der.mat_mul(ts::trans(v[num2].NodePos->Val())));
    v[num2].NodePos->add_der(ts::trans(v[num1].NodePos->Val()).mat_mul(der));
    return 0;

}