//
// Created by yzy on 2019/6/1.
//

#include "Conv.h"
#include "../Storage.h"
#include "../createFunc.h"
#include "../ts.h"
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
#include "../Operator_2/myconv.h"
#include <string>

void Conv::build(MyGraph &G)
{
    Node* newNode;
    std::string w_name;

    newNode = new MyVar(w_name);
    G.insert_node(newNode, w_name);
    K = G.str_to_int(w_name);
    G.change_var(w_name, ts::randn({out_num, in_num, kernel_size, kernel_size}));

    newNode = new MyConv(w_name, pre_layer.output(), K, padding, stride);
    G.insert_node(newNode, w_name);
    out_pos = G.str_to_int(w_name);
}
