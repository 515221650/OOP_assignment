//
// Created by WLY on 2019/5/22.
//

#ifndef OOP_TSCPT_H
#define OOP_TSCPT_H

#include "Tensor.h"

namespace mtrx
{
    Matrix sin(Matrix);
    Matrix exp(Matrix);
    Matrix log(Matrix);
    Matrix sigmoid(Matrix);
    Matrix tanh(Matrix);

    Tensor sin(Tensor);
    Tensor exp(Tensor);
    Tensor log(Tensor);
    Tensor sigmoid(Tensor);
    Tensor tanh(Tensor);

}

#endif //OOP_TSCPT_H
