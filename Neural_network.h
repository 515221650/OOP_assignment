//
// Created by player0 on 2019/5/3.
//

#ifndef OOP_NEURAL_NETWORK_H
#define OOP_NEURAL_NETWORK_H

#include "Storage.h"
#include "Layer/Dense.h"
#include "Layer/Input.h"
#include "Layer/activationfunc.h"
#include "Layer/criterion.h"
#include "Layer/Conv.h"
#include "Layer/maxpool.h"
#include "Layer/Reshape.h"
#include "Utils/Data.h"
#include "Scalar.h"


class Neural_network {
private:
    std::vector<Layer*> seq;
    Layer* tar; //groud truth
    Layer* cri; //criterion, calc loss
    std::vector<int> parameter;  //parameters in Neural_Network
public:
    Neural_network() = default;

    //get position (in NodeInfoVec)
    int outputpos();
    int cripos();

    //add layers
    void add_Input(int num, MyGraph& G);
    void add_Dense(int num, MyGraph& G);
    void add_ReLU(MyGraph& G);
    void add_Sigmoid(MyGraph& G);
    void add_MSELoss(MyGraph& G);
    void add_target(int num, MyGraph& G);
    void add_conv(int _in, int _out, MyGraph& G, int _kernel = 3, bool _bias= false, int _stride=1, int _padding=0);
    void add_maxpool(int _in, int _out, MyGraph& G);
    void add_Reshape(int _in, int _out, MyGraph& G, std::initializer_list<int> beforesize, std::initializer_list<int> aftersize);

    void train(Dataloader& DataLoader, MyGraph &G, bool need_accu, int epoch = 100, double learn_rate = 0.3);
    void test(Dataloader& DataLoader, MyGraph &G, bool need_accu = 0);

    void save(int cnt, MyGraph& G); //save learning data to .txt
    int load(std::string filename, MyGraph& G); //load learning data from .txt
};

#endif //OOP_NEURAL_NETWORK_H
