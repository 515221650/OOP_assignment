//
// Created by player1 on 2019/3/30.
//
#include "CreateFunc.h"
#include "Storage.h"
#include "Node.h"
#include <iostream>
#include <map>
#include <queue>
#include "Operator_0/MyVar.h"

#define MK std::make_pair
#define MG (*this)

MyGraph::Session* MyGraph::now_session = nullptr ;

MyGraph::MyGraph()
{
    Session* tmp = new Session();
    Session_name["init"] = tmp;
    now_session = tmp;
}

void MyGraph::change_session(std::string &str)
{
    if(Session_name.find(str) == Session_name.end())
    {
        std::cout<<"Session doesn't exist, change to default session"<<std::endl;
        now_session = Session_name["init"];
    }
    else now_session = Session_name[str];
}

MyGraph::Session* MyGraph::add_session(const std::string &str)
{
    if(Session_name.find(str) == Session_name.end())
    {
        Session* tmp = new Session(*Session_name["init"]);
        Session_name[str] = tmp;
    }
    else
    {
        puts("Session exist!");
    }
    return Session_name[str];
}

void MyGraph::erase_session(std::string &str)
{
    if(Session_name.find(str) != Session_name.end())
    {
        delete Session_name[str];
        Session_name.erase(str);
    }
}

Tensor MyGraph::GetVR(int x)
{
    return now_session->get(x);
}

std::pair<bool,Tensor> MyGraph::GetPH(const std::string &str)    // find the placeholder and its status
{
    auto t = PlaceholderRev.find(str);
    if(t != PlaceholderRev.end())return MK(1, t->second);
    return MK(0,0);
}


void MyGraph::create_root()     //create const or var or placeholder
{
    int n = 0;
    std::cin>>n;
    std::string tmpscanf[2];
    while(n--)
    {
        std::cin>>tmpscanf[0]>>tmpscanf[1];
        if(tmpscanf[1]=="P") create_placeholder(tmpscanf[0], MG);
        if(tmpscanf[1]=="C")
        {
            double val;
            std::cin>>val;
            create_const(tmpscanf[0], MG, val);
        }
        if(tmpscanf[1]=="V")
        {
            double val;
            std::cin>>val;
            create_var(tmpscanf[0], MG, val);
        }
    }
    now_session = add_session(std::string("default"));
}

