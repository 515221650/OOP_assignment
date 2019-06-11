//
// Created by yzy on 2019/5/18.
//

#ifndef OOP_TENSOR_H
#define OOP_TENSOR_H

#include <vector>
#include <cstdarg>
#include "Matrix.h"
#include <iostream>

class Scalar;
class MyGraph;
//class MyMatMul;
using std::vector;
class Tensor {
private:
    int dim;
    vector<int> size; // 后两维是matrix的
    vector<Matrix> val;
    void add_dim(int sz) {size.push_back(sz); dim++;}

public:
    Tensor(double x):Tensor({1,1},x){}
    Tensor(std::initializer_list<int> szlist = {1, 1}, double mval = 0);//Tensor(5)是5*5还是1*5? 对dim==1的特判//默认填充0
    explicit Tensor(vector<double> &vallist);
    explicit Tensor(vector<int> szlist, double mval = 0);
    double operator() (std::initializer_list<int> arglist);
    Tensor operator() (std::initializer_list<std::pair<int,int> > arglist);
    void slice_helper(std::vector<int>& startp, std::vector<int>& endp, int now, int pos, Tensor& res);
    Tensor operator+ (Tensor b) const;
    Tensor operator* (Tensor b) const;
    Tensor operator- (Tensor b) const;
    Tensor operator- () const;
    Tensor operator/ (Tensor b) const;
    Tensor operator> (Tensor b) const;
    Tensor operator< (Tensor b) const;
    Tensor operator>= (Tensor b) const;
    Tensor operator<= (Tensor b) const;
    Tensor & operator +=(const Tensor& obj2);
    Tensor & operator -=(const Tensor&  obj2);
    Tensor & operator *=(const Tensor & obj2);

    void reshape(std::initializer_list<int> szlist);
//    static int get_error(){return error;}

    Tensor trans() const ;
    Tensor cos() const;
    Tensor sin() const;
    Tensor exp() const;
    Tensor log() const;
    Tensor sigmoid() const;
    Tensor tanh() const;
    Tensor concat(const Tensor & b, const int catdim) const;
    Tensor point_mul(Tensor) const;
    Tensor mat_mul(const Tensor&) const;
    Tensor abs() const;

    friend std::pair<Tensor, Tensor> ts::broadcast(Tensor, Tensor);
    friend void ts::broadcast(int now_dim, Tensor &new_A, const Tensor &A, int pos);
    friend std::ostream& operator << (std::ostream& out, const Tensor &x);
    friend MyGraph;
    friend Scalar;
//    friend MyMatMul;
    void randn();
    bool check_shape(const Tensor& B) const;
    int Size(){return val.size()*size[dim-1]*size[dim-2];}
    int get_dim() const {return dim;}
    const vector<int> & get_size() const {return size;}
    const int get_size(int i) const {return size[i];}//返回指定维度的size
    const Matrix & get_val(int i) const {return val[i];}
    const vector<Matrix> & get_val() const {return val;}
    void change_val(int i, const Matrix & a) {val[i] = a;}//越界报错？
    void add_val(int i, const Matrix & a){val[i] += a;}
    void clear(){dim = 0;size.clear();val.clear();}
};
std::ostream& operator << (std::ostream& out, const Tensor &x);

#endif //OOP_TENSOR_H
