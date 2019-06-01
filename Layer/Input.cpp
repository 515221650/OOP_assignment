//
// Created by player0 on 2019/5/3.
//

#include "Input.h"
#include "../Operator_0/MyVar.h"

void Input::build(MyGraph &G, int num)
{
    std::string name;
    //这里命名

    Node* newNode = new MyVar(name);
    G.insert_node(newNode, name);
    G.change_var(name, Tensor({num,1}));
    out_pos = G.str_to_int(name);
}

void Input::change_input(const Tensor &input, MyGraph &G)
{
    G.change_var(out_pos, input);
}