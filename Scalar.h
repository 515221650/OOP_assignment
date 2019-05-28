//
// Created by hwy on 2019/5/28.
//

#ifndef OOP_SCALAR_H
#define OOP_SCALAR_H

#include "Tensor.h"

class Scalar
{
private:
    double val;
public:
    explicit Scalar(double val):val(val){}
    explicit Scalar(const Tensor& a): val(a.get_val(1).get_mval(1)){}
    Tensor operator *(const Tensor & b) const;
    Matrix operator *(const Matrix & b) const;
    double get_val() const {return val;}
};

#endif //OOP_SCALAR_H
