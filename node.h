//
// Created by yzy on 2019/3/30.
//

#ifndef OOP_NODE_H
#define OOP_NODE_H
#define EPS 1E-8
#include <string>
class MyGraph;

class Node {
protected:
    std::string name;
    float val;
public:
    virtual int Calc(MyGraph &v);
    std::string Name();
    Node(std::string &s, float x = 0);

    float Val();
};


#endif //OOP_NODE_H
