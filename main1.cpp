//
// Created by hwy on 2019/6/20.
//

#include <iostream>
#include <vector>
#include "Storage.h"
#include <stdio.h>
#include <ctime>
#include "test_minst.h"

int main()
{
    MyGraph i_love_compute;
    i_love_compute.create_root();//set const or var or placeholder
    i_love_compute.create_tree();//set others
    i_love_compute.graph_compute();//compute
    return 0;
}