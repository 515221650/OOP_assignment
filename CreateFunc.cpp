//
// Created by player1 on 2019/4/1.
//
#include <iostream>
#include <string>
#include "CreateFunc.h"
#include "Operator_0/MyVar.h"
#include "Operator_0/MyPlaceholder.h"
#include "Operator_0/MyConst.h"
#include "Operator_3/MyCond.h"
#include "Operator_1/myexp.h"
#include "Operator_1/mylog.h"
#include "Operator_1/myprint.h"
#include "Operator_1/mysigmoid.h"
#include "Operator_1/mysin.h"
#include "Operator_1/myassert.h"
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
#include "Operator_2/mybind.h"
#include "Operator_2/myassign.h"
#include "Operator_2/myat.h"
#include "Operator_1/mygrad.h"

//operator_0
int create_placeholder(std::string& name, MyGraph& g)
{
    MyPlaceholder* NewPlaceHolder = new MyPlaceholder(name);
    g.insert_node(NewPlaceHolder, name);

    return g.str_to_int(name);
}

int create_const(std::string& name, MyGraph& g, double val)
{
    MyConst* NewConst = new MyConst(name, val);
    g.insert_node(NewConst, name);

    return g.str_to_int(name);
}

int create_var(std::string& name, MyGraph& g, Tensor val)
{
    MyVar* NewVar = new MyVar(name, 0);//0是暂时的，后面可以改成默认值
    g.insert_node(NewVar, name);
    g.change_var(NewVar->get_index(), val);
    return g.str_to_int(name);
}

// operator_1

int create_sin(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MySin* NewNode = new MySin(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_log(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyLog* NewNode = new MyLog(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_exp(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyExp* NewNode = new MyExp(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_tanh(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyTanh* NewNode = new MyTanh(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_sigmoid(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MySigmoid* NewNode = new MySigmoid(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_print(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyPrint* NewNode = new MyPrint(name, IntPara);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_assert(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyAssert* NewConst = new MyAssert(name, IntPara);
    g.insert_node(NewConst, name);

    return g.str_to_int(name);
}

int create_grad(std::string StrPara, MyGraph& g, std::string& name)
{
    int IntPara = g.str_to_int(StrPara);
    MyGrad* NewConst = new MyGrad(name, IntPara);
    g.insert_node(NewConst, name);

    return g.str_to_int(name);
}

//operator_2

int create_plus(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyPlus* NewNode = new MyPlus(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);
    return g.str_to_int(name);
}

int create_minus(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyMinus* NewNode = new MyMinus(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_mul(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyMul* NewNode = new MyMul(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_div(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyDiv* NewNode = new MyDiv(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_greater(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyGreater* NewNode = new MyGreater(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_less(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyLess* NewNode = new MyLess(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_greaterequal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyGreaterEqual* NewNode = new MyGreaterEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_lessequal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyLessEqual* NewNode = new MyLessEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}


int create_equal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);

    MyEqual* NewNode = new MyEqual(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_bind(std::string StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara[2];
    IntPara[0] = g.str_to_int(StrPara1);
    IntPara[1] = g.str_to_int(StrPara2);

    MyBind* NewNode = new MyBind(name, IntPara[0], IntPara[1]);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_assign(std::string StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara[2];
    IntPara[0] = g.str_to_int(StrPara1);
    IntPara[1] = g.str_to_int(StrPara2);

    MyAssign* NewNode = new MyAssign(name, IntPara[0], IntPara[1]);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_at(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name)
{
    int IntPara1 = g.str_to_int(StrPara1);
    int IntPara2 = g.str_to_int(StrPara2);
    MyAt* NewNode = new MyAt(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

//Operator_3

int create_cond(std::string& StrPara1, std::string& StrPara2, std::string& StrPara3, MyGraph& g, std::string& name)
{
    int IntPara[3];
    IntPara[0] = g.str_to_int(StrPara1);
    IntPara[1] = g.str_to_int(StrPara2);
    IntPara[2] = g.str_to_int(StrPara3);

    MyCond* NewNode = new MyCond(name, IntPara[0], IntPara[1], IntPara[2]);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_mul(int IntPara1, int IntPara2, MyGraph& g, std::string& name)
{

    MyMul* NewNode = new MyMul(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}

int create_plus(int IntPara1, int IntPara2, MyGraph& g, std::string& name)
{

    auto NewNode = new MyPlus(name, IntPara1, IntPara2);
    g.insert_node(NewNode, name);

    return g.str_to_int(name);
}