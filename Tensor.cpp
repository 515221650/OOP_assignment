//
// Created by yzy on 2019/5/18.
//

#include "Tensor.h"
#include <stdexcept>

bool Tensor::check_shape(const Tensor & obj2) const
{
    bool flag = 0;
    if(get_dim() != obj2.get_dim())flag = 1;
    for(int i = 0; i < dim; i++)
    {
        if(size[i] != obj2.size[i])flag = 1;
    }
    if(flag)
    {
        throw std::range_error("Tensor's shape doesn't match");
    }
}


std::ostream& operator << (std::ostream& out,const Tensor &x)
{
    if(x.dim==2)out<<x.val[0];
    else
    {
        for(int i = 0; i < x.size.size()-2; i++)out<<'[';
        for(int i = 1; i <= x.val.size(); i++)
        {
            out<<x.val[i-1];
            int tmp = 1;int flag = 0;
            for(int j = x.size.size()-3; j >= 0 ; j--)
            {
                tmp *= x.size[j];
                if(i%tmp == 0)out<<']',flag ++;
            }
            if(i!=x.val.size())
            {
                out<<',';
                for(int j = 0;j < flag; j++)out<<'[';
            }
        }
    }
    return out;
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

void Tensor::slice_helper(std::vector<int>& startp, std::vector<int>& endp, int now, int pos, Tensor& res)
{
    if(now == startp.size()-2)
    {
        res.val.push_back(this->get_val(pos)(std::make_pair(startp[now], endp[now]), std::make_pair(startp[now+1], endp[now+1])));
        return;
    }
    for(int i=startp[now]; i<endp[now]; i++)
    {
        slice_helper(startp, endp, now+1, pos*size[now+1]+i, res);
    }
}

Tensor Tensor::operator() (std::initializer_list<std::pair<int,int> > arglist)
{
    std::vector<int> startp;
    std::vector<int> endp;
    std::vector<int> deltap;

    int tmp = 0;
    for(auto a: arglist)
    {
        if(a.first>=a.second || a.first<0 || a.second > size[tmp]) throw(std::range_error("invalid slice"));
        startp.push_back(a.first);
        endp.push_back(a.second);
        deltap.push_back(a.second-a.first);
        tmp++;
    }

    Tensor res(deltap);
    res.val.clear();
    slice_helper(startp, endp, 0, 0, res);
    return res;
}

Tensor Tensor::operator+(const Tensor &b) const
{
    check_shape(b);
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)tmp.val[i] += b.val[i];
    return tmp;
}

Tensor Tensor::operator-(const Tensor &b) const
{
    check_shape(b);
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
    check_shape(b);
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i]=tmp.val[i]/b.val[i];
    }
    return tmp;
}

Tensor Tensor::operator> (const Tensor& b) const
{
    check_shape(b);
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
    check_shape(b);
    Tensor tmp = (*this);
    int len = val.size();
    for(int i=0;i<len;i++)
    {
        tmp.val[i] = tmp.val[i] < b.val[i];
    }
    return tmp;
}

Tensor Tensor::operator>= (const Tensor& b) const
{
    check_shape(b);
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
    check_shape(b);
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
    check_shape(b);
    Tensor tmp;tmp.clear();

    for(int i=0; i<=dim-3; i++) tmp.add_dim(size[i]);
    tmp.add_dim(size[dim-2]);
    tmp.add_dim(b.size[dim-1]);
    for(int i=0; i<val.size(); i++)  tmp.val.push_back(val[i]*b.val[i]);
    return tmp;
}

Tensor & Tensor::operator +=(const Tensor& obj2)
{
    *this = *this + obj2;
    return *this;
}

Tensor & Tensor::operator -=(const Tensor& obj2)
{
    *this = *this - obj2;
    return *this;
}

Tensor & Tensor::operator *=(const Tensor& obj2)
{
    *this = *this * obj2;
    return *this;
}

Tensor::Tensor(std::initializer_list<int> szlist, double mval)
{
    dim = 0;
    int valnum = 1;
    for(auto & a: szlist)
    {
        size.push_back(a);
        dim++;
        valnum*=a;
    }
    if(dim == 1)
    {
        size.push_back(size[0]);
        size[0] = 1;
        dim++;
    }
    val.resize(valnum/(size[dim-1]*size[dim-2]), Matrix(size[dim-2], size[dim-1], mval));
}

Tensor::Tensor(vector<double>& vallist)
{
    int sz = vallist.size();
    dim = 2;
    size = {1, sz};
    Matrix tmp(1, sz);
    for(int i = 0; i < sz; i ++)
    {
        tmp.change_mval(i, vallist[i]);
    }
    val = {tmp};
}

Tensor::Tensor(vector<int> szlist, double mval)
{
    dim = 0;
    for(auto & a: szlist)
    {
        size.push_back(a);
        dim++;
    }
    if(dim == 1)
    {
        size.push_back(1);
        dim++;
    }
    int valnum = 1;
    for(int i=0; i<size.size()-2; i++) valnum *= size[i];
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

    if((specialdim == -1) && (mul != Size())) fail = 1;
    if(specialdim!=-1)
    {
        if(Size()%mul != 0) fail = 1;
        else tmpsz[specialdim] = Size()/mul;

    }
    if(fail)
    {
        throw std::range_error("Tensor's shape doesn't match while reshaping");
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

    int col = size.back(), row = size[size.size()-2];
    int new_size = tmp.size()/(row*col);
    val.clear();

    for(int i = 0; i < new_size; i++)
    {
        Matrix matrix(row, col, 0);
        for(int j = 0; j < row*col; j++)
        {
            matrix.change_mval(j, tmp[i*(row*col)+j]);
        }
        val.push_back(matrix);
    }

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

Tensor Tensor::cos() const
{
    Tensor res = *this;
    for(auto &a: res.val) a = ts::cos(a);
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
        throw std::range_error("Tensor's shape doesn't match while concating");
    }
    for(int i=0; i<dima; i++)
    {
        if((this->get_size(i)!=b.get_size(i)) && i!=catdim)
        {
            throw std::range_error("Tensor's shape doesn't match while concating");
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
        int times = 1;//交替复制进去 交替的次数
        for(int i=catdim; i<dima-2; i++)
        {
            abatch *= this->get_size(i);
            bbatch *= b.get_size(i);
        }
        for(int i=0; i<catdim; i++) times *= this->get_size(i);
        for(int k=0; k<times; k++)
        {
            for(int i=0; i<abatch; i++) res.change_val(k*(abatch+bbatch)+i, this->get_val(k*abatch+i));
            for(int i=0; i<bbatch; i++) res.change_val(k*(abatch+bbatch)+abatch+i, b.get_val(k*bbatch+i));
        }
    }
    else //需要用到Matrix的concat
    {
        int times = res.get_val().size();
        for(int i=0; i<times; i++)
        {
            res.change_val(i, ts::concat(this->get_val(i), b.get_val(i), catdim-(dima-2)));
        }
    }
    return res;
}

Tensor Tensor::point_mul(const Tensor& b) const
{
    check_shape(b);
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