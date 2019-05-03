//
// Created by yzy on 2019/5/3.
//

#ifndef OOP_NEURAL_NETWORK_H
#define OOP_NEURAL_NETWORK_H

#include "Storage.h"
#include "Layer/Dense.h"
#include "Layer/Input.h"
class Neural_network {
private:
    std::vector<Layer*>seq;
public:
    Neural_network(){}

    void add_Input(int num, MyGraph& G);
    void add_Dense(int num, MyGraph& G);
};


#endif //OOP_NEURAL_NETWORK_H
