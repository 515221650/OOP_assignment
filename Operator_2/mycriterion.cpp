//
// Created by hwy on 2019/6/1.
//
#include "mycriterion.h"
#include "../Scalar.h"

MyMSELoss::MyMSELoss(std::string &s, int x, int y) : Operator_2(s, x, y){}

int MyMSELoss::Calc(MyGraph &v) {
    Tensor delta = v[num1].NodePos->Val() - v[num2].NodePos->Val();
    val = ts::point_mul(delta, delta);
    return 0;
}

int MyMSELoss::Derivate(MyGraph& v)
{
    v[num1].NodePos->add_der(Scalar(2.0)*(v[num1].NodePos->Val() - v[num2].NodePos->Val()));
    v[num2].NodePos->add_der(Scalar(2.0)*(v[num2].NodePos->Val() - v[num1].NodePos->Val()));
    return 0;
}

