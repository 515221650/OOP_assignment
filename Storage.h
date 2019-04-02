//
// Created by hwy on 2019/3/30.
//

#ifndef BIGHOMEWORK_STORAGE_H
#define BIGHOMEWORK_STORAGE_H

#include <map>
#include <vector>
#include <string>

class Node;
class MyGraph{
private:
    struct NodeInfo{
        Node* NodePos;
        bool vis;
    };
    std::vector<NodeInfo> NodeInfoVec ;
    std::map <std::string, int> StrToIntMap ;
    std::map <std::string, float > PlaceholderRev;//其实可以用map 也可以省一些函数，就是会慢一点？
public:
    friend class Node;
    void insert_node(Node*, std::string);
    NodeInfo& operator [](std::string &str){ return NodeInfoVec[StrToIntMap[str]];} //add
    NodeInfo& operator [](int i) { return NodeInfoVec[i];}
    int str_to_int(std::string& str) { return StrToIntMap[str];}//还是重载下标运算符？？

    void insert_placeholder_rev(const std::string &str, float x){PlaceholderRev[str] = x;}
    std::pair<bool,float> GetPH(const std::string &str);
    void empty_placeholder_rev(){PlaceholderRev.clear();}

    void Mark(int x){NodeInfoVec[x].vis=1;}

    void create_root();
    void create_tree();
    void graph_compute();
    ~MyGraph();
};
//记得delete node
#endif //BIGHOMEWORK_STORAGE_H
