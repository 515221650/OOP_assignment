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
    //Neurual Network
    MyGraph i_love_compute;
    std::srand(std::time(0));
    try{
        //test_MNIST(); //mainly dense
        test_Conv();    //mainly convolutional
    }
    catch(std::range_error & ERROR)
    {
        std::cout<<ERROR.what()<<std::endl;
    }
    return 0;
}

