//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYPLACEHOLDER_H
#define BIGHOMEWORK_MYPLACEHOLDER_H

#include "Operator_0.h"

class MyPlaceholder : public Operator_0{
public:
    MyPlaceholder(std::string& name);
    virtual int Calc(MyGraph& v);

    virtual ~MyPlaceholder(){}
};


#endif //BIGHOMEWORK_MYPLACEHOLDER_H
