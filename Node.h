//
// Created by player1 on 2019/3/30.
//

#ifndef BIGHOMEWORK_NODE_H
#define BIGHOMEWORK_NODE_H
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Tensor.h"
#include "Storage.h"

#define EPS 1E-20

class Node{
protected:
    Tensor val, der, dersum; //val: value  der: derivative  dersum: (used in Neural network) the sum of a certain group of derivatives
    std::string name;
    virtual int Calc(MyGraph& g) = 0; // calculate the value of the node (to get the value, use Compt first and Calc second)

public:
    Node(std::string _name, Tensor x = 0.0): name(_name),val(x) {}

    friend class MyGraph;

    virtual int Derivate(MyGraph& g) = 0;      // derivate 求导
    virtual int Compt(MyGraph& g, int x) = 0;  //compt the value in node (to get the value, use Compt first and Calc second)

    std::string Name(){return name;}
    const Tensor& Der() {return der;}
    const Tensor& DerSum() {return dersum;}
    const Tensor& Val() {return val;}//MyVar中override

    void rev_val(Tensor x){val = x;return ;}
    void rev_der(Tensor x){der = x;return ;}
    void rev_dersum(Tensor x){dersum = x;}

    void add_der(Tensor x){der = der + x;return ;}
    void add_val(Tensor x){val = val + x;}
    void add_dersum(Tensor x){dersum = dersum + x;}

    virtual ~Node(){};
};

#endif //BIGHOMEWORK_NODE_H
