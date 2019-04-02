//
// Created by HWY on 2019/3/30.
//
#include "MyComputation.h"

int MyComputation(std::string &StrAim, MyGraph& g)
{
    Node* aim = NodeInfo[StrToIntMap[StrAim]].NodePos;
    int status = aim->Compt(*this);
    return status;
}