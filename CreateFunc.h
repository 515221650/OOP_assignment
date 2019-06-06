//
// Created by player1 on 2019/4/1.
//

#ifndef BIGHOMEWORK_CREATEFUNC_H
#define BIGHOMEWORK_CREATEFUNC_H
#include "Storage.h"

// the function creating node
int create_placeholder(std::string& name, MyGraph& g);
int create_const(std::string& name, MyGraph& g, double val);
int create_var(std::string& name, MyGraph& g, double val);
int create_sin(std::string StrPara, MyGraph& g, std::string& name);
int create_log(std::string StrPara, MyGraph& g, std::string& name);
int create_exp(std::string StrPara, MyGraph& g, std::string& name);
int create_tanh(std::string StrPara, MyGraph& g, std::string& name);
int create_sigmoid(std::string StrPara, MyGraph& g, std::string& name);
int create_grad(std::string StrPara, MyGraph& g, std::string& name);
int create_print(std::string StrPara, MyGraph& g, std::string& name);
int create_assert(std::string StrPara, MyGraph& g, std::string& name);
int create_plus(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_minus(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_mul(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_div(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_greater(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_less(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_greaterequal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_lessequal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_equal(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_at(std::string& StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_bind(std::string StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_assign(std::string StrPara1, std::string StrPara2, MyGraph& g, std::string& name);
int create_cond(std::string& StrPara1, std::string& StrPara2, std::string& StrPara3, MyGraph& g, std::string& name);

#endif //BIGHOMEWORK_CREATEFUNC_H
