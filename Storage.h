//
// Created by player1 on 2019/3/30.
//
#include <iostream>
#ifndef BIGHOMEWORK_STORAGE_H
#define BIGHOMEWORK_STORAGE_H

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "Tensor.h"
#include "CreateFunc.h"


class Node;
class Neural_network;
class MyGraph{
private:
    struct NodeInfo{
        Node* NodePos;
        bool vis;   //to mark if this node has been visited in former computation;
    };
    struct Session : public std::map<std::string, Tensor>{
    public:
        Tensor get(std::string& str)
        {
            return (*this)[str];
        }
        void change(std::string& str, Tensor& x)
        {
            (*this)[str] = x;
        }
    };

    std::map<std::string, Session*>Session_name;
    std::vector<int> DerVec;                       // used for derivative
    std::vector<NodeInfo> NodeInfoVec ;            // set of nodes
    std::vector<std::string> IntToStr;             // id to name
    std::map <std::string, int> StrToIntMap ;      // name to id
    std::map <std::string, Tensor > PlaceholderRev; // name to value about placeholder
    std::vector<std::pair<int, Tensor> >ChangeVar;
    //std::vector<std::vector<float> > DerV;
    static Session* now_session;
public:
    friend class Node;
    friend class Neural_network;
    NodeInfo& operator [](int i) { return NodeInfoVec[i];}    // id to node
    NodeInfo& operator [](std::string &str){ return NodeInfoVec[StrToIntMap[str]];} // name to node
    std::pair<bool,Tensor> GetPH(const std::string &str);   // find the placeholder and its status
    Tensor GetVR(std::string &str);
    int str_to_int(std::string& str) { return StrToIntMap[str];} //id to name

    MyGraph();
    void create_root();   //create const or var or placeholder
    void create_tree();   //create others
    void graph_compute(); // compute answer

    Session* add_session(const std::string &str);
    void erase_session(std::string &str);
    void change_session(std::string &str);
    void push_assign(int x,Tensor y){ChangeVar.push_back(std::make_pair(x, y));}
    void push_der(int x); // push the node which was needed to the vector when derivate
    void insert_node(Node*, std::string); //insert the node into NodeInfoVec & StrToIntMap
    void insert_placeholder_rev(std::string &str, Tensor x){PlaceholderRev[str] = x;}  //name to value

    void Mark(int x){NodeInfoVec[x].vis=1;}        // whether the node has been visited when computing

    void change_var(int id, Tensor x);              // change the value of var with a certain id in NodeInfoVec
    void change_var(std::string &name, Tensor x);   // change the value of var with a certain name

    void assign_change();

    void erase_mark();                             // init mark
    void erase_der();                              // init der
    void clear_DerVec();                           // delete DerVec
    void empty_placeholder_rev(){PlaceholderRev.clear();}

    void load(std::string &file);
    void save(std::string &file);
    ~MyGraph();
};
#endif //BIGHOMEWORK_STORAGE_H
