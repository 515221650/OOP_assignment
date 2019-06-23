#include<bits/stdc++.h>
#include "Tensor.h"
using namespace std;

void easy_math()
{
    Tensor a({3,4},1),b({3,4},2);
    a.randn();b.randn();
    std::cout<<"a:"<<std::endl<<a<<std::endl;
    std::cout<<"b:"<<std::endl<<b<<std::endl;
    std::cout<<std::endl;

    Tensor c = a + b;
    std::cout<<"PLUS"<<std::endl<<c<<std::endl;

    c = a * b;
    std::cout<<"DOT PRODUCT"<<std::endl<<c<<std::endl;

    c = a - b;
    std::cout<<"MINUS"<<std::endl<<c<<std::endl;

    c = a / b;
    std::cout<<"DIVIDE"<<std::endl<<c<<std::endl;

    c = a > b;
    std::cout<<"GREATER"<<std::endl<<c<<std::endl;

    c = a < b;
    std::cout<<"LESS"<<std::endl<<c<<std::endl;

    c = a.cos();
    std::cout<<"COS"<<std::endl<<c<<std::endl;

    c = a.trans();
    std::cout<<"TRANSPOSITION"<<std::endl<<c<<std::endl;
}

void tensor_concat()
{
    std::cout<<"CONCAT"<<std::endl;


    {
        std::cout<<"test 0 : "<<std::endl;
        Tensor a({2,3,4},1),b({2,3,2},2);
        std::cout<<"a:"<<std::endl<<a<<std::endl;
        std::cout<<"b:"<<std::endl<<b<<std::endl;
        std::cout<<std::endl;
        Tensor c = ts::concat(a,b,2);
        std::cout<<"c:"<<std::endl<<c<<std::endl;
    }


    {
        std::cout<<"test 1 : "<<std::endl;
        Tensor a({2,3,4},1),b({2,1,4},2);
        std::cout<<"a:"<<std::endl<<a<<std::endl;
        std::cout<<"b:"<<std::endl<<b<<std::endl;
        std::cout<<std::endl;
        Tensor c = ts::concat(a,b,1);
        std::cout<<"c:"<<std::endl<<c<<std::endl;
    }

    {
        std::cout<<"test 2 : "<<std::endl;
        Tensor a({2,4,3},1),b({3,4,3},2);
        std::cout<<"a:"<<std::endl<<a<<std::endl;
        std::cout<<"b:"<<std::endl<<b<<std::endl;
        std::cout<<std::endl;
        Tensor c = ts::concat(a,b,0);
        std::cout<<"c:"<<std::endl<<c<<std::endl;
    }

}

void tensor_reshape()
{
    std::cout<<"RESHAPE"<<std::endl;

    std::cout<<"test 1 : "<<std::endl;
    Tensor a = ts::randn({4,3,2});
    std::cout<<"before reshape"<<std::endl<<a<<std::endl;

    a.reshape({2,3,-1});
    std::cout<<"after reshape"<<std::endl<<a<<std::endl;

    std::cout<<"test 2 : "<<std::endl;
    a = ts::randn({3,5,4});
    std::cout<<"before reshape"<<std::endl<<a<<std::endl;

    a.reshape({5,4,-1});
    std::cout<<"after reshape"<<std::endl<<a<<std::endl;
}

void tensor_slice()
{
    std::cout<<"SLICE"<<std::endl;

    Tensor a({2,3,4},1);
    a.randn();
    std::cout<<"a:"<<std::endl<<a<<std::endl;

    {
        std::cout<<"test 1:"<<std::endl;
        Tensor b = a({{0,1},{0,2},{1,3}});
        std::cout<<b<<std::endl;
    }


    {
        std::cout<<"test 2:"<<std::endl;
        Tensor b = a({{0,2},{1,3},{0,3}});
        std::cout<<b<<std::endl;
    }

}

void tensor_broadcast()
{
    std::cout<<"BROADCAST"<<std::endl;

    {
        std::cout<<"test 1:"<<std::endl;
        Tensor a({1,4,3},1),b({3,4,3},2);
        a.randn();b.randn();
        std::cout<<"before broadcast"<<std::endl;
        std::cout<<"a:"<<std::endl<<a<<std::endl;
        std::cout<<"b:"<<std::endl<<b<<std::endl;
        std::cout<<"after broadcast"<<std::endl;
        std::cout<<"a:"<<std::endl<<ts::broadcast(a,b).first<<std::endl;
        std::cout<<"b:"<<std::endl<<ts::broadcast(a,b).second<<std::endl;
    }
    {
        std::cout<<"test 1:"<<std::endl;
        Tensor a({1,4,3},1),b({2,1,1},2);
        a.randn();b.randn();
        std::cout<<"before broadcast"<<std::endl;
        std::cout<<"a:"<<std::endl<<a<<std::endl;
        std::cout<<"b:"<<std::endl<<b<<std::endl;
        std::cout<<"after broadcast"<<std::endl;
        std::cout<<"a:"<<std::endl<<ts::broadcast(a,b).first<<std::endl;
        std::cout<<"b:"<<std::endl<<ts::broadcast(a,b).second<<std::endl;
    }


}



int main()
{
	srand(time(0));
    try{
        easy_math();
        tensor_concat();
        tensor_reshape();
        tensor_slice();
        tensor_broadcast();
    }
    catch (std::range_error & ERROR)
    {
        std::cout<<ERROR.what()<<std::endl;
    }


	return 0;
} 
// g++ -o debug.exe  Tensor.cpp debug.cpp Matrix.cpp ts.cpp -std=c++14 -O2 
