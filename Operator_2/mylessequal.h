//
// Created by player0 on 2019/4/1.
//

#ifndef OOP_MYLESSEQUAL_H
#define OOP_MYLESSEQUAL_H

#include "operator_2.h"
class MyLessEqual : public Operator_2 {
public:
    MyLessEqual(std::string &s, int x,int y);
    virtual int Calc(MyGraph &v);
    virtual int Derivate(MyGraph &v);

    virtual ~MyLessEqual(){};
};




#endif //OOP_MYLESSEQUAL_H
