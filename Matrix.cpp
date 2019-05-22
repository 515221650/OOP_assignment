//
// Created by hwy on 2019/5/21.
//
#include "Matrix.h"

Matrix Matrix::operator + (const Matrix& obj2) const//判断不符合相加要求？
{
    Matrix res(row, col);
    for(int i=0; i<row*col; i++)
    {
        res.data.push_back(data[i] + obj2.data[i]);
    }
    return res;
}

Matrix Matrix::operator - (const Matrix& obj2) const//判断不符合相加要求？
{
    Matrix res(row, col);
    for(int i=0; i<row*col; i++)
    {
        res.data.push_back(data[i] - obj2.data[i]);
    }
    return res;
}

Matrix Matrix::operator*(const Matrix &obj2) const
{
    Matrix res(row, obj2.col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<obj2.col; j++)
        {
            double sum = 0;
            for(int k=0; k<col; k++)
            {
                sum += data[i*col+k]*obj2.data[k*obj2.col+j];
            }
            res.data.push_back(sum);
        }
    }
    return res;
}

Matrix & Matrix::operator +=(const Matrix& obj2)
{
    *this = *this + obj2;
    return *this;
}

Matrix & Matrix::operator -=(const Matrix& obj2)
{
    *this = *this - obj2;
    return *this;
}

Matrix & Matrix::operator *=(const Matrix& obj2)
{
    *this = *this * obj2;
    return *this;
}
