//
// Created by hwy on 2019/6/1.
//
#include "Data.h"

Tensor& MINSTDataset::get_item()
{
    if(now == len-1)
    {
        now = 0;
        throw 1;
    }

}

bool Dataloader::get_data(std::vector<Tensor> &  bdata)
{
    for(int i=0; i<BatchSize; i++)
    {
        try{
            bdata.push_back(dataset->get_item());
        }
        catch(int)
        {
            return false;
        }
    }
    return true;
}