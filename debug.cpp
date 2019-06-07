#include<bits/stdc++.h>
#include "Tensor.h"
using namespace std;
void print(Matrix x)
{
	for(int i = 0; i < x.get_row(); i++)
	{
		for(int j = 0; j < x.get_col(); j++)
		{
			cout<<x[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
}
void print(Tensor y)
{
	int t = 1;
	if(y.get_dim() == 3)t = y.get_size(0);
	for(int k = 0; k < t; k++)
	{
//		cout<<k<<endl;
		Matrix x = y.get_val(k);

		for(int i = 0; i < x.get_row(); i++)
		{
			for(int j = 0; j < x.get_col(); j++)
			{
				cout<<x[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	srand(time(0));
	
//	Matrix a(2,2,1),b(2,2,2);
//	a.randn();b.randn();
//	print(a);print(b);
//	Matrix c = a + b;print(c);
//	 c = a * b;print(c);
//	 c = a - b;print(c);
//	 c = a / b;print(c);
//	 c = a > b;print(c);
//	 c = a < b;print(c);
//	 c = a.cos();print(c);
//	 c = a.trans();print(c);
//	 c = a.point_mul(b);print(c);
//	a+=b; print(a);
	
	
//	Tensor a({3,4},1),b({3,4},2);
//	a.randn();b.randn();
//	print(a);print(b);
//	Tensor c = a + b;print(c);
//	c = a * b;print(c);
//	c = a - b;print(c);
//	c = a / b;print(c);
//	c = a > b;print(c);
//	c = a < b;print(c);
//	c = a.cos();print(c);
//	c = a.trans();print(c);
//	c = a.point_mul(b);print(c);
//	a+=b; print(a);
//	c.reshape({1,-1});print(c);
//	c.reshape({2,-1});print(c);
//	c.reshape({-1,6});print(c);
//	c.reshape({3,-1});print(c);
//	c.reshape({4,-1});print(c);

	Tensor a({5,3,4,2},1),b({5,3,1},2);
	cout<<a<<endl;
	//a.randn();b.randn();
//	print(a);
//	print(b);
//	Tensor c = ts::broadcast(a,b).first;
//    print(c);
    //print(ts::broadcast(a,b).second);
    /*print(a.get_val(1).get_size(1));
    print(a.get_val(1).get_size(0));
    print(b.get_val(1).get_size(1));
    print(b.get_val(1).get_size(0));*/

    //Tensor c = a.concat(b,0);
	//print(c);
   // Tensor c = a.concat(b,1);
	//print(c);
   // Tensor c = a.concat(b,2);
	//print(c);
	return 0;
} 
// g++ -o debug.exe  Tensor.cpp debug.cpp Matrix.cpp ts.cpp -std=c++14 -O2 
