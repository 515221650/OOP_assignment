//
// Created by HWY on 2019/3/30.
//
#include "CreateFunc.h"
#include "Storage.h"
#include "Node.h"
#include <iostream>
#include <map>
#include <queue>
#define MK std::make_pair

void MyGraph::erase_mark()
{
    for(auto& i : NodeInfoVec)i.vis = false;
}
void MyGraph::erase_der()
{
    for(auto& i :NodeInfoVec)i.NodePos ->rev_der(0);
}
void MyGraph::insert_node(Node* NewNode, std::string name)
{
    NodeInfoVec.push_back({NewNode, 0});
    if(StrToIntMap.find(name)!=StrToIntMap.end()) StrToIntMap.erase(name);
    StrToIntMap.insert(std::pair<std::string, int>(name, NodeInfoVec.size()-1));
}

std::pair<bool,float> MyGraph::GetPH(const std::string &str)
{
    auto t = PlaceholderRev.find(str);
    if(t != PlaceholderRev.end())return MK(1, t->second);
    return MK(0,0);
}

#define MG (*this)

void MyGraph::create_root()
{
    int n = 0;
    std::cin>>n;
    std::string tmpscanf[2];
    while(n--)
    {
        std::cin>>tmpscanf[0]>>tmpscanf[1];
        if(tmpscanf[1]=="P") create_placeholder(tmpscanf[0], MG);
        if(tmpscanf[1]=="C") create_const(tmpscanf[0], MG);
        if(tmpscanf[1]=="V") create_var(tmpscanf[0], MG);
    }

}


typedef void (*fun1) (std::string&, MyGraph&);
typedef void (*fun2) (std::string&, std::string&, MyGraph&);

void MyGraph::create_tree()
{

    std::map <std::string, fun1> ScanfMap1 = {
            {"SIN", create_sin},
            {"LOG", create_log},
            {"EXP", create_exp},
            {"TANH", create_tanh},
            {"SIGMOID", create_sigmoid},
            {"PRINT", create_print},
            {"COND", create_cond}
    };//match the func

    std::map <std::string, fun2> ScanfMap2 = {
            {"+", create_plus},
            {"-", create_minus},
            {"*", create_mul},
            {"/", create_div},
            {">", create_greater},
            {"<", create_less},
            {">=", create_greaterequal},
            {"<=", create_lessequal},
            {"==", create_equal}
    };// match the operator node build func

    std::string MyScanf[4]; //input string
    int m = 0;
    std::cin>>m;    //number of inputs
    while(m--)
    {
        std::cin>>MyScanf[0]>>MyScanf[1]>>MyScanf[2];//name & "=" & first word
        if(ScanfMap1.find(MyScanf[2]) == ScanfMap1.end())
        {
            std::cin>>MyScanf[3];
            ScanfMap2[MyScanf[3]](MyScanf[0], MyScanf[2], MG);//怎么写...
        }
        else
        {
            ScanfMap1[MyScanf[2]](MyScanf[0], MG);
        }
    }
}


void MyGraph::push_der(int x)
{
    DerVec.push_back(x);
}

void MyGraph::change_var(std::string &name, float x)
{
    NodeInfoVec[str_to_int(name)].NodePos->rev_val(x);
}
void MyGraph::change_var(int id, float x)
{
    NodeInfoVec[id].NodePos->rev_val(x);
}
MyGraph::~MyGraph()
{
    int total = NodeInfoVec.size();
    for(int i=0;i<total;i++) delete NodeInfoVec[i].NodePos;
}
