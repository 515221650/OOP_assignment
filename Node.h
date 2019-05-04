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
    std::string name;
    float val, der, dersum;
    virtual int Calc(MyGraph& g) = 0;//private or public
public:
    friend class MyGraph;
    virtual int Compt(MyGraph& g, int x) = 0;
    virtual int Derivate(MyGraph& g);
    Node(std::string &s, float x = 0.0);
   // friend void  MyComputation(std::string aim, MyGraph a);
    std::string Name() {return name;}
    float Val() {return val;}
    float Der() {return der;}
    float DerSum() {return dersum;}
    void rev_val(float x){val = x;return ;}
    void rev_der(float x){der = x;return ;}
    void add_der(float x){der += x;return ;}
    void rev_dersum(float x){dersum = x;}
    void add_dersum(float x){der += x;}
    void add_val(float x){val+=x;}
};

#endif //BIGHOMEWORK_NODE_H
