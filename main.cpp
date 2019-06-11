#include <iostream>
#include <vector>
#include "Storage.h"
#include <stdio.h>
#include <ctime>
#include "test_minst.h"

int main()
{
    //if you want to use the fundamental function, please comment out the last two sentence;
    //if you want to test the neural network, comment out the other three instead;
    MyGraph i_love_compute;
    i_love_compute.create_root();//set const or var or placeholder
    i_love_compute.create_tree();//set others
    i_love_compute.graph_compute();//compute
   // std::srand(std::time(0));
   // test_MINST();
    //i_love_compute.solve_equation();

    return 0;
}