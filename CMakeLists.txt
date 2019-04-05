cmake_minimum_required(VERSION 3.13)
project(OOP)
MESSAGE(STATUS "Project: SERVER")
set(CMAKE_CXX_STANDARD 14)

add_executable(OOP main.cpp node.cpp node.h
        Operator_1/operator_1.cpp Operator_1/operator_1.h
        Operator_2/operator_2.cpp Operator_2/operator_2.h
        Operator_3/Operator_3.cpp Operator_3/Operator_3.h
        Operator_0/Operator_0.cpp Operator_0/Operator_0.h
        Operator_2/myplus.cpp Operator_2/myplus.h
        Operator_2/myminus.cpp Operator_2/myminus.h
        Operator_2/mymul.cpp Operator_2/mymul.h
        Operator_2/mydiv.cpp Operator_2/mydiv.h
        Operator_1/mysin.cpp Operator_1/mysin.h
        Operator_1/mylog.cpp Operator_1/mylog.h
        Operator_1/myexp.cpp Operator_1/myexp.h
        Operator_1/mytanh.cpp Operator_1/mytanh.h
        Operator_1/mysigmoid.cpp Operator_1/mysigmoid.h
        Operator_0/MyConst.cpp Operator_0/MyConst.h
        Operator_0/MyPlaceholder.cpp Operator_0/MyPlaceholder.h
        Operator_0/MyVar.cpp Operator_0/MyVar.h
        Operator_2/mygreater.cpp Operator_2/mygreater.h
        Operator_2/myless.cpp Operator_2/myless.h
        Operator_2/mygreaterequal.cpp Operator_2/mygreaterequal.h
        Operator_2/mylessequal.cpp Operator_2/mylessequal.h
        Operator_2/myequal.cpp Operator_2/myequal.h
        Operator_1/myprint.cpp Operator_1/myprint.h
        Operator_3/MyCond.cpp Operator_3/MyCond.h
        Storage.cpp Storage.h
        CreateFunc.cpp CreateFunc.h
        GraphCompute.cpp
        )