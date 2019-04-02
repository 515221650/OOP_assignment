//
// Created by HWY on 2019/3/30.
//
#include "MyComputation.h"

int MyComputation(std::string &StrAim, MyGraph& g)
{
    Node* aim = g[g.str_to_int(StrAim)].NodePos;
    int status = aim->Compt(g);
    return status;
}