//
// Created by hwy on 2019/6/1.
//
#include "Data.h"

std::vector<Tensor> Dataloader::get_data()
{
    vector<Tensor> loader;
    for(int i=0; i<BatchSize; i++)
    {
        loader.push_back(dataset->get_item());
    }
    return loader;
}