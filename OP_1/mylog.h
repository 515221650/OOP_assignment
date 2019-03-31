//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYLOG_H
#define OOP_MYLOG_H

#include "operator_1.h"
class MyLog : public Operator_1{
public:
    MyLog(std::string &s, int x);
    virtual int Calc(Node **v);
};


#endif //OOP_MYLOG_H
