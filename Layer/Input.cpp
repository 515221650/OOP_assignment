//
// Created by player0 on 2019/5/3.
//

#include "Input.h"
#include "../Operator_0/MyVar.h"

void Input::build(MyGraph &G, int num)
{
    std::string name;
    //这里命名
    out_pos = create_var(name, G, Tensor({1,num}));
}

void Input::change_input(const Tensor &input, MyGraph &G)
{
    G.change_var(dynamic_cast<MyVar*>(G[out_pos].NodePos)->get_index(), input);
}