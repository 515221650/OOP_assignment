cmake_minimum_required(VERSION 2.8)
project(OOP)
MESSAGE(STATUS "Project: SERVER")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native -Wno-reorder")

add_executable(main main.cpp Node.h
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
        Layer/layer.h
        Layer/Dense.cpp Layer/Dense.h
        Layer/Input.cpp Layer/Input.h
        Neural_network.cpp Neural_network.h
        test_minst.h test_minst.cpp Operator_1/myassert.cpp Operator_1/myassert.h Operator_2/mybind.cpp Operator_2/mybind.h Operator_2/myassign.cpp Operator_2/myassign.h Tensor.cpp Tensor.h Matrix.h Matrix.cpp ts.h ts.cpp Operator_1/mygrad.cpp Operator_1/mygrad.h Operator_2/myat.cpp Operator_2/myat.h Scalar.h Scalar.cpp SessionRelated.h Layer/activationfunc.h Layer/activationfunc.cpp Operator_1/myrelu.h Operator_1/myrelu.cpp Utils/Data.h Utils/Data.cpp Layer/Conv.cpp Layer/Conv.h Operator_2/myconv.cpp Operator_2/myconv.h Layer/maxpool.cpp Layer/maxpool.h Operator_2/mycriterion.h Operator_2/mycriterion.cpp Layer/criterion.h Layer/criterion.cpp Equation_solver.cpp Operator_1/mymaxpool.h Operator_1/mymaxpool.cpp Operator_2/mymatmul.cpp Operator_2/mymatmul.h)
