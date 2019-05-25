//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_TENSOR_H
#define OOP_TENSOR_H

#include <vector>
#include <cstdarg>
#include "Matrix.h"

using std::vector;
class Tensor {
private:
    int dim;
    vector<int> size; // 后两维是matrix的
    vector<Matrix> val;
    void add_dim(int sz) {size.push_back(sz); dim++;}
    static int error;
    static void set_error(int i){error = i;}
public:
    Tensor(std::initializer_list<int> szlist = {1, 1}, int mval = 0);//Tensor(5)是5*5还是1*5? 对dim==1的特判//默认填充0
    explicit Tensor(vector<int> szlist, int mval = 0);
    double operator() (std::initializer_list<int> arglist);
    Tensor operator() (std::initializer_list<std::pair<int,int> > arglist);
    Tensor operator+ (const Tensor& b) const;
    Tensor operator* (const Tensor& b) const;
    Tensor operator- (const Tensor& b) const;
    Tensor& reshape(std::initializer_list<int> szlist);
    static int get_error(){return error;}
    friend Matrix ts::sin(const Tensor&);
    friend Matrix ts::exp(const Tensor&);
    friend Matrix ts::log(const Tensor&);
    friend Matrix ts::sigmoid(const Tensor&);
    friend Matrix ts::tanh(const Tensor&);
    int get_dim(){return dim;}
    static int get_error() {return error};
    const vector<int> & get_size() {return size;}
    const int get_size(int i) {return size[i];}//返回指定维度的size
    const Matrix & get_val(int i) {return val[i];}
    const vector<Matrix> & get_val() {return val;}
    void change_val(int i, const Matrix & a){val[i] = a;}//越界报错？
};


#endif //OOP_TENSOR_H
