//
// Created by hwy on 2019/5/20.
//

#ifndef OOP_MATRIX_H
#define OOP_MATRIX_H

#include<vector>
#include "ts.h"

class Tensor;
class Scalar;

class Matrix{
private:
    int col; //从0开始编号
    int row;
    std::vector<double> mval;
    static int error;//需要初始化！！！
    static void set_error(int i){error = i;}
public: //这样好吗...
    explicit Matrix(int row = 1, int col = 1, int val = 0): col(col), row(row), mval(col*row, val){}
    auto operator[] (const int a) const {return mval.begin()+a*col;} //用obj[][]访问
    Matrix operator * (const Matrix & obj2) const;
    Matrix operator + (const Matrix & obj2) const;
    Matrix operator - (const Matrix & obj2) const;
    Matrix operator - () const;
    Matrix operator / (const Matrix & obj2) const;
    Matrix operator > (const Matrix & obj2) const;
    Matrix operator < (const Matrix & obj2) const;
    Matrix operator >= (const Matrix & obj2) const;
    Matrix operator <= (const Matrix & obj2) const;
    Matrix & operator +=(const Matrix & obj2);
    Matrix & operator -=(const Matrix & obj2);
    Matrix & operator *=(const Matrix & obj2);
    //Matrix MatMul(const Matrix & obj2) const; //either this or that should be changed
    Matrix cos() const;
    Matrix trans() const;
    Matrix sin() const;
    Matrix exp() const;
    Matrix log() const;
    Matrix sigmoid() const;
    Matrix tanh() const;
    Matrix abs() const;
    Matrix point_mul(const Matrix &) const;
    Matrix concat(const Matrix & b, const int catdim) const;
    int get_size() const {return row*col;}
    int get_size(int i) const {if(i==0) return row; if(i==1) return col;}
    int get_col() const {return col;}
    int get_row() const {return row;}
    double get_mval(int p) const {return mval[p];}
    double get_mval(int aimrow, int aimcol) const {return mval[aimrow*col+aimcol];}
    void change_mval(int r, int c, double val){mval[r*col+c] = val;}
    void change_mval(int p, double val) {mval[p] = val;}

    static int get_error(){return error;}
    friend class Tensor;
    friend class Scalar;
};

#endif //OOP_MATRIX_H
