//
// Created by HWY on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYCOND_H
#define BIGHOMEWORK_MYCOND_H
#include "Operator_3.h"

class MyCond: public Operator_3{
private:
    virtual int Calc(const MyGraph& g);
public:
    MyCond(std::string& s, int x, int y, int z);
};

#endif //BIGHOMEWORK_MYCOND_H
