//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_TENSOR_H
#define OOP_TENSOR_H

#include <vector>
#include <cstdarg>
#include "Matrix.h"
#include <iostream>
using std::vector;
class Tensor {
private:
    int dim;
    vector<int> size; // 后两维是matrix的
    vector<Matrix> val;
    void add_dim(int sz) {size.push_back(sz); dim++;}
    static int error;
    static void set_error(int i) {error = i;}
public:
    Tensor(double x):Tensor({1,1},x){}
    Tensor(std::initializer_list<int> szlist = {1, 1}, int mval = 0);//Tensor(5)是5*5还是1*5? 对dim==1的特判//默认填充0
    explicit Tensor(vector<int> szlist, int mval = 0);
    double operator() (std::initializer_list<int> arglist);
    Tensor operator() (std::initializer_list<std::pair<int,int> > arglist);
    Tensor operator+ (const Tensor& b) const;
    Tensor operator* (const Tensor& b) const;
    Tensor operator- (const Tensor& b) const;
    Tensor operator- () const;
   // Tensor& reshape(std::initializer_list<int> szlist);
    static int get_error(){return error;}
    friend Tensor ts::trans(const Tensor&);
    friend Tensor ts::point_mul(const Tensor&, const Tensor&);
    friend Tensor ts::sin(const Tensor&);
    friend Tensor ts::exp(const Tensor&);
    friend Tensor ts::log(const Tensor&);
    friend Tensor ts::sigmoid(const Tensor&);
    friend Tensor ts::tanh(const Tensor&);
    friend Tensor ts::concat(const Tensor & a, const Tensor & b, const int catdim);
    friend std::ostream& operator << (std::ostream& out, Tensor &x);

    int Size(){return val.size()*size[dim-1]*size[dim-2];}
    int get_dim() const {return dim;}
    const vector<int> & get_size() const {return size;}
    const int get_size(int i) const {return size[i];}//返回指定维度的size
    const Matrix & get_val(int i) const {return val[i];}
    const vector<Matrix> & get_val() const {return val;}
    void change_val(int i, const Matrix & a) const {val[i] = a;}//越界报错？

};
std::ostream& operator << (std::ostream& out, Tensor &x);

#endif //OOP_TENSOR_H
