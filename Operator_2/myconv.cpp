//
// Created by yzy on 2019/6/1.
//

#include "myconv.h"
#include "../Matrix.h"

MyConv::MyConv(std::string &s, int x, int y, int _padding, int _stride):
    Operator_2(s, x, y), padding(_padding), stride(_stride){}

// 3维 4维 3维
int MyConv::Calc(MyGraph &G)
{
    // N = (W − F + 2P) / S + 1
    Tensor T1 = G[num1].NodePos->Val(), T2 = G[num2].NodePos->Val();

    int high = (T1.get_size(0));
    int row = (T1.get_size(1));
    int col = (T1.get_size(2));
    int ker_size = (T2.get_size(2));
    int new_row = (row - ker_size + 2*padding) / stride + 1;
    int new_col = (col - ker_size + 2*padding) / stride + 1;
    val = Tensor({T2.get_size(0), new_row, new_col});

    for(int q = 0; q < T2.get_size(0); q++)
    {
        Matrix new_T(new_row, new_col);
        for(int i = 0; i < new_row; i++)
        {
            for(int j = 0; j < new_col; j++)
            {
                double sum = 0;
                for(int k = 0; k < high; k++)
                {
                    const Matrix & kernel =  T2.get_val(q*high + k);
                    const Matrix & input = T1.get_val(k);
                    int max_l = std::min(ker_size, row+padding-i*stride);
                    for(int l = std::max(0, padding-i*stride); l < max_l; l++)
                    {
                        int max_t = std::min(ker_size, col+padding-j*stride);
                        for(int t = std::min(0, padding-j*stride); t < max_t; t++)
                        {
                            sum += kernel[l][t] * input [i*stride+l-padding][j*stride+t-padding];
                        }
                    }
                }
                new_T.change_mval(i, j, sum);
            }
        }
        val.change_val(q, new_T);
    }
    return 0;
}

int MyConv::Derivate(MyGraph &G)
{
    Tensor T1 = G[num1].NodePos->Val(), T2 = G[num2].NodePos->Val(), T3 = der;
    int high = (T1.get_size(0));
    int row = (T1.get_size(1));
    int col = (T1.get_size(2));
    int ker_size = (T2.get_size(2));
    int new_row = (row - ker_size + 2*padding) / stride + 1;
    int new_col = (col - ker_size + 2*padding) / stride + 1;
//    for(int q = 0; q < T2.get_size(0); q++)
//    {
//        const Matrix & output = T3.get_val(q);
//        // 先求卷积核的导数
//        for(int i = 0; i < high; i++)
//        {
//            Matrix tmp(ker_size, ker_size);
//            for(int j = 0; j < ker_size; j++)
//            {
//                for(int k = 0; k < ker_size; k++)
//                {
//                    int max_l = std::min(ker_size, row+padding-i*stride);
//                    for(int l = std::max(0, padding-i*stride); l < max_l; l++)
//                    {
//                        int max_t = std::min(ker_size, col+padding-j*stride);
//                        for(int t = std::min(0, padding-j*stride); t < max_t; t++)
//                        {
//
//                        }
//                    }
//                }
//            }
//        }
//    }
    Tensor Dr_ker({T2.get_size(0), high, ker_size, ker_size});
    Tensor Dr_per({high, row, col});
    for(int q = 0; q < T2.get_size(0); q++)
    {
        for(int i = 0; i < new_row; i++)
        {
            for(int j = 0; j < new_col; j++)
            {
                double sum = der({q, i ,j});
                for(int k = 0; k < high; k++)
                {
                    const Matrix & kernel =  T2.get_val(q*high + k);
                    const Matrix & input = T1.get_val(k);
                    Matrix tmp_ker(ker_size, ker_size);
                    Matrix tmp_per(row, col);
                    int max_l = std::min(ker_size, row+padding-i*stride);
                    for(int l = std::max(0, padding-i*stride); l < max_l; l++)
                    {
                        int max_t = std::min(ker_size, col+padding-j*stride);
                        for(int t = std::min(0, padding-j*stride); t < max_t; t++)
                        {
                            tmp_ker.add_mval(l, t, input[i*stride+l-padding][j*stride+t-padding]);
                            tmp_per.add_mval(i*stride+l-padding, j*stride+t-padding, kernel[l][t]);
                        }
                    }
                    Dr_ker.change_val(q*high + k, tmp_ker);
                    Dr_per.add_val(k, tmp_per);
                }
            }
        }
    }
    G[num2].NodePos->add_der(Dr_ker);
    G[num1].NodePos->add_der(Dr_per);
}