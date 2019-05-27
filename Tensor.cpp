//
// Created by yzy on 2019/5/18.
//

#include "Tensor.h"

std::ostream& operator << (std::ostream& out, Tensor &x)
{
    for(auto i: x.val)
    {

    }
}

double Tensor::operator() (std::initializer_list<int> arglist)
{
    int listsz = arglist.size();
    //if(listsz != dim) //错误判断

    int tmpnum = 1;
    int tmprank = 0;//for循环后为矩阵在val中的下标
    int tmpdim = dim-1;
    for(auto a = arglist.end()-3; tmpdim>=0; a--, tmpdim--)
    {
        tmprank += (*a)*tmpnum;
        tmpnum *= size[tmpdim];
    }
    return val[tmprank].get_mval(*(arglist.end()-2), *(arglist.end()-1));
}

Tensor Tensor::operator() (std::initializer_list<std::pair<int,int> > arglist)
{

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

Tensor Tensor::operator-() const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i]=-tmp.val[i];
    return tmp;
}

Tensor Tensor::operator*(const Tensor &b) const
{
    // if() 维数不符合
    Tensor tmp;
    for(int i=0; i<=dim-3; i++) tmp.add_dim(size[i]);
    tmp.add_dim(size[dim-2]);
    tmp.add_dim(b.size[dim-1]);
    for(int i=0; i<val.size(); i++)  tmp.val.push_back(val[i]*b.val[i]);
    return tmp;
}

Tensor::Tensor(std::initializer_list<int> szlist, int mval)
{
    dim = 0;
    int valnum = 1;
    for(auto & a: szlist)
    {
        size.push_back(a);
        dim++;
        if(dim>2) valnum*=a;
    }
    if(dim == 1)
    {
        size.push_back(1);
        dim++;
    }
    val.resize(valnum, Matrix(size[dim-2], size[dim-1], mval));
}

Tensor::Tensor(vector<int> szlist, int mval)
{
    dim = 0;
    int valnum = 1;
    for(auto & a: szlist)
    {
        size.push_back(a);
        dim++;
        if(dim>2) valnum*=a;
    }
    if(dim == 1)
    {
        size.push_back(1);
        dim++;
    }
    val.resize(valnum, Matrix(size[dim-2], size[dim-1], mval));
}//这个和上面一个可以用模板合并吗?

Tensor& Tensor::reshape(std::initializer_list<int> szlist)//现在还不支持reshape(-1)
{
    vector<int> tmpsz;//把szlist转成vector，方便处理
    int specialdim = -1;//赋成-1的那一维
    int k = 0;
    int mul = 1;
    for(auto a: szlist)
    {
        tmpsz.push_back(a);
        if(a==-1) specialdim = k;
        else mul *= a; //除了赋成-1那一维，其余所有维的size的乘积
        k++;
    }
    bool fail = 0;
    if((specialdim == -1) && (mul != val.size())) fail = 1;
    if((specialdim!=-1))
    {
        if(val.size()%mul != 0) fail = 1;
        else tmpsz[specialdim] = val.size()/mul;
    }
    size.swap(tmpsz);

    //to be continued... have difficulties with vector<int> val

    return (*this);
}