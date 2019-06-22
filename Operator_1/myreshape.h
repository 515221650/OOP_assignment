//
// Created by hwy on 2019/6/21.
//

#ifndef OOP_MYRESHAPE_H
#define OOP_MYRESHAPE_H

#include "operator_1.h"
class MyReshape : public Operator_1{
private:
    std::initializer_list<int> beforesize;
    std::initializer_list<int> aftersize;
public:
    MyReshape(std::string &s, int x, std::initializer_list<int> bs, std::initializer_list<int> as);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph& g);

    virtual ~MyReshape(){}
};

#endif //OOP_MYRESHAPE_H
