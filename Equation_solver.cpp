//
// Created by hwy on 2019/6/6.
//
#include <iomanip>
#include <cmath>
#include "Storage.h"
#include "Node.h"
#include "Scalar.h"

int MyGraph::create_term(int xpos, int last_term_pos, int degree, double k)//k是前面的系数
{
    std::string name = std::to_string(degree);//名字没啥用
    int prenode = create_const(name, *this, k);
    for(int i=0; i<degree; i++)
    {
        prenode = create_mul(prenode, xpos, *this, name);
    }
    if(last_term_pos != -1) prenode = create_plus(last_term_pos, prenode, *this, name);

    return prenode;
}


void MyGraph::solve_equation()
{
    int num_eqt = 0;
    std::cin>>num_eqt;
    while(num_eqt--)
    {
        int degree = 0;
        std::cin>>degree;
        std::string xname = "x";
        int xpos = create_var(xname, *this, 0.0);
        int last_term_pos = -1;
        for(int i=degree; i>=0; i--)
        {
            double k;
            std::cin>>k;
            last_term_pos = create_term(xpos, last_term_pos, i, k);
        }
        //建好图了
        double answerx = 0.0;
        std::cin>>answerx;
        change_var(xpos, answerx);

        for(int i=0; i<5; i++)
        {
            //加和乘求导不会出问题
            NodeInfoVec[last_term_pos].NodePos->Compt(*this, last_term_pos);
            double res = Scalar(NodeInfoVec[last_term_pos].NodePos->Val()).get_val();
            if(fabs(res)<EPS) break;
            erase_der();
            NodeInfoVec[last_term_pos].NodePos->rev_der(Tensor(1));
            reverse(DerVec.begin(), DerVec.end());   //DerVec is created in Compt, which indicate what nodes are related with aim node;
            for(auto i : DerVec)  NodeInfoVec[i].NodePos->Derivate(*this);
            double derx = Scalar(NodeInfoVec[xpos].NodePos->Der()).get_val();
            change_var(xpos, NodeInfoVec[xpos].NodePos->Val()-Tensor(res/derx));
            std::cout  <<std::fixed<<std::setprecision(4) << Scalar(NodeInfoVec[xpos].NodePos->Val()).get_val() << std::endl;
        }
    }
}



