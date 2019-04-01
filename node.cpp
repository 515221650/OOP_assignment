//
// Created by yzy on 2019/3/30.
//

#include "node.h"

Node::Node(std::string &s, float x) : name(s), val(x){}
float Node::Val() {return val;}
std::string Node::Name(){return name;}