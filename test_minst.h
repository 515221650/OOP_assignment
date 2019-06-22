//
// Created by player0 on 2019/5/4.
//
#ifndef BIGHOMEWORK_TEST_MINST_H
#define BIGHOMEWORK_TEST_MINST_H
#include "Neural_network.h"
#include <vector>
#include <fstream>
using namespace std;

//the function to read data from MINST, mainly copied from the Internet
int read_int(int i);
void read_Label(string filename, vector<double>& labels);
void read_Data(string filename, vector<vector<double>>& data);

void test_MNIST();
void test_Conv();

#endif //BIGHOMEWORK_TEST_MINST_H