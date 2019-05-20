//
// Created by player0 on 2019/5/3.
//

#include "Input.h"
#include "../Operator_0/MyVar.h"

void Input::build(MyGraph &G)
{
    for(int i=0;i<in_num;i++)
    {
        std::string name;
        // 这里命名
        Node* newNode = new MyVar(name, 0);
        G.insert_node(newNode, name);
        out_vec.push_back(G.str_to_int(name));
    }
}

void Input::change_input(const std::vector<double> &input, MyGraph &G)
{
    for(int i=0;i<in_num;i++)
    {
        G.change_var(out_vec[i], input[i]);
    }
}