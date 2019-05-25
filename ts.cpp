//
// Created by hwy on 2019/5/24.
//
#include "ts.h"
#include "Node.h"
#include "Matrix.h"

namespace ts
{
    Matrix sin(const Matrix & ob)
    {
        Matrix res = ob;
        for(auto a: res.mval) a = sinf(a);
        return res;
    }

    Matrix exp(const Matrix & ob)
    {
        Matrix res = ob;
        for(auto a: res.mval) a = expf(a);
        return res;
    }
    Matrix log(const Matrix & ob)
    {
        Matrix res = ob;
        for(auto a: res.mval)
        {
            if(a <= EPS)
            {
                Matrix::set_error(2);
                return ob;
            }
            a = logf(a);
        }
        return res;
    }
    Matrix sigmoid(const Matrix & ob)
    {
        Matrix res = ob;
        for(auto a: res.mval) a = 1.0/(1+expf(a));
        return res;
    }
    Matrix tanh(const Matrix & ob)
    {
        Matrix res = ob;
        for(auto a: res.mval) a = tanhf(a);
        return res;
    }

    Tensor sin(const Tensor & ob)
    {
        Tensor res = ob;
        for(auto a: res.val) a = sin(a);
        return res;
    }
    Tensor exp(const Tensor & ob)
    {
        Tensor res = ob;
        for(auto a: res.val) a = exp(a);
        return res;
    }
    Tensor log(const Tensor & ob)
    {
        Tensor res = ob;
        for(auto a: res.val)
        {
            a = log(a);
            if(Matrix::get_error()!=0)
            {
                Tensor::set_error(Matrix::get_error());
                return ob;
            }
        }
        return res;
    }
    Tensor sigmoid(const Tensor &)
    {
        Tensor res = ob;
        for(auto a: res.val) a = sigmoid(a);
        return res;
    }
    Tensor tanh(const Tensor &)
    {
        Tensor res = ob;
        for(auto a: res.val) a = tanh(a);
        return res;
    }

    Matrix concat(const Matrix & a, const Matrix & b, const int catdim)//catdim只能是0/1
    {
        if((concat!=0 && concat!=1) || a.get_size(1-catdim) != b.get_size(1-catdim))//mismatch
        {
            Matrix::set_error(5);//5...
            return a;//???
        }
        if(catdim == 0)
        {
            Matrix res(a.get_row()+b.get_row(), a.get_col());
            int asz = a.get_size(), bsz = b.get_size();
            for(int i=0; i<asz; i++) res.change_mval(i, a.get_mval(i);)
            for(int i=0; i<bsz; i++) res.change_mval(i+asz, b.get_mval(i);)
            return res;
        }
        if(catdim == 1)
        {
            Matrix res(a.get_row(), a.get_col()+b.get_col());
            int acol = a.get_col(), bcol = b.get_col();
            for(int i=0; i<a.get_row(); i++)
            {
                for(int k=0; k<acol; k++) res.change_mval(i, k, a.get_mval(i, k));
                for(int k=0; k<bcol; k++) res.change_mval(i, k+acol, b.get_mval(i, k));
            }
            return res;
        }
    }

    Tensor concat(const Tensor & a, const Tensor & b, const int catdim)//catdim:连接的那一维,从0开始
    {
        int dima = a.get_dim();
        int dimb = b.get_dim();
        if(dima!=dimb)
        {
            Tensor::set_error(5);//5...
            return a;//return what?
        }
        for(int i=0; i<dima; i++)
        {
            if((a.get_size(i)!=b.get_size(i)) && i!=catdim)
            {
                Tensor::set_error(5);//5...
                return a;//return what?
            }
        }

        std::vector<int> tmpsize;
        for(int i=0; i<dima; i++)
        {
            if(i!=catdim) tmpsize.push_back(a.get_size(i));
            else tmpsize.push_back(a.get_size(i)+b.get_size(i);)
        }
        Tensor res(tmpsize);

        if(catdim < dima-2)
        {
            int abatch = 1, bbatch = 1;
            int times = 0;//交替复制进去 交替的次数
            for(int i=catdim+1; i<dima-2; i++)
            {
                abatch *= a.get_size(i);
                bbatch *= b.get_size(i);
            }
            for(int i=0; i<catdim; i++) times *= a.get_size(i);
            times *= a.get_size(catdim) + b.get_size(catdim);
            for(int k=0; k<times; k++)
            {
                for(int i=0; i<abatch; i++) res.change_val(k*(abatch+bbatch)+i, a.get_val(k*abatch+i);)
                for(int i=0; i<bbatch; i++) res.change_val(k*(abatch+bbatch)+abatch+i, b.get_val(k*bbatch+i);)
            }
        }
        else //需要用到Matrix的concat
        {
            int times = res.get_val().size();
            for(int i=0; i<times; i++) res.change_val(i, concat(a.get_val(i), b.get_val(i), catdim-(dima-2)));
        }
        return res;
    }
}