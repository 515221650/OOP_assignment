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
        std::string aim; float x;
        if(tmps == "EVAL")
        {
            g.empty_placeholder_rev();
            int ParaNum;
            std::ParaName;
            std::cin>>aim>>ParaNum;
            while(ParaNum--)
            {
                std::cin>>ParaName>>x;
                g.insert_placeholder_rev(ParaName, x)
            }
            int ans = (g[g.str_to_int(aim)].NodePos)->Compt(g, g.str_to_int(aim))
            if(!ans)
            {
                int res = g[aim].NodePos->Val();
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
            g[aim].NodePos->rev_val(x);
            myresult.push_back(0.0);//这也算一次操作...
        }
        else if(tmps == "SETANSWER")
        {
            int rank;
            std::cin>>aim>>rank;
            g[aim].NodePos->rev_val(myresult[rank]);
            myresult.push_back(0.0);
        }
    }
}


