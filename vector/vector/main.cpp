#include"vector.h"
#include <iostream>
//#include<vector>

using namespace std;

//void my_printf(vector v)
//{
//	for (int i = 0; i < v.my_size(); i++)
//	{
//		cout << v[i] << end;;
//	}
//}



int main()
{
	vector v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	

	vector test(v);



}