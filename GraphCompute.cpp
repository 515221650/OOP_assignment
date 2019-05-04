//
// Created by hwy on 2019/4/1.
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
    std::vector<float> myresult;
    while(q--)
    {
        std::string line;
        getline(std::cin, line);
        std::stringstream is(line);
        std::string tmps;
        is>>tmps;
        std::string aim, aim2; float x;
        if(tmps == "DERIVATIVE")
        {
            empty_placeholder_rev();
            erase_mark();
            int ParaNum;
            std::string ParaName;
            is>>aim>>aim2;
            if(!(is>>ParaNum)) ParaNum = 0;
            while(ParaNum--)
            {
                is>>ParaName>>x;
                insert_placeholder_rev(ParaName, x);
            }
            int aim_num = str_to_int(aim);
            Node* ans_node = NodeInfoVec[aim_num].NodePos;
            int ans = ans_node->Compt(*this, aim_num);
            if(!ans)
            {
                erase_der();
                ans_node->rev_der(1);
                reverse(DerVec.begin(),DerVec.end());
                int DerStatus = 0;
                for(auto i : DerVec)
                    if(DerStatus = NodeInfoVec[i].NodePos->Derivate(*this)) break;
                if(DerStatus)
                {
                    std::cout<<"Underivable"<<std::endl;
                    myresult.push_back(0);
                }
                else
                {
                    float res =  NodeInfoVec[str_to_int(aim2)].NodePos->Der();
                    std::cout<<std::fixed<<std::setprecision(4)<<res<<std::endl;
                    myresult.push_back(res);
                }
            }
            else
            {
                if(ans == 1) std::cout << "ERROR: Division by zero" << std::endl;
                if(ans == 2) std::cout << "ERROR: LOG operator's input must be positive" << std::endl;
                if(ans == 3) std::cout << "ERROR: Placeholder missing" << std::endl;
                myresult.push_back(0.0);//???
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

            while(ParaNum--)
            {
                std::string ParaName;
                is>>ParaName>>x;
                insert_placeholder_rev(ParaName, x);
            }

            int ans = (NodeInfoVec[str_to_int(aim)].NodePos)->Compt(*this, str_to_int(aim));
            if(!ans)
            {
                float res = NodeInfoVec[str_to_int(aim)].NodePos->Val();//把g[aim]改了
                std::cout<<std::fixed<<std::setprecision(4)<<res<<std::endl;
                myresult.push_back(res);
            }
            else
            {
                if(ans == 1) std::cout << "ERROR: Division by zero" << std::endl;
                if(ans == 2) std::cout << "ERROR: LOG operator's input must be positive" << std::endl;
                if(ans == 3) std::cout << "ERROR: Placeholder missing" << std::endl;
                myresult.push_back(0.0);//???
            }
            DerVec.clear();
        }
        else if(tmps == "SETCONSTANT")
        {
            is>>aim>>x;
            change_var(aim, x);
            myresult.push_back(0.0);//这也算一次操作...
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


