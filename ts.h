//
// Created by hwy on 2019/5/22.
//

#ifndef OOP_TS_H
#define OOP_TS_H

class Tensor;
class Matrix;

namespace ts
{
    Matrix sin(const Matrix &);
    Matrix exp(const Matrix &);
    Matrix log(const Matrix &);
    Matrix sigmoid(const Matrix &);
    Matrix tanh(const Matrix &);

    Matrix concat(const Matrix & a, const Matrix & b, const int catdim);

    Tensor sin(const Tensor &);
    Tensor exp(const Tensor &);
    Tensor log(const Tensor &);
    Tensor sigmoid(const Tensor &);
    Tensor tanh(const Tensor &);

    Tensor concat(const Tensor & a, const Tensor & b, const int catdim);

}

#endif //OOP_TS_H
