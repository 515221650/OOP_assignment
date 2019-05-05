//
// Created by hwy on 2019/5/4.
//
#include "test_minst.h"

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

void test_MINST()
{
    vector<vector<double>>train_data, test_data;
    vector<double>train_labels, test_labels;
    read_Data("t10k-images.idx3-ubyte", test_data);
    read_Label("t10k-labels.idx1-ubyte", test_labels);
    read_Data("train-images.idx3-ubyte", train_data);
    read_Label("train-labels.idx1-ubyte", train_labels);
    Neural_network* MyNet = new Neural_network();
    MyGraph* G = new MyGraph();
    MyNet->add_Input(784, *G);
    MyNet->add_Dense(10, *G);
    MyNet->add_Dense(10, *G);
    MyNet->train(train_data, train_labels, *G, 10);
    MyNet->test(train_data, train_labels, *G);

    return ;
}