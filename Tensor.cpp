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

Tensor Tensor::operator/ (const Tensor& b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]/b.val[i];
        /*if()
        {

        }*///error
    }
    return tmp;
}

Tensor Tensor::operator> (const Tensor& b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]>b.val[i];
    }
    return tmp;
}

Tensor Tensor::operator< (const Tensor& b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]<b.val[i];
    }
    return tmp;
}

Tensor Tensor::operator>= (const Tensor& b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]>=b.val[i];
    }
    return tmp;
}

Tensor Tensor::operator<= (const Tensor& b) const
{
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]<=b.val[i];
    }
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

void Tensor::reshape(std::initializer_list<int> szlist)//现在还不支持reshape(-1)
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
    if(fail)
    {
        std::terminate();
    }

    if(tmpsz.size() == 1)
    {
        tmpsz.push_back(tmpsz[0]);
        tmpsz[0] = 1;
    }


    size.swap(tmpsz);
    dim = size.size();
    std::vector<double> tmp;
    for(auto& i : val)
    {
        for(auto j : i.mval)
        {
            tmp.push_back(j);
        }
    }
    val.clear();


    int col = size.back(), row = size[size.size()-2] ;
    int new_size = Size()/(row*col);

    for(int i = 0; i < new_size; i++)
    {
        Matrix matrix(row, col, 0);
        for(int j = 0; j < row*col; j++)
        {
            matrix.change_mval(j, tmp[i*(row*col)+j]);
        }
        val.push_back(matrix);
    }
    //to be continued... have difficulties with vector<int> val

}

Tensor Tensor::trans() const
{
    Tensor res = *this;
    for(auto &a: res.val)
    {
        a = ts::trans(a);
    }
    return res;
}

Tensor Tensor::sin() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::sin(a);
    return res;
}

Tensor Tensor::exp() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::exp(a);
    return res;
}

Tensor Tensor::log() const
{
    Tensor res = *this;
    for(auto &a: res.val)
    {
        a = ts::log(a);
        if(Matrix::get_error()!=0)
        {
            Tensor::set_error(Matrix::get_error());
            return *this;
        }
    }
    return res;
}
Tensor Tensor::sigmoid() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::sigmoid(a);
    return res;
}
Tensor Tensor::tanh() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::tanh(a);
    return res;
}

Tensor Tensor::concat(const Tensor & b, const int catdim) const
{
    int dima = this->get_dim();
    int dimb = b.get_dim();
    if(dima!=dimb)
    {
        Tensor::set_error(5);//5...
        return *this;//return what?
    }
    for(int i=0; i<dima; i++)
    {
        if((this->get_size(i)!=b.get_size(i)) && i!=catdim)
        {
            Tensor::set_error(5);//5...
            return *this;//return what?
        }
    }

    std::vector<int> tmpsize;
    for(int i=0; i<dima; i++)
    {
        if(i!=catdim) tmpsize.push_back(this->get_size(i));
        else tmpsize.push_back(this->get_size(i)+b.get_size(i));
    }
    Tensor res(tmpsize);

    if(catdim < dima-2)
    {
        int abatch = 1, bbatch = 1;
        int times = 0;//交替复制进去 交替的次数
        for(int i=catdim+1; i<dima-2; i++)
        {
            abatch *= this->get_size(i);
            bbatch *= b.get_size(i);
        }
        for(int i=0; i<catdim; i++) times *= this->get_size(i);
        times *= this->get_size(catdim) + b.get_size(catdim);
        for(int k=0; k<times; k++)
        {
            for(int i=0; i<abatch; i++) res.change_val(k*(abatch+bbatch)+i, this->get_val(k*abatch+i));
            for(int i=0; i<bbatch; i++) res.change_val(k*(abatch+bbatch)+abatch+i, b.get_val(k*bbatch+i));
        }
    }
    else //需要用到Matrix的concat
    {
        int times = res.get_val().size();
        for(int i=0; i<times; i++) res.change_val(i, ts::concat(this->get_val(i), b.get_val(i), catdim-(dima-2)));
    }
    return res;
}

Tensor Tensor::point_mul(const Tensor& b) const
{
    Tensor res = *this;
    int len = this->val.size();
    for(int i = 0; i <len; i++) res.val[i] = ts::point_mul(res.val[i], b.val[i]);
    return res;
}

Tensor Tensor::abs() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::abs(a);
    return res;
}

void Tensor::randn()
{
    for(auto& i : val)
    {
        i.randn();
    }
}