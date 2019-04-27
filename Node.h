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
    float val, der;
    virtual int Calc(MyGraph& g) = 0;//private or public
public:
    friend class MyGraph;
    virtual int Compt(MyGraph& g, int x) = 0;
    virtual void Derivate(MyGraph& g) = 0;
    Node(std::string &s, float x = 0.0);
   // friend void  MyComputation(std::string aim, MyGraph a);
    std::string Name() {return name;}
    float Val() {return val;}
    float Der() {return der;}
    void rev_val(float x){val = x;return ;}
    void rev_der(float x){der = x;return ;}
    void add_der(float x){der += x;return ;}
};

#endif //BIGHOMEWORK_NODE_H
