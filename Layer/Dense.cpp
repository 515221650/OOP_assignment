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
#include "../Operator_2/mymatmul.h"
#include "../Operator_2/myminus.h"
#include <string>
// 初始化的参数是否需要传进来，这里写的是 0 ~ 5/in_num 随机变量

using namespace std;

void Dense::build(MyGraph& G)
{
    Node* newNode;
    std::string w_name;
    //命名
    W = create_var(w_name, G, ts::randn({in_num, out_num}));

    std::string ans_w_name;
    //命名
    newNode = new MyMatMul(ans_w_name, pre_layer.output(), W);
    G.insert_node(newNode, ans_w_name);
    int pre_add = G.str_to_int(ans_w_name);

    std::string b_name;
    //命名
    B = create_var(w_name, G, ts::randn({1, out_num}));


    std::string pre_out_name;
    //命名
    newNode = new MyPlus(pre_out_name, pre_add, B);
    G.insert_node(newNode, b_name);
    out_pos = G.str_to_int(pre_out_name);
}