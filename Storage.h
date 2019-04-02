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
    std::vector<bool> PlaceholderRev;//其实可以用map 也可以省一些函数，就是会慢一点？
public:
    friend class Node;
    void insert_node(Node*, std::string);
    NodeInfo& operator [](std::string &str){ return NodeInfoVec[StrToIntMap[str]];} //add
    NodeInfo& operator [](int i) { return NodeInfoVec[i];}
    int str_to_int(std::string& str) { return StrToIntMap[str];}//还是重载下标运算符？？
    bool ph_if_rev(int i) { return PlaceholderRev[i];}
    int placeholder_rev_num() { return PlaceholderRev.size();}//感觉好不美观...
    void insert_placeholder_rev() { PlaceholderRev.push_back(0);}
    void empty_placeholder_rev();
    void mark_placeholder_rev(int rank);

    void create_root();
    void create_tree();
};
//记得delete node
#endif //BIGHOMEWORK_STORAGE_H
