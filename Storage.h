//
// Created by player1 on 2019/3/30.
//
#include <iostream>
#ifndef BIGHOMEWORK_STORAGE_H
#define BIGHOMEWORK_STORAGE_H

#include <map>
#include <vector>
#include <string>

class Node;
class Neural_network;
class MyGraph{
private:
    struct NodeInfo{
        Node* NodePos;
        bool vis;   //to mark if this node has been visited in former computation;
    };
    std::vector<int> DerVec;                       // used for derivative
    std::vector<NodeInfo> NodeInfoVec ;            // set of nodes
    std::map <std::string, int> StrToIntMap ;      // name to id
    std::map <std::string, float > PlaceholderRev; // name to value about placeholder
    std::vector<std::pair<int, float> >ChangeVar;

public:
    friend class Node;
    friend class Neural_network;
    NodeInfo& operator [](int i) { return NodeInfoVec[i];}    // id to node
    NodeInfo& operator [](std::string &str){ return NodeInfoVec[StrToIntMap[str]];} // name to node
    std::pair<bool,float> GetPH(const std::string &str);   // find the placeholder and its status
    int str_to_int(std::string& str) { return StrToIntMap[str];} //id to name

    void create_root();   //create const or var or placeholder
    void create_tree();   //create others
    void graph_compute(); // compute answer

    void push_assign(int x,float y){ChangeVar.push_back(std::make_pair(x, y));}
    void push_der(int x); // push the node which was needed to the vector when derivate
    void insert_node(Node*, std::string); //insert the node into NodeInfoVec & StrToIntMap
    void insert_placeholder_rev(std::string &str, float x){PlaceholderRev[str] = x;}  //name to value

    void Mark(int x){NodeInfoVec[x].vis=1;}        // whether the node has been visited when computing
    void change_var(int id, float x);              // change the value of var with a certain id in NodeInfoVec
    void change_var(std::string &name, float x);   // change the value of var with a certain name
    void assign_change();

    void erase_mark();                             // init mark
    void erase_der();                              // init der
    void clear_DerVec();                           // delete DerVec
    void empty_placeholder_rev(){PlaceholderRev.clear();}

    ~MyGraph();
};
#endif //BIGHOMEWORK_STORAGE_H
