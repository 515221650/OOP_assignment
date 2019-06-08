//
// Created by hwy on 2019/6/7.
//
#include <cmath>
#include "mymaxpool.h"

MyMaxPool::MyMaxPool(std::string &s, int x, int kernel_size, int _stride):
    Operator_1(s,x), kernel_size(kernel_size), stride(_stride){}

#define inf 1e8
int MyMaxPool::Calc(MyGraph &G)
{
    Tensor T = G[num].NodePos->Val();

    int high = (T.get_size(0));
    int row = (T.get_size(1));
    int col = (T.get_size(2));

    int new_row = ceil(1.0*(row - kernel_size) / stride) + 1;
    int new_col = ceil(1.0*(col - kernel_size) / stride) + 1;

    val = Tensor({high, new_row, new_col});

    for(int i=0; i<high; i++)
    {
        Matrix new_M(new_row, new_col);
        for(int kx=0; kx<new_row; kx++)
        {
            for(int ky=0; ky<new_col; ky++)
            {
                double maxv = -inf;
                for(int x=kx*stride; x<kx*stride+kernel_size && x<row; x++)
                {
                    for(int y=ky*stride; y<ky*stride+kernel_size && y<col; y++)
                    {
                        maxv = fmax(maxv, T.get_val(i).get_mval(x,y));
                    }
                }
                new_M.change_mval(kx, ky, maxv);
            }
        }
        val.change_val(i, new_M);
    }
}

int MyMaxPool::Derivate(MyGraph &G)
{
    Tensor T = G[num].NodePos->Val();
    int high = (T.get_size(0));
    int row = (T.get_size(1));
    int col = (T.get_size(2));
    Tensor res_T({high, row, col}, 0);

    int new_row = val.get_size(1);
    int new_col = val.get_size(2);

    for(int i=0; i<high; i++)
    {
        Matrix res_M(row, col, 0);
        for(int kx = 0; kx<new_row; kx++)
        {
            for(int ky = 0; ky<new_col; ky++)
            {
                double maxv = val.get_val(i).get_mval(kx, ky);
                for(int x=kx*stride; x<kx*stride+kernel_size && x<row; x++)
                {
                    for(int y=ky*stride; y<ky*stride+kernel_size && y<col; y++)
                    {
                        if(abs(maxv-T.get_val(i).get_mval(x,y))<EPS)
                        {
                            res_M.change_mval(kx, ky, res_M.get_mval(kx, ky)+der.get_val(i).get_mval(kx, ky));
                        }
                    }
                }
            }
        }
        res_T.change_val(i, res_M);
    }
    G[num].NodePos->add_der(res_T);
    return 0;
}

