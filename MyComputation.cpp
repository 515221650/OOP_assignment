//
// Created by HWY on 2019/3/30.
//
#include "MyComputation.h"

int MyComputation(std::string &StrAim, MyGraph& g)
{
    Node* aim = g[g.str_to_int(StrAim)].NodePos;
    int status = aim->Compt(g);
    if(status == 0) std::cout << aim->Val() << std::endl;
    if(status == 1) std::cout << "Division by zero" << std::endl;
    if(status == 2) std::cout << "LOG operators input must be positive" << std::endl;
    if(status == 3) std::cout << "Placeholder missing" << std::endl;
    return status;
}