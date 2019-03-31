//
// Created by yzy on 2019/3/30.
//

#ifndef OOP_NODE_H
#define OOP_NODE_H

#include <string>

class Node {
protected:
    std::string name;
    float val;
public:
    virtual int Calc(Node **v);
    Node(string &s, float x);
    float Val();
};


#endif //OOP_NODE_H
