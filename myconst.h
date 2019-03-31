//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYCONST_H
#define OOP_MYCONST_H

#include "node.h"
class MyConst : public Node{
public:
    MyConst(std::string &s, float x);
    virtual int Calc(Node **v);
};


#endif //OOP_MYCONST_H
