//
// Created by hwy on 2019/5/24.
//
#include "ts.h"
#include "Node.h"
#include "Matrix.h"
#include "Tensor.h"
namespace ts
{
    Matrix trans(const Matrix & ob)
    {
        return ob.trans();
    }

    Matrix point_mul(const Matrix & A, const Matrix & B)
    {
        return A.point_mul(B);
    }

    Matrix sin(const Matrix & ob)
    {
        return ob.sin();
    }

    Matrix exp(const Matrix & ob)
    {
        return ob.exp();
    }

    Matrix log(const Matrix & ob)
    {
        return ob.log();
    }
    Matrix sigmoid(const Matrix & ob)
    {
        return ob.sigmoid();
    }
    Matrix tanh(const Matrix & ob)
    {
        return ob.tanh();
    }

    Matrix abs(const Matrix & ob)
    {
        return ob.abs();
    }

    Matrix concat(const Matrix & a, const Matrix & b, const int catdim)//catdim只能是0/1
    {
        return a.concat(b,catdim);
    }

    Tensor sin(const Tensor & ob)
    {
        return ob.sin();
    }

    Tensor exp(const Tensor & ob)
    {
        return ob.exp();
    }
    Tensor log(const Tensor & ob)
    {
        return ob.log();
    }
    Tensor sigmoid(const Tensor &ob)
    {
        return ob.sigmoid();
    }
    Tensor tanh(const Tensor &ob)
    {
        return ob.tanh();
    }

    Tensor abs(const Tensor &ob)
    {
        return ob.abs();
    }

    Tensor trans(const Tensor &ob)
    {
        return ob.trans();
    }
    Tensor point_mul(const Tensor & A, const Tensor & B)
    {
        return A.point_mul(B);
    }

    Tensor concat(const Tensor & a, const Tensor & b, const int catdim)//catdim:连接的那一维,从0开始
    {
        return a.concat(b,catdim);
    }
}