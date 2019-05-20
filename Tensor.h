//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_TENSOR_H
#define OOP_TENSOR_H

#include <vector>
#include <cstdarg>

using std::vector;
class Tensor {
private:
    int dim;
    vector<int>size;
    vector<double >val;
public:
    Tensor operator() (int a,...);
    Tensor operator+ (Tensor& b);
    Tensor operator* (Tensor& b);
    Tensor operator- (Tensor& b);
};


#endif //OOP_TENSOR_H
