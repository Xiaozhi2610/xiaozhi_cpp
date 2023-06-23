#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;

//c++的程序模块叫做函数
//#include<iostream>的作用:iostram文件包含io输入输出流，通过#include预处理指令引进过来
//using namespace std的作用:引入std命名空间

//2.1
//void my_print()
//{
//	cout << "xiaozhi" << endl;
//	cout << "adress: ......" << endl;
//}

//2.2
//void admir_set()
//{
//	long long temp = 0;
//	cout << "输入一个距离(单位:long): ";
//	cin >> temp;
//	cout << endl;
//	cout << temp * 220 << "码" << endl;
//}

//2.3
//void print_thr()
//{
//	cout << "Three blind mice" << endl;
//}
//
//void print_see()
//{
//	cout << "See how they run" << endl;
//}

//2.4
//void gue_age()
//{
//	int age = 0;
//	cin >> age;
//	while (age > 100 || age <= 0)
//	{
//		cout << "请输入正确的年龄: ";
//		cin >> age;
//	}
//	cout << "your mouth haven: " << age * 12 << endl;
//}

//2.5
//void warm()
//{
//	double war = 0;
//	cout << "set a warm: ";
//	cin >> war;
//	cout << endl;
//	cout << "The warm is: " << war * 1.8 + 32.0 << endl;
//}

//2.6
//void long_time()
//{
//	double llong = 0;
//	cout << "set a long time: ";
//	cin >> llong;
//	cout << endl;
//	cout << "The longtime is: " << "jisuangongshi" << endl;
//}

//2.77
//void show_time()
//{
//	int fen = 0;
//	int hous = 0;
//	cout << "set a hous: ";
//	cin >> hous;
//	while (hous < 0 || hous > 23)
//	{
//		cout << endl;
//		cout << "set a hous again: ";
//		cin >> hous;
//	}
//	cout << endl;
//	cout << "set a fen";
//	cin >> fen;
//	while (fen < 0 || fen > 59)
//	{
//		cout << endl;
//		cout << "set fen again: ";
//		cin >> fen;
//	}
//	cout << endl;
//	cout << "the time is: " << hous << " : " << fen << endl;
//}

//为什么cpp有多种存储整形？根据不同的需求(数据的大小)合理的分配资源，减少资源的浪费
//short sor = 80
//unsigned int u_int = 42110
//C++没有提供自动防止超出整型限制的功能，可以使用头文件climits来确定限制情况。
//char赋值字母和ascll码效果一样
//大转小会损失精度(需要强转),小转大不会

//3.1
//void change()
//{
//	const double cha_chi = 1.6;
//	const double cha_cun = 20;
//	double cm = 0;
//	cout << "set your cm: ";
//	cin >> cm;
//	cout << endl;
//	cout << "your cha_chi: " << cha_chi * cm << endl;
//	cout << "your cha_cun: " << cha_cun * cm << endl;
//}

//6.1


class xiaozhi
{
public:
	static int a;
	int b = 0;
	xiaozhi()
	{
		cout << "xiaozhi wucangouzhao" << endl;
	}

	static void my_print()
	{
		cout << a << endl;
	}
	void myprint()
	{
		cout << a << endl;
		cout << b << endl;
	}
};

//template<typename T>
//void sort(T* left, T* right)
//{
//	if ()
//	{
//		cout << " " << endl;
//		return;
//	}
//	while (left < right)
//	{
//		for (T* l = left; l < right; l++)
//		{
//			if (*left < *l)
//			{
//				T temp = *left;
//				*left = *l;
//				*left = temp;
//			}
//		}
//		left++;
//	}
//}






#include <list>

using std::list;

int main()
{
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	for (auto it = l.begin(); it != l.end(); it++)
	{
		cout << *it << endl;
	}


	
}