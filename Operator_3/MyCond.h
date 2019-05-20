//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYCOND_H
#define BIGHOMEWORK_MYCOND_H
#include "Operator_3.h"

class MyCond: public Operator_3{
public:
    virtual int Calc(MyGraph& g);
    virtual int Derivate(MyGraph& g);

    MyCond(std::string& s, int x, int y, int z);
    virtual  ~MyCond(){};
};

#endif //BIGHOMEWORK_MYCOND_H
