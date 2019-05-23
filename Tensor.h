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
public:
    Tensor();
    Tensor(std::initializer_list<int> szlist);//Tensor(5)是5*5还是1*5? 对dim==1的特判//默认填充0
    double operator() (std::initializer_list<int> arglist);
    Tensor operator() (std::initializer_list<std::pair<int,int> > arglist);
    Tensor operator+ (const Tensor& b) const;
    Tensor operator* (const Tensor& b) const;
    Tensor operator- (const Tensor& b) const;
};


#endif //OOP_TENSOR_H
