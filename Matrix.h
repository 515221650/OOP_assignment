//
// Created by hwy on 2019/5/20.
//

#ifndef OOP_MATRIX_H
#define OOP_MATRIX_H

#include<vector>
#include<iostream>
#include "ts.h"

class Tensor;
class Scalar;
class MyGraph;

class Matrix {
private:
    int col; //从0开始编号
    int row;
    std::vector<double> mval;

public:
    explicit Matrix(int row = 1, int col = 1, double val = 0) : col(col), row(row), mval(col * row, val) {}

    auto operator[](const int a) const { return mval.begin() + a * col; } //visit with obj[][]

    Matrix operator() (std::pair<int, int> rowp, std::pair<int, int> colp) const;

    Matrix operator*(const Matrix &obj2) const; //dot product

    Matrix operator+(const Matrix &obj2) const;

    Matrix operator-(const Matrix &obj2) const;

    Matrix operator-() const;

    Matrix operator/(const Matrix &obj2) const;

    Matrix operator>(const Matrix &obj2) const;

    Matrix operator<(const Matrix &obj2) const;

    Matrix operator>=(const Matrix &obj2) const;

    Matrix operator<=(const Matrix &obj2) const;

    Matrix &operator+=(const Matrix &obj2);

    Matrix &operator-=(const Matrix &obj2);

    Matrix &operator*=(const Matrix &obj2);

    Matrix cos() const;

    Matrix trans() const;

    Matrix sin() const;

    Matrix exp() const;

    Matrix log() const;

    Matrix sigmoid() const;

    Matrix tanh() const;

    Matrix abs() const;

    Matrix point_mul(const Matrix &) const; //dot product

    Matrix mat_mul(const Matrix &) const;

    Matrix concat(const Matrix &b, const int catdim) const;

    bool check_shape(const Matrix &obj2) const;

    int get_size() const { return row * col; }

    int get_size(int i) const {
        if (i == 0) return row;
        if (i == 1) return col;
    }

    int get_col() const { return col; }

    int get_row() const { return row; }

    const std::vector<double> &get_mval() const { return mval; }

    double get_mval(int p) const { return mval[p]; }

    double get_mval(int aimrow, int aimcol) const { return mval[aimrow * col + aimcol]; }

    void change_mval(int r, int c, double val) { mval[r * col + c] = val; }

    void add_mval(int r, int c, double val) { mval[r * col + c] += val; }

    void change_mval(int p, double val) { mval[p] = val; }

    void randn();

    friend class Tensor;

    friend class Scalar;

    friend class MyGraph;

    friend void ts::broadcast(int now_dim, Matrix &new_A, const Matrix &A, int pos);

    friend void ts::broadcast(int now_dim, Tensor &new_A, const Tensor &A, int pos);

    friend std::ostream& operator << (std::ostream& out, const Matrix &x);
};
#endif //OOP_MATRIX_H
