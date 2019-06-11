//
// Created by hwy on 2019/6/1.
//
#include <stdexcept>
#include "Data.h"

std::tuple<Tensor, Tensor, bool> Dataset::get_item()
{
    bool nextstatus = true;
    if(now == len-1)
    {
        now = 0;
        nextstatus = false;
    }
    now++;
    return std::make_tuple(input_data[now], output_data[now], nextstatus);
}

bool Dataloader::get_data(std::vector<Tensor>& in_data, std::vector<Tensor>& out_data)
{
    in_data.clear();
    out_data.clear();
    for(int i=0; i<BatchSize; i++)
    {
        auto newitem = dataset->get_item();
        in_data.push_back(std::get<0>(newitem));
        out_data.push_back(std::get<1>(newitem));
        if(!std::get<2>(newitem)) return false;
    }
    return true;
}