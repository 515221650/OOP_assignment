//
// Created by yzy on 2019/5/18.
//

#include "Tensor.h"

double Tensor::operator() (std::initializer_list<int> arglist)
{
    int listsz = arglist.size();
    //if(listsz != dim) //错误判断

    int tmpnum = 1;
    int tmprank = 0;
    int tmpdim = dim-1;
    for(auto a = arglist.end()-1; tmpdim>1; a--, tmpdim--)
    {
        tmprank += arglist[tmpdim]*tmpnum;
        tmpnum *= size[tmpdim];
    }
    return val[tmprank].get_data(arglist[0], arglist[1]);
}

Tensor Tensor::operator+(const Tensor &b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i] += b.val[i];
    return tmp;
}

Tensor Tensor::operator-(const Tensor &b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i]-=b.val[i];
    return tmp;
}

Tensor Tensor::operator*(const Tensor &b) const
{
    // if() 维数不符合
    Tensor tmp;
    tmp.add_dim(size[0]);
    tmp.add_dim(b.size[1]);
    for(int i=2; i<=dim; i++) tmp.add_dim(size[i]);
    for(int i=0; i<val.size(); i++)  tmp.val.push_back(val[i]*b.val[i]);
    return tmp;
}

Tensor::Tensor(std::initializer_list<int> szlist)
{
    dim = 0;
    int valnum = 1;
    for(auto & a: szlist)
    {
        size.push_back(a);
        dim++;
        if(dim>2) valnum*=a;
    }
    if(dim == 1) size.push_back(1);
    val.resize(valnum, Matrix(size[0], size[1], 0));

}