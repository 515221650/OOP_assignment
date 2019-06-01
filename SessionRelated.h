//
// Created by hwy on 2019/5/28.
//

#ifndef OOP_SESSIONRELATED_H
#define OOP_SESSIONRELATED_H

#include "Storage.h"
class Node;

class Scope
{
private:
    struct NodeInfo{
        Node* NodePos;
        bool vis;   //to mark if this node has been visited in former computation;
    };
   // MyGraph* graph;
    std::vector<NodeInfo> NodeInfoVec;
public:
    Scope(){}
};

#endif //OOP_SESSIONRELATED_H
