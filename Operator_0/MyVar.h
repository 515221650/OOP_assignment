//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_MYVAR_H
#define BIGHOMEWORK_MYVAR_H

#include "Operator_0.h"

class MyVar : public Operator_0{
private:
    int index;
public:
    friend MyGraph;
    const Tensor& Val(){return MyGraph::now_session->get(index);} //override var 保证不会重名
    virtual int Calc(MyGraph& a);
    MyVar(std::string& name, int _index);
    int get_index(){return index;}
    virtual ~MyVar(){}
};

#endif //BIGHOMEWORK_MYVAR_H
