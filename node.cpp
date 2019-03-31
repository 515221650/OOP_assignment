//
// Created by yzy on 2019/3/30.
//

#include "node.h"

Node::Node(string &s, float x = 0) : name(s), val(x){}
float Node::Val() {return val;}