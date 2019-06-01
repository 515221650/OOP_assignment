//
// Created by player0 on 2019/5/3.
//

#ifndef OOP_NEURAL_NETWORK_H
#define OOP_NEURAL_NETWORK_H

#include "Storage.h"
#include "Layer/Dense.h"
#include "Layer/Input.h"
#include "Layer/activationfunc.h"

class Neural_network {
private:
    std::vector<Layer*> seq;

public:
    Neural_network() {}
    int output();
    void add_Input(int num, MyGraph& G);
    void add_Dense(int num, MyGraph& G);
    void add_ReLU(MyGraph& G);
    void add_Sigmoid(MyGraph& G);

    void train(const std::vector<Tensor> & InputData, const std::vector<double> & TargetData, MyGraph& G, int epoch = 100, int batchsize = 128);

    void save(int cnt, MyGraph& G); //save learning data to .txt
    int load(std::string filename, MyGraph& G); //load learning data from .txt
};

/*class Neural_network {
private:
    std::vector<Layer*>seq; //pointers to its layers

public:
    Neural_network(){}
    int output(int j);  //return the the jth output's index in NodeInfoVec
    void add_Input(int num, MyGraph& G);    //add input layer
    void add_Dense(int num, MyGraph& G);    //add denses
    void train(const std::vector<std::vector<double>> & InputData, const std::vector<double> & TargetData, MyGraph& G, int epoch = 100, int batchsize = 128);
    void test(const std::vector<std::vector<double>> & InputData, const std::vector<double> & TargetData, MyGraph& G);
    void save(int cnt, MyGraph& G); //save learning data to .txt

    int load(std::string filename, MyGraph& G); //load learning data from .txt
};*/


#endif //OOP_NEURAL_NETWORK_H
