//
// Created by player1 on 2019/5/4.
//
#include "test_minst.h"

//the function to read data from MINST, mainly copied from the Internet

int read_int(int i)
{
    unsigned char ch1, ch2, ch3, ch4;
    ch1 = i & 255;
    ch2 = (i >> 8) & 255;
    ch3 = (i >> 16) & 255;
    ch4 = (i >> 24) & 255;
    return((int)ch1 << 24) + ((int)ch2 << 16) + ((int)ch3 << 8) + ch4;
}
void read_Label(string filename, vector<double>& labels)
{
    ifstream file(filename, ios::binary);
    if(!file.is_open())
    {
        puts("ERROR: Can't find the file");
        return ;
    }
    int num = 0, size_image = 0;
    file.read((char*)&size_image, sizeof(size_image));
    file.read((char*)&num, sizeof(num));
    size_image = read_int(size_image);
    num = read_int(num);

    for(int i=0;i<num;i++)
    {
        unsigned char tmp = 0;
        file.read((char*)&tmp, sizeof(tmp));
        labels.push_back((double)tmp);
    }
}
void read_Data(string filename, vector<vector<double>>& data)
{
    ifstream file(filename, ios::binary);
    if(!file.is_open())
    {
        puts("ERROR: Can't find the file");
        return ;
    }
    int num = 0, size_image = 0, row = 0, col = 0;
    file.read((char*)&size_image, sizeof(size_image));
    file.read((char*)&num, sizeof(num));
    file.read((char*)&row, sizeof(row));
    file.read((char*)&col, sizeof(col));
    size_image = read_int(size_image);
    num = read_int(num);
    row = read_int(row);
    col = read_int(col);

   // std::cout<<"num"<<num<<std::endl;
    for(int i=0;i<num;i++)
    {
        vector<double>tp;
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<col;k++)
            {
                unsigned char tmp = 0;
                file.read((char*)&tmp, sizeof(tmp));
                tp.push_back((double)tmp/256);
            }
        }
        data.push_back(tp);
    }
}

void test_MINST() {
    vector<vector<double>> train_data_v, test_data_v;
    vector<double> train_labels_v, test_labels_v;
    read_Data("t10k-images.idx3-ubyte", test_data_v);
    read_Label("t10k-labels.idx1-ubyte", test_labels_v);
    read_Data("train-images.idx3-ubyte", train_data_v);
    read_Label("train-labels.idx1-ubyte", train_labels_v);
    vector<Tensor>train_data, test_data;
    for(int i = 0; i < test_data_v.size(); i++)train_data.push_back(Tensor(train_data_v[i]));
    for(int i = 0; i < test_data_v.size(); i++)test_data.push_back(Tensor(test_data_v[i]));
    vector<Tensor>train_labels, test_labels;
    for(int i = 0; i < test_data_v.size(); i++)train_labels.push_back(Tensor(train_labels_v[i]));
    for(int i = 0; i < test_data_v.size(); i++)test_labels.push_back(Tensor(test_labels_v[i]));


    auto *MyNet = new Neural_network();
    auto *G = new MyGraph();
    MyNet->add_target(10, *G);
    MyNet->add_Input(784, *G);
    MyNet->add_Dense(10, *G);
    MyNet->add_Sigmoid(*G);
    MyNet->add_Dense(10, *G);
    MyNet->add_Sigmoid(*G);
    MyNet->add_MSELoss(*G);
    Dataset train_set(train_data, train_labels);
    Dataset test_set(train_data, train_labels);
    Dataloader Train(train_set, 64);
    Dataloader Test(test_set, 64);
    //MyNet->load("epoch7_time=1026068.txt", *G);   //取消注释可开启load功能
    MyNet->train(Train, *G, true,  10, 1);
    MyNet->test(Test, *G, true);
}