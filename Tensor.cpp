//
// Created by yzy on 2019/5/18.
//

#include "Tensor.h"

Tensor Tensor::operator()(int a, ...)
{
    va_list args;
    //声明变量 ap,用于指向参数
    va_start(args, a);
    for(int i=1;i<=dim;i++)
    {

    }

}

Tensor Tensor::operator+(Tensor &b)
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i]+=b.val[i];
    return tmp;
}

Tensor Tensor::operator-(Tensor &b)
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i]-=b.val[i];
    return tmp;
}

Tensor Tensor::operator*(Tensor &b)
{
    // if() 维数不符合

    for(int i=0;i<=n;i++)
    {

    }
}
