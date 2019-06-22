//
// Created by player1 on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include "Scalar.h"
#include "Storage.h"
#include "Operator_0/MyPlaceholder.h"
#include "Operator_0/MyVar.h"

void MyGraph::graph_compute()
{
    int q;
    std::cin>>q;
    std::cin.get();
    std::vector<Tensor> myresult;    //save the result of each eval
    while(q--)
    {
        std::string line;
        getline(std::cin, line);
        std::stringstream is(line);
        std::string tmps;
        is>>tmps;   //cin the first word
        std::string aim, aim2; float x;
        if(tmps == "SESSION")
        {
            is>>aim;
            change_session(aim);
            is>>tmps;
        }
        if(tmps == "EVAL")
        {
            empty_placeholder_rev();
            erase_mark();
            int ParaNum;
            is>>aim;

            if(!(is>>ParaNum)) ParaNum = 0;

            while(ParaNum--)    //cin the parameters
            {
                std::string ParaName;
                is>>ParaName>>x;
                insert_placeholder_rev(ParaName, x);
            }

            try
            {
                NodeInfoVec[str_to_int(aim)].NodePos->Compt(*this, str_to_int(aim));    //record the status of computation ; 0 means no errors
                Tensor res = NodeInfoVec[str_to_int(aim)].NodePos->Val();
                std::cout<<std::fixed<<std::setprecision(4)<<Scalar(res).get_val()<<std::endl;
                myresult.push_back(res);
            }
            catch(std::range_error& ERROR)
            {
                std::cout<< ERROR.what() <<std::endl;
                myresult.emplace_back(Tensor(0.0));
            }
            DerVec.clear();
            assign_change();
        }
        else if(tmps == "SETCONSTANT")
        {
            is>>aim>>x;
            change_var(StrToIntMap[aim], x);
            myresult.emplace_back(Tensor(0.0));
        }
        else if(tmps == "SETANSWER")
        {
            int rank;
            is>>aim>>rank;
            change_var(StrToIntMap[aim], myresult[rank-1]);
            myresult.emplace_back(Tensor(0.0));
        }
        else if(tmps == "NEWSESSION")
        {
            is>>aim;
            add_session(aim);
        }
        else if(tmps == "DELETESESSION")
        {
            is>>aim;
            erase_session(aim);
        }
    }
}


