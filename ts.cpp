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


    Tensor max_T(const Tensor & A, const Tensor & B)
    {
        return point_mul((A>=B), A) + point_mul((B>A), B);
    }

    Tensor randn(std::initializer_list<int> szlist)
    {
        Tensor tmp(szlist);
        tmp.randn();
        return tmp;
    }

    bool need_broadcast(const Tensor &A, const Tensor &B)
    {
        int dimA = A.get_dim(), dimB = B.get_dim();
        int maxdim = std::max(dimA, dimB);
        bool flag = 0;
        for(int i = 0; i < maxdim; i ++)
        {
            int sizeA, sizeB;

            if(dimA > i)sizeA = A.get_size(dimA - i - 1);
            else sizeA = 1;
            if(dimB > i)sizeB = B.get_size(dimB - i - 1);
            else sizeB = 1;

            if(sizeA != sizeB)
            {
                if (sizeA > 1 && sizeB > 1)
                {
                    std::terminate();
                }
                flag = 1;
            }
        }
        return flag;
    }

    void broadcast(int now_dim, Matrix &new_A,const Matrix &A, int pos)
    {
        int pos2 = new_A.mval.size(), sz = A.get_size(now_dim) , new_sz = new_A.get_size(now_dim), alpha = 1;
        if(now_dim != 1)alpha = A.get_size(now_dim+1);
        if (sz != new_sz)
        {
            broadcast(now_dim+1, new_A, A, pos*alpha);
            int pos3 = new_A.mval.size();
            for(int i = 1; i < new_sz; i++)
            {
                for(int j = pos2; j < pos3; j++)
                {
                    new_A.mval.push_back(new_A.mval[j]);
                }
            }
        }
        else
        {
            for(int i=0;i<sz;i++)
            {
                broadcast(now_dim+1, new_A, A, (pos+i)*alpha);
            }
        }
    }

    void broadcast(int now_dim, Tensor &new_A, const Tensor &A, int pos) //now中的size已经是正确的了
    {
        if(now_dim == A.dim - 2)
        {
            Matrix new_mt;new_mt.mval.clear();
            broadcast(0, new_mt, A.val[pos], 0);
            new_A.val.push_back(new_mt);
            return ;
        }


        int pos2 = new_A.val.size(), sz = A.get_size(now_dim) , new_sz = new_A.get_size(now_dim), alpha = 1;
        if(now_dim != A.dim-3)alpha = A.get_size(now_dim+1);
        if (sz != new_sz)
        {
            broadcast(now_dim+1, new_A, A, pos*alpha);
            int pos3 = new_A.val.size();
            for(int i = 1; i < new_sz; i++)
            {
                for(int j = pos2; j < pos3; j++)
                {
                    new_A.val.push_back(new_A.val[j]);
                }
            }
        }
        else
        {
            for(int i=0;i<sz;i++)
            {
                broadcast(now_dim+1, new_A, A, (pos+i)*alpha);
            }
        }
    }

    std::pair<Tensor, Tensor>broadcast(Tensor A, Tensor B) {
        int dimA = A.get_dim(), dimB = B.get_dim();
        int maxdim = std::max(dimA, dimB);
        if (dimA < maxdim) {
            A.dim = maxdim;
            std::vector<int> sz;
            for (int i = 0; i < maxdim - dimA; i++)sz.push_back(1);
            for (auto i : A.size)sz.push_back(i);
            A.size.swap(sz);
        }
        if (dimB < maxdim) {
            B.dim = maxdim;
            std::vector<int> sz;
            for (int i = 0; i < maxdim - dimA; i++)sz.push_back(1);
            for (auto i : A.size)sz.push_back(i);
            A.size.swap(sz);
        }

        std::vector<int> new_size;
        for (int i = 0; i < maxdim; i++) {
            new_size.push_back(std::max(A.get_size(i), B.get_size(i)));
        }

        Tensor new_A;
        new_A.val.clear();
        new_A.dim = maxdim;
        new_A.size = new_size;
        broadcast(0, new_A, A, 0);

        Tensor new_B;
        new_B.val.clear();
        new_B.dim = maxdim;
        new_B.size = new_size;
        broadcast(0, new_B, B, 0);

        return std::make_pair(A,B);
    }

    int get_max_pos_2d(Tensor& a)
    {
        int tensorsize = a.get_size(0) * a.get_size(1);//两维的
        int maxpos = 0;
        double maxv = a.get_val(0).get_mval(0);
        for(int i=0; i<tensorsize; i++)
        {
            double v = a.get_val(0).get_mval(i);
            if(v > maxv)
            {
                maxv = v;
                maxpos = i;
            }
        }
        return maxpos;
    }
}