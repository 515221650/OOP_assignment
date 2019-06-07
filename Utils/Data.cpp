//
// Created by hwy on 2019/6/1.
//
#include <stdexcept>
#include "Data.h"

Tensor& MINSTDataset::get_item()
{
    if(now == len-1)
    {
        now = 0;
        throw std::range_error("exceed");
    }
//    now

}

bool Dataloader::get_data(std::vector<Tensor> &  bdata)
{
    for(int i=0; i<BatchSize; i++)
    {
        try{
            bdata.push_back(dataset->get_item());
        }
        catch(std::range_error& ERROR)
        {
            return false;
        }
    }
    return true;
}