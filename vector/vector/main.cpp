#include"vector.h"
#include <iostream>
//#include<vector>

using namespace std;

void my_printf(vector& v)
{
	for (int i = 0; i < v.my_size(); i++)
	{
		cout << v[i] << endl;
	}
}



int main()
{
	vector v0(5);
	for (int i = 0; i < 5; i++)
	{
		v0.insert_fro(1, i);
		my_printf(v0);
	}

	vector v1(5);
	for (int i = 0; i < 5; i++)
	{
		v0.insert_bac(1, i);
		my_printf(v1);
	}

	getchar();



}