//
// Created by hwy on 2019/5/20.
//

#ifndef OOP_MATRIX_H
#define OOP_MATRIX_H

#include<vector>

class Tensor;

class Matrix{
private:
    int col; //从0开始编号
    int row;
    std::vector<double> data;
protected:
    Matrix();
    Matrix(int row, int col):col(col), row(row){}
    Matrix(int row, int col, int val): col(col), row(row), data(col*row, val){}
    auto operator[] (const int a) {return data.begin()+a*col;} //用obj[][]访问
    Matrix operator * (const Matrix & obj2) const;
    Matrix operator + (const Matrix & obj2) const;
    Matrix operator - (const Matrix & obj2) const;
    Matrix & operator +=(const Matrix & obj2);
    Matrix & operator -=(const Matrix & obj2);
    Matrix & operator *=(const Matrix & obj2);
    int get_col(){return col;}
    int get_row(){return row;}
    double get_data(int aimrow, int aimcol){return data[aimrow*col+aimcol];}
public:
    friend class Tensor;

};

#endif //OOP_MATRIX_H
