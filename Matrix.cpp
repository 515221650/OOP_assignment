//
// Created by hwy on 2019/5/21.
//
#include "Matrix.h"
#include <cmath>
#include "Node.h"

std::ostream& operator << (std::ostream& out, const Matrix &x)
{
    cout<<'[';
    for(int i = 0; i < x.row; i++)
    {
        out<<'[';
        for(int j = 0; j < x.col; j++)
        {
            out<<x[i][j];
            if(j!=x.col-1)out<<',';
        }
        out<<']';
        if(i!=x.row-1)out<<',';
    }cout<<']';
    return out;
}

bool Matrix::check_shape(const Matrix & obj2) const
{
    if(row != obj2.row || col != obj2.col)
    {
        throw std::range_error("Tensor's shape doesn't match");
    }
    return 1;
}

Matrix Matrix::operator() (std::pair<int, int> rowp, std::pair<int, int> colp) const
{
    auto res = Matrix(rowp.second-rowp.first, colp.second-colp.first);
    for(int i=0; i<res.get_row(); i++)
    {
        for(int j=0; j<res.get_col(); j++)
        {
            res.change_mval(i, j, get_mval(i+rowp.first, j+colp.first));
        }
    }
    return res;
}


Matrix Matrix::operator + (const Matrix& obj2) const//判断不符合相加要求？
{
    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back(mval[i] + obj2.mval[i]);
    }
    return res;
}

Matrix Matrix::operator - (const Matrix& obj2) const//判断不符合相加要求？
{

    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back(mval[i] - obj2.mval[i]);
    }
    return res;
}

Matrix Matrix::operator - () const
{
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back(-mval[i]);
    }
    return res;
}

Matrix Matrix::operator / (const Matrix & obj2) const
{

    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        if(fabs(obj2.mval[i])<EPS)
        {
            throw std::range_error("ERROR: Division by zero");
        }
        res.mval.push_back(mval[i]/obj2.mval[i]);
    }
    return res;
}

Matrix Matrix::operator > (const Matrix& obj2) const//判断不符合相加要求？
{
    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back((mval[i] - obj2.mval[i])>EPS ? 1.0 : 0.0);
    }
    return res;
}

Matrix Matrix::operator < (const Matrix& obj2) const//判断不符合相加要求？
{
    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back((mval[i] - obj2.mval[i]) < (-EPS) ? 1.0 : 0.0);
    }
    return res;
}

Matrix Matrix::operator >= (const Matrix& obj2) const//判断不符合相加要求？
{
    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back((mval[i] - obj2.mval[i])>(-EPS) ? 1.0 : 0.0);
    }
    return res;
}

Matrix Matrix::operator <= (const Matrix& obj2) const//判断不符合相加要求？
{
    check_shape(obj2);
    Matrix res(row, col);
    res.mval.clear();
    for(int i=0; i<row*col; i++)
    {
        res.mval.push_back((mval[i] - obj2.mval[i])<EPS ? 1.0 : 0.0);
    }
    return res;
}

Matrix Matrix::operator*(const Matrix &obj2) const
{
    if(col != obj2.row)
    {
        throw std::range_error("Tensor's shape doesn't match while matmuling");
    }
    Matrix res(row, obj2.col);
    res.mval.clear();
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<obj2.col; j++)
        {
            double sum = 0;
            for(int k=0; k<col; k++)
            {
                sum += mval[i*col+k]*obj2.mval[k*obj2.col+j];
            }
            res.mval.push_back(sum);
        }
    }
    return res;
}

/*
Matrix Matrix::operator*(const Matrix &obj2) const  //dot mul
{
    check_shape(obj2);
    Matrix res(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res.mval.push_back(mval[i*col+j] * obj2.mval[i*col+j]);
        }
    }
    return res;
}*/




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


/*Matrix Matrix::MatMul(const Matrix &obj2) const
{
    Matrix res(row, obj2.col);
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<obj2.col; j++)
        {
            double sum = 0;
            for(int k=0; k<col; k++)
            {
                sum += mval[i*col+k]*obj2.mval[k*obj2.col+j];
            }
            res.mval.push_back(sum);
        }
    }
    return res;
}*/

Matrix Matrix::cos() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = ::cos(a);
    return res;
}

Matrix Matrix::trans() const
{
    Matrix res(this->row, this->col);
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->col;j++)
        {
            res.change_mval(i, j, this->get_mval(j, i));
        }
    }
    return res;
}

Matrix Matrix::sin() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = ::sin(a);
    return res;
}

Matrix Matrix::exp() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = ::exp(a);
    return res;
}

Matrix Matrix::log() const
{
    Matrix res = *this;
    for(auto &a: res.mval)
    {
        if(a <= EPS)
        {
            throw std::range_error("ERROR: LOG operator's input must be positive");
        }
        a = ::log(a);
    }
    return res;
}

Matrix Matrix::sigmoid() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = 1.0/(1.0+::exp(-a));
    return res;
}

Matrix Matrix::tanh() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = ::tanh(a);
    return res;
}

Matrix Matrix::abs() const
{
    Matrix res = *this;
    for(auto &a: res.mval) a = ::fabs(a);
    return res;
}

Matrix Matrix::point_mul(const Matrix & B) const
{
    check_shape(B);
    Matrix res = *this;
    for(int i=0;i<B.get_size();i++)
        res.change_mval(i, res.get_mval(i)*B.get_mval(i));
    return res;
}

Matrix Matrix::concat( const Matrix & b, const int catdim) const
{
    if((catdim!=0 && catdim!=1) || (this->get_size(1-catdim) != b.get_size(1-catdim)))//mismatch
    {
        throw std::range_error("Tensor's shape doesn't match while concating");
    }
    /*if((catdim!=0 && catdim!=1))//mismatch
    {
        std::cout<<"catdim"<<catdim<<std::endl;
        throw std::range_error("Tensor's shape doesn't match while concating");
    }
    if(this->get_size(1-catdim) != b.get_size(1-catdim))//mismatch
    {
        std::cout<<"size"<<this->get_size(1-catdim)<<std::endl<<b.get_size(1-catdim)<<std::endl;
        throw std::range_error("Tensor's shape doesn't match while concating");
    }*/

    if(catdim == 0)
    {
        Matrix res(this->get_row()+b.get_row(), this->get_col());
        int asz = this->get_size(), bsz = b.get_size();
        for(int i=0; i<asz; i++) res.change_mval(i, this->get_mval(i));
        for(int i=0; i<bsz; i++) res.change_mval(i+asz, b.get_mval(i));
        return res;
    }
    if(catdim == 1)
    {
        Matrix res(this->get_row(), this->get_col()+b.get_col());
        int acol = this->get_col(), bcol = b.get_col();
        for(int i=0; i<this->get_row(); i++)
        {
            for(int k=0; k<acol; k++) res.change_mval(i, k, this->get_mval(i, k));
            for(int k=0; k<bcol; k++) res.change_mval(i, k+acol, b.get_mval(i, k));
        }
        return res;
    }
}

void Matrix::randn()
{
    for(double& i : mval)
    {
        i = ((double)rand()/100-50)/50;
    }
}