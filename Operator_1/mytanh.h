//
// Created by yzy on 2019/3/31.
//

#ifndef OOP_MYTANH_H
#define OOP_MYTANH_H

#include "operator_1.h"
class MyTanh : public Operator_1 {
public:
    MyTanh(std::string &s, int x);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);
};


#endif //OOP_MYTANH_H
