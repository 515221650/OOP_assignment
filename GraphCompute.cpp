//
// Created by hwy on 2019/4/1.
//
#include <iostream>
#include <vector>
#include "GraphCompute.h"
#include "MyPlaceholder.h"

void graph_compute(MyGraph& g)
{
    int q;
    std::cin>>q;
    vector<float> myresult;
    while(q--)
    {
        std::string tmps;
        std::cin>>tmps;
        if(tmps == "EVAL")
        {
            g.empty_placeholder_rev();
            int ParaNum; std::string aim, ParaName; float x;
            std::cin>>aim>>ParaNum;
            while(ParaNum--)
            {
                std::cin>>ParaName>>x;
                Node* pnode = g[ParaName].NodePos;
                pnode->rev_val(x);
                g.mark_placeholder_rev(pnode->Rank());
            }
            if(!MyComputation(aim, g);)
            {
                int res = g[aim].NodePos->Val();
                std::cout<<res<<std::endl;
                myresult.push_back(res);
            }
            else myresult.push_back(0.0);//???
        }
        else if(tmps == "SETCONSTANT")
        {
            std::string aim; float x;
            std::cin>>aim>>x;
            g[aim].NodePos->rev_val(x);
            myresult.push_back(0.0);//这也算一次操作...
        }
        else if(tmps == "SETANSWER")
        {
            std::string aim; int rank;
            std::cin>>aim>>rank;
            g[aim].NodePos->rev_val(myresult[rank]);
        }
    }
}

