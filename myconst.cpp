//
// Created by yzy on 2019/3/31.
//

#include "myconst.h"

MyConst::MyConst(std::string &s, float x) : Node(s, x){}

int MyConst::Calc(MyGraph &v) { return 0;}