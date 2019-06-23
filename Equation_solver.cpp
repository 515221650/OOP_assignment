//
// Created by hwy on 2019/6/6.
//
#include <iomanip>
#include <cmath>
#include "Storage.h"
#include "Node.h"
#include "Scalar.h"
#include "CreateFunc.h"
#include "Operator_0/MyVar.h"
int MyGraph::create_term(int xpos, int last_term_pos, int degree, double k) //create a single term with certain degree and coefficient
{
    std::string name = std::to_string(degree);
    int prenode = create_const(name, *this, k);//k is the coefficient before each term
    for(int i=0; i<degree; i++)
    {
        prenode = create_mul(prenode, xpos, *this, name);
    }
    if(last_term_pos != -1) prenode = create_plus(last_term_pos, prenode, *this, name);//connect with last term

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

        //build the graph
        std::string xname = "x";
        int xpos = create_var(xname, *this, 0.0);
        int last_term_pos = -1;
        for(int i=degree; i>=0; i--)
        {
            double k;
            std::cin>>k;
            last_term_pos = create_term(xpos, last_term_pos, i, k);
        }

        //calc the answer
        double answerx = 0.0;
        std::cin>>answerx;
        change_var(xpos, answerx);
        try
        {
            for(int i=0; i<5; i++)
            {
                //compt the graph
                DerVec.clear();
                erase_mark();
                NodeInfoVec[last_term_pos].NodePos->Compt(*this, last_term_pos);
                double res = Scalar(NodeInfoVec[last_term_pos].NodePos->Val()).get_val();
                if(fabs(res)<EPS) break;

                //calc the derivative
                erase_der();
                NodeInfoVec[last_term_pos].NodePos->rev_der(Tensor(1));
                reverse(DerVec.begin(), DerVec.end());   //DerVec is created in Compt, which indicates that what nodes are associated with aim node;
                for(auto i : DerVec)
                {
                    NodeInfoVec[i].NodePos->Derivate(*this);
                }
                double derx = Scalar(NodeInfoVec[xpos].NodePos->Der()).get_val();

                //iterate
                if(fabs(derx)<EPS) throw std::range_error("Inappropriate Initial Value");
                std::cout<<std::fixed<<std::setprecision(4)<<Scalar(NodeInfoVec[xpos].NodePos->Val()).get_val()-res/derx<<" ";
                change_var(xpos, NodeInfoVec[xpos].NodePos->Val() - Tensor(res/derx));
            }
        }
        catch(std::range_error& ERROR)
        {
            std::cout<< ERROR.what() <<std::endl;
            continue;
        }
        std::cout<<std::endl;
    }
}



