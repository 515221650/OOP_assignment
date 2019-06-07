//
// Created by player1 on 2019/4/1.
//
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include "Storage.h"
#include "Operator_0/MyPlaceholder.h"

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
        if(tmps == "DERIVATIVE")
        {
            empty_placeholder_rev();
            erase_mark();
            int ParaNum;
            std::string ParaName;
            is>>aim>>aim2;
            if(!(is>>ParaNum)) ParaNum = 0;
            while(ParaNum--)    //cin parameters
            {
                is>>ParaName>>x;
                insert_placeholder_rev(ParaName, x);    //to save the value and mark that the placeholder is not missed
            }
            int aim_num = str_to_int(aim);
            Node* ans_node = NodeInfoVec[aim_num].NodePos;  //pointer to our aim node
            try
            {
                int ans = ans_node->Compt(*this, aim_num);  //ans: the status of computation; 0 means no error
                if(!ans)
                {
                    erase_der();
                    ans_node->rev_der(1);   //in der, we record the deravative of aiming node to current node 目标节点对当前节点的导数，目标节点的der初始化为1
                    reverse(DerVec.begin(), DerVec.end());   //DerVec is created in Compt, which indicate what nodes are related with aim node;
                    int DerStatus = 0;  //record the status of derivative; 0 means no errors
                    for(auto i : DerVec)
                    {
                        DerStatus = NodeInfoVec[i].NodePos->Derivate(*this);
                        if(DerStatus) break;
                    }

                    if(DerStatus)   //have errors
                    {
                        std::cout<<"ERROR: Underivable"<<std::endl;
                        myresult.push_back(0);
                    }
                    else
                    {
                        Tensor res =  NodeInfoVec[str_to_int(aim2)].NodePos->Der();
                        std::cout<<std::fixed<<std::setprecision(4)<<res<<std::endl;
                        myresult.push_back(res);
                    }
                }
            }
            catch(std::range_error ERROR)
            {
                std::cerr<<ERROR.what()<<std::endl;
                myresult.push_back(0.0);
            }
            DerVec.clear();
        }
        else if(tmps == "EVAL")
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
                int ans = (NodeInfoVec[str_to_int(aim)].NodePos)->Compt(*this, str_to_int(aim));    //record the status of computation ; 0 means no errors
                if(!ans)
                {
                    Tensor res = NodeInfoVec[str_to_int(aim)].NodePos->Val();
                    std::cout<<std::fixed<<std::setprecision(4)<<res<<std::endl;
                    myresult.push_back(res);
                }
            }
            catch(std::range_error ERROR)
            {
                std::cerr<< ERROR.what() <<std::endl;
                myresult.push_back(0.0);
            }
            DerVec.clear();
            assign_change();
        }
        else if(tmps == "SETCONSTANT")
        {
            is>>aim>>x;
            change_var(aim, x);
            myresult.push_back(0.0);
        }
        else if(tmps == "SETANSWER")
        {
            int rank;
            is>>aim>>rank;
            change_var(aim, myresult[rank-1]);
            myresult.push_back(0.0);
        }

    }
}


