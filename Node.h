//
// Created by HWY on 2019/3/30.
//

#ifndef BIGHOMEWORK_NODE_H
#define BIGHOMEWORK_NODE_H

#include <iostream>
#include <cmath>
#include "Storage.h"
#define EPS 1E-8

class Node{
protected:
    float val, der, dersum; //val: value  der: derivative  dersum: (used in Neural network) the sum of a certain group of derivatives
    std::string name;

    virtual int Calc(MyGraph& g) = 0; // calculate the value of the node (to get the value, use Compt first and Calc second)

public:
    Node(std::string &s, float x = 0.0):name(s), val(x) {}

    friend class MyGraph;

    virtual int Derivate(MyGraph& g) = 0;      // derivate 求导
    virtual int Compt(MyGraph& g, int x) = 0;  //compt the value in node (to get the value, use Compt first and Calc second)

    std::string Name() {return name;}
    float Val() {return val;}
    float Der() {return der;}
    float DerSum() {return dersum;}

    void rev_val(float x){val = x;return ;}
    void rev_der(float x){der = x;return ;}
    void rev_dersum(float x){dersum = x;}

    void add_der(float x){der += x;return ;}
    void add_val(float x){val+=x;}
    void add_dersum(float x){dersum += x;}

    virtual ~Node(){};
};

#endif //BIGHOMEWORK_NODE_H
