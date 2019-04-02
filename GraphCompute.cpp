//
// Created by hwy on 2019/4/1.
//
#include <iostream>
#include <vector>
#include "GraphCompute.h"
#include "MyPlaceholder.h"

void MyGraph::graph_compute()
{
    int q;
    std::cin>>q;
    vector<float> myresult;
    while(q--)
    {
        std::string tmps;
        std::cin>>tmps;
        std::string aim; float x;
        if(tmps == "EVAL")
        {
            empty_placeholder_rev();
            int ParaNum;
            std::ParaName;
            std::cin>>aim>>ParaNum;
            while(ParaNum--)
            {
                std::cin>>ParaName>>x;
                insert_placeholder_rev(ParaName, x)
            }
            int ans = (NodeInfoVec[str_to_int(aim)].NodePos)->Compt(*this, str_to_int(aim))
            if(!ans)
            {
                int res = NodeInfoVec[str_to_int(aim)].NodePos->Val();//把g[aim]改了
                std::cout<<res<<std::endl;
                myresult.push_back(res);
            }
            else
            {
                if(ans == 1) std::cout << "Division by zero" << std::endl;
                if(ans == 2) std::cout << "LOG operators input must be positive" << std::endl;
                if(ans == 3) std::cout << "Placeholder missing" << std::endl;
                myresult.push_back(0.0);//???
            }
        }
        else if(tmps == "SETCONSTANT")
        {
            std::cin>>aim>>x;
            NodeInfoVec[str_to_int(aim)].NodePos->rev_val(x);
            myresult.push_back(0.0);//这也算一次操作...
        }
        else if(tmps == "SETANSWER")
        {
            int rank;
            std::cin>>aim>>rank;
            NodeInfoVec[str_to_int(aim)].NodePos->rev_val(myresult[rank-1]);
            myresult.push_back(0.0);
        }
    }
}


