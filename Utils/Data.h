//
// Created by hwy on 2019/6/1.
//

#ifndef OOP_DATASET_H
#define OOP_DATASET_H

#include <vector>
#include <tuple>
#include "../Tensor.h"

class Dataset{
protected:
    std::vector<Tensor> input_data;
    std::vector<Tensor> output_data;
    int len;
    int now;
public:
    explicit Dataset(std::vector<Tensor> & in_data, std::vector<Tensor> & out_data):
        input_data(in_data), output_data(out_data), len(in_data.size()), now(0){}
    virtual std::tuple< Tensor,  Tensor, bool> get_item();
    int get_len(){return len;}
};

class MINSTDataset : public Dataset{
public:
    explicit MINSTDataset(std::vector<Tensor> & in_data, std::vector<Tensor> & out_data): Dataset(in_data, out_data){};
   // virtual std::tuple<const Tensor&, const Tensor&, bool>  get_item();
};

class Dataloader { //如果有余数，用多出来的那部分
private:
    int BatchSize;
    Dataset* dataset;
public:
    Dataloader(Dataset& dataset, int bs): dataset(&dataset), BatchSize(bs){}
    bool get_data(std::vector<Tensor>& in_data, std::vector<Tensor>& out_data);
};

#endif //OOP_DATASET_H
