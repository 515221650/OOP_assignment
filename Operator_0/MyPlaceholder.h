//
// Created by hwy on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYPLACEHOLDER_H
#define BIGHOMEWORK_MYPLACEHOLDER_H

#include "Operator_0.h"

class MyPlaceholder:public Operator_0{
private:
    int RevRank;
public:
    MyPlaceholder(std::string& name, int RevRank);
    virtual int Calc(const MyGraph& a);
    virtual int Rank(){return RevRank;}
};


#endif //BIGHOMEWORK_MYPLACEHOLDER_H
