//
// Created by player0 on 2019/5/1.
//

#include "Dense.h"
#include "../Storage.h"
#include "../createFunc.h"
#include "../Operator_0/MyVar.h"
#include "../Operator_0/MyPlaceholder.h"
#include "../Operator_0/MyConst.h"
#include "../Operator_3/MyCond.h"
#include "../Operator_1/myexp.h"
#include "../Operator_1/mylog.h"
#include "../Operator_1/myprint.h"
#include "../Operator_1/mysigmoid.h"
#include "../Operator_1/mysin.h"
#include "../Operator_1/mytanh.h"
#include "../Operator_2/mydiv.h"
#include "../Operator_2/myequal.h"
#include "../Operator_2/mygreater.h"
#include "../Operator_2/mygreaterequal.h"
#include "../Operator_2/myless.h"
#include "../Operator_2/mylessequal.h"
#include "../Operator_2/myplus.h"
#include "../Operator_2/mymul.h"
#include "../Operator_2/myminus.h"
#include <string>
// 初始化的参数是否需要传进来，这里写的是 0 ~ 5/in_num 随机变量

void Dense::build(MyGraph& G)
{
    //RD
    Node* newNode;
    std::string w_name;
    //命名
    newNode = new MyVar(w_name, Tensor({out_num, in_num}));
    G.insert_node(newNode, w_name);
    W = G.str_to_int(w_name);

    std::string ans_w_name;
    //命名
    newNode = new MyMul(ans_w_name, pre_layer.output(), W);
    G.insert_node(newNode, ans_w_name);
    int pre_add = G.str_to_int(ans_w_name);

    std::string b_name;
    //
    newNode = new MyVar(b_name, Tensor({out_num, 1}));
    G.insert_node(newNode, b_name);
    B = G.str_to_int(b_name);

    std::string pre_out_name;
    //
    newNode = new MyPlus(pre_out_name, pre_add, B);
    G.insert_node(newNode, b_name);
    out_pos = G.str_to_int(pre_out_name);
}

/*void Dense::build(MyGraph& G)
{
    #define RD ((float)(rand()%101)/20/in_num)+EPS

    for(int j=0;j<out_num;j++)
    {
        Node* newNode;
        int pre_add = -1;
        for(int i=0;i<in_num;i++)
        {
            //Node: wij
            std::string name_wij;
            //  这里命名 name
            newNode= new MyVar(name_wij, RD);
            G.insert_node(newNode, name_wij);
            // 第i个输入到第j个输出的权重
            int id_wij = G.str_to_int(name_wij);
            W.push_back(id_wij);

            //Node: wij * input
            std::string name_ans_wij;
            // 命名name
            newNode = new MyMul(name_ans_wij, pre_layer.output(i), id_wij);
            G.insert_node(newNode, name_ans_wij);
            int id_ans_wij = G.str_to_int(name_ans_wij);

            //Node: add up wij * input
            if(pre_add==-1)pre_add = id_ans_wij;
            else
            {
                std::string name_temp;
                //命名name
                newNode = new MyPlus(name_temp, pre_add, id_ans_wij);
                G.insert_node(newNode, name_temp);
                pre_add = G.str_to_int(name_temp);
            }
        }

        //Node: bias
        std::string name_bj;
        //  这里命名 name
        newNode= new MyVar(name_bj, RD);
        G.insert_node(newNode, name_bj);
        int id_bj = G.str_to_int(name_bj);
        B.push_back(id_bj);

        //Node: sigma(wij*input)+bias
        std::string name_pre_outj;
        // 这里命名 name
        newNode = new MyPlus(name_pre_outj, id_bj, pre_add);
        G.insert_node(newNode, name_pre_outj);
        int id_pre_outj = G.str_to_int(name_pre_outj);

        //Node: sigmoid (output)
        std::string name_outj;
        // 这里命名 name
        newNode = new MySigmoid(name_outj, id_pre_outj);
        G.insert_node(newNode, name_outj);
        int id_outj = G.str_to_int(name_outj);

        out_vec.push_back(id_outj);

    }
}*/