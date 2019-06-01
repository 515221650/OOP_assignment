//
// Created by hwy on 2019/6/1.
//

#ifndef OOP_DATASET_H
#define OOP_DATASET_H

#include <vector>
#include "../Tensor.h"

class Dataset{
protected:
    std::vector<Tensor> data;
    int len;
    int now;
public:
    explicit Dataset(std::vector<Tensor> & data): data(data), len(data.size()), now(0){}
    virtual Tensor & get_item() = 0;
    int get_len(){return data.size();}
};

class MINSTDataset : public Dataset{
public:
    explicit MINSTDataset(std::vector<Tensor> & data): Dataset(data){};
    virtual Tensor &  get_item(){return data[now++];}
};

class Dataloader {
private:
    int BatchSize;
    Dataset* dataset;
public:
    Dataloader(Dataset& dataset, int bs): dataset(&dataset), BatchSize(bs){}
    std::vector<Tensor> get_data();
};

#endif //OOP_DATASET_H
