//
// Created by yzy on 2019/5/26.
//

#ifndef OOP_MYGRAD_H
#define OOP_MYGRAD_H

#include "operator_1.h"
class MyGrad: public Operator_1{
private:
    std::vector<Tensor> DerVec;
public:
    MyGrad(std::string &s, int x);
    Tensor GetDer(int x){return DerVec[x];}
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &g);

    virtual ~MyGrad();
};


#endif //OOP_MYGRAD_H