typedef void (*fun1) (std::string&, MyGraph&);
typedef void (*fun2) (std::string&, std::string&, MyGraph&);
void MyGraph::create_tree()     //create others
{
#define MP std::make_pair

    std::map<std::string, int> op1 = {
            MP(std::string("SIN"),1),
            MP(std::string("LOG"),2),
            MP(std::string("EXP"),3),
            MP(std::string("TANH"),4),
            MP(std::string("SIGMOID"),5),
            MP(std::string("PRINT"),6),
            MP(std::string("ASSERT"),7),
            MP(std::string("GRAD"),8)
    };

    std::map<std::string, int> op2 = {
            MP(std::string("BIND"),1),
            MP(std::string("ASSIGN"),2)
    };

    std::map<std::string, int> op3 = {
            MP(std::string("COND"),1)
    };

    std::map<std::string, int> op4 = {
            MP(std::string("+"),1),
            MP(std::string("-"),2),
            MP(std::string("*"),3),
            MP(std::string("/"),4),
            MP(std::string(">"),5),
            MP(std::string("<"),6),
            MP(std::string(">="),7),
            MP(std::string("<="),8),
            MP(std::string("=="),9),
            MP(std::string("AT"),10)
    };


    std::string MyScanf[7]; //input string
    int m = 0;
    std::cin>>m;    //number of inputs
    while(m--)
    {
        std::cin>>MyScanf[0]>>MyScanf[1]>>MyScanf[2];//name & "=" & first word
        if(op1.find(MyScanf[2])!=op1.end())
        {
            std::cin>>MyScanf[3];
            switch(op1[MyScanf[2]])
            {
                case 1 : create_sin(MyScanf[3], MG, MyScanf[0]);break;
                case 2 : create_log(MyScanf[3], MG, MyScanf[0]);break;
                case 3 : create_exp(MyScanf[3], MG, MyScanf[0]);break;
                case 4 : create_tanh(MyScanf[3], MG, MyScanf[0]);break;
                case 5 : create_sigmoid(MyScanf[3], MG, MyScanf[0]);break;
                case 6 : create_print(MyScanf[3], MG, MyScanf[0]);break;
                case 7 : create_assert(MyScanf[3], MG, MyScanf[0]);break;
                case 8 : create_grad(MyScanf[3], MG, MyScanf[0]);break;
            }
        }
        else if(op2.find(MyScanf[2])!=op2.end())
        {
            std::cin>>MyScanf[3]>>MyScanf[4];
            switch(op2[MyScanf[2]])
            {
                case 1 : create_bind(MyScanf[3], MyScanf[4], MG, MyScanf[0]);break;
                case 2 : create_assign(MyScanf[3], MyScanf[4], MG, MyScanf[0]);break;
            }
        }
        else if(op3.find(MyScanf[2])!=op3.end())
        {
            std::cin>>MyScanf[3]>>MyScanf[4]>>MyScanf[5];
            switch(op3[MyScanf[2]])
            {
                case 1 : create_cond(MyScanf[3], MyScanf[4], MyScanf[5], MG, MyScanf[0]);break;
            }
        }
        else
        {
            std::cin>>MyScanf[3]>>MyScanf[4];//operator&Para2

            if(op4.find(MyScanf[3])!=op4.end())
            {
                switch(op4[MyScanf[3]])
                {
                    case 1: create_plus(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 2: create_minus(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 3: create_mul(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 4: create_div(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 5: create_greater(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 6: create_less(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 7: create_greaterequal(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 8: create_lessequal(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 9: create_equal(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;
                    case 10: create_at(MyScanf[2], MyScanf[4], MG, MyScanf[0]);break;

                }
            }

        }
    }
}

void MyGraph::push_der(int x)
{
    DerVec.push_back(x);
}

void MyGraph::insert_node(Node* NewNode, std::string name)
{
    NodeInfoVec.push_back({NewNode, 0});
    if(StrToIntMap.find(name)!=StrToIntMap.end()) StrToIntMap.erase(name);
    StrToIntMap.insert(std::pair<std::string, int>(name, NodeInfoVec.size()-1));
    IntToStr.push_back(name);
}

void MyGraph::insert_node(MyVar* NewNode, std::string name)
{
    NodeInfoVec.push_back({(Node*)(NewNode), 0});
    if(StrToIntMap.find(name)!=StrToIntMap.end()) StrToIntMap.erase(name);
    StrToIntMap.insert(std::pair<std::string, int>(name, NodeInfoVec.size()-1));
    IntToStr.push_back(name);
    NewNode->index = NodeInfoVec.size()-1;
}

void MyGraph::change_var(int index, Tensor x)
{
    now_session->change(index, x);
    NodeInfoVec[index].NodePos->rev_der(x);
}

void MyGraph::add_var(int id, Tensor x)
{
    now_session->change(id, GetVR(id)+x);
}

void MyGraph::assign_change()
{
    for(auto pir : ChangeVar)
    {
        change_var(pir.first, pir.second);
    }
    ChangeVar.clear();
}

void MyGraph::erase_mark()
{
    for(auto& i : NodeInfoVec)i.vis = false;
}

void MyGraph::erase_der()
{
    for(auto& i :NodeInfoVec)i.NodePos ->rev_der(0);
}

void MyGraph::clear_DerVec()
{
    DerVec.clear();
}

void MyGraph::save(std::string file)
{
    std::freopen(file.data(), "w", stdout);
    for(auto it : *now_session)
    {
        auto val = it.second.get_val();
        for(auto &i : val)
        {
            auto mval = i.get_mval();
            for(auto &j : mval)
            {
                std::cout<<' '<<j;
            }
        }
    }
    std::cout<<std::endl;
    fclose(stdout);
    freopen("CON","w",stdout);  //for Windows
    //freopen("/dev/tty","w",stdout);   //for Linux
}

void MyGraph::load(std::string file)
{
    std::freopen(file.data(), "r", stdin);
    for(auto it : *now_session)
    {
        Tensor &tmp_T = it.second;
        for(auto& i : tmp_T.val)
        {
            for(auto& j : i.mval )
            {
                std::cin>>j;
            }
        }
    }
    fclose(stdin);
}

MyGraph::~MyGraph()
{
    int total = NodeInfoVec.size();
    for(int i=0;i<total;i++) delete NodeInfoVec[i].NodePos;
    for(auto i: Session_name)delete i.second;
}