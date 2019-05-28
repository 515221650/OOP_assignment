//
// Created by hwy on 2019/5/28.
//
#include "Scalar.h"


Tensor Scalar::operator *(const Tensor & b) const
{
    Tensor res = b;
    for(auto tmp: res.val) tmp = *this*tmp;
    return res;
}

Matrix Scalar::operator *(const Matrix & b) const
{
    Matrix res = b;
    for(auto tmp: res.mval) tmp *= this->val;
    return res;
}