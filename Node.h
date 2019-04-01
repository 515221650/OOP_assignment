//
// Created by HWY on 2019/3/30.
//

#ifndef BIGHOMEWORK_NODE_H
#define BIGHOMEWORK_NODE_H

#include "Storage.h"

//void  MyComputation(std::string aim, MyGraph a);

class Node{
protected:
    std::string name;
    float val;
    virtual int Calc(const MyGraph& g) = 0;//private还是public
public:
    virtual void rev_val(float x) = 0;
    virtual int Rank() = 0;
    virtual int Compt(const MyGraph& g) = 0;
    Node(std::string &s, float x);
    friend void  MyComputation(std::string aim, MyGraph a);
    float Val() {return val;}
};

#endif //BIGHOMEWORK_NODE_H
