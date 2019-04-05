//
// Created by hwy on 2019/4/1.
//
#include <iostream>
#include <string>
#include "Storage.h"
#include "Operator_0/MyVar.h"
#include "Operator_0/MyPlaceholder.h"
#include "Operator_0/MyConst.h"
#include "Operator_3/MyCond.h"
#include "Operator_1/myexp.h"
#include "Operator_1/mylog.h"
#include "Operator_1/myprint.h"
#include "Operator_1/mysigmoid.h"
#include "Operator_1/mysin.h"
#include "Operator_1/mytanh.h"
#include "Operator_2/mydiv.h"
#include "Operator_2/myequal.h"
#include "Operator_2/mygreater.h"
#include "Operator_2/mygreaterequal.h"
#include "Operator_2/myless.h"
#include "Operator_2/mylessequal.h"
#include "Operator_2/myplus.h"
#include "Operator_2/mymul.h"
#include "Operator_2/myminus.h"

//#include "............................."

void create_placeholder(std::string& name, MyGraph& g)
{
    MyPlaceholder* NewPlaceHolder = new MyPlaceholder(name);
    g.insert_node(NewPlaceHolder, name);
}
void create_const(std::string& name, MyGraph& g)
{
    float val;
    std::cin>>val;
    MyConst* NewConst = new MyConst(name, val);
    g.insert_node(NewConst, name);
}
void create_var(std::string& name, MyGraph& g)
{
    float val;
    std::cin>>val;
    MyVar* NewVar = new MyVar(name, val);
    g.insert_node(NewVar, name);
}

void create_sin(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MySin* NewNode = new MySin(name, IntPara);
    g.insert_node(NewNode, name);
}

void create_log(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MyLog* NewNode = new MyLog(name, IntPara);
    g.insert_node(NewNode, name);
}

void create_exp(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MyExp* NewNode = new MyExp(name, IntPara);
    g.insert_node(NewNode, name);
}

void create_tanh(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MyTanh* NewNode = new MyTanh(name, IntPara);
    g.insert_node(NewNode, name);
}

void create_sigmoid(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MySigmoid* NewNode = new MySigmoid(name, IntPara);
    g.insert_node(NewNode, name);
}

void create_print(std::string& name, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara = g.str_to_int(StrPara);
    MyPrint* NewNode = new MyPrint(name, IntPara);
    g.insert_node(NewNode, name);
}

//operator_2

void create_plus(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyPlus* NewNode = new MyPlus(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_minus(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyMinus* NewNode = new MyMinus(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_mul(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyMul* NewNode = new MyMul(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_div(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyDiv* NewNode = new MyDiv(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}
void create_greater(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyGreater* NewNode = new MyGreater(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_less(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyLess* NewNode = new MyLess(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_greaterequal(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyGreaterEqual* NewNode = new MyGreaterEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

void create_lessequal(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyLessEqual* NewNode = new MyLessEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}


void create_equal(std::string& name, std::string& x, MyGraph& g)
{
    std::string StrPara;
    std::cin>>StrPara;
    int IntPara1 = g.str_to_int(x);
    int IntPara2 = g.str_to_int(StrPara);

    MyEqual* NewNode = new MyEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
}

//Operator_3
void create_cond(std::string& name, MyGraph& g)
{
    std::string StrPara[3];
    int IntPara[3];
    for(int i=0;i<3;i++)
    {
        std::cin>>StrPara[i];
        IntPara[i] = g.str_to_int(StrPara[i]);
    }
    MyCond* NewNode = new MyCond(name, IntPara[0], IntPara[1], IntPara[2]);
    g.insert_node(NewNode, name);
}