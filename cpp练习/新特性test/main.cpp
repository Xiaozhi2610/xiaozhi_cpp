#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

//void fun(int, int, int = 10);
//
//void fun(int, int = 20, int);
//
//void fun(int = 30, int, int);
//
//void fun(int a, int b, int c)
//{
//	cout << a << " " << b << " " << c << endl;
//}

//class xiaozhi
//{
//public:
//	void f(int n);
//
//	void fun(int, int = 99);
//
//	xiaozhi(int n = 20);
//};
//
//void xiaozhi::f(int)
//{
//
//}
//
//void xiaozhi::fun(int = 10, int)
//{
//
//}
//
//xiaozhi::xiaozhi(int n = 10)
//{
//	cout << n << endl;
//}

//class xiaozhi
//{
//public:
//
//	virtual void fun(int n = 10)
//	{
//		cout << "n =  " << n << endl;
//	}
//};
//
//class xiaoxiaozhi:public xiaozhi
//{
//public:
//
//	void fun(int n = 20)
//	{
//		cout << "n =  " << n << endl;
//	}
//};

//class xiaozhi
//{
//public:
//	int n = 10;
//	static const int a = 10;
//	void f(int n = sizeof + a)
//	{
//		cout << n << endl;
//	}
//};

class xiaozhi
{
public:
	int n = 10;
	static const int a = 10;
	void f()
	{
		cout << n << endl;
	}
};






void test()
{
	//xiaozhi xz;
	// 
	//fun();

	/*xiaozhi* p = new xiaoxiaozhi;
	p->fun();*/

	/*int f = 10;
	void fun(int n = sizeof f);//gcc可以，msvc不行
	fun();*/

	/*void (xiaozhi:: * f)() = &xiaozhi::f;
	xiaozhi xz;
	(xz.*f)();*/








	cout << "hello wode" << endl;
}



int main()
{
	test();


	/*int f = 0;
	void fun(int n = sizeof(f));
	fun();*/



	return 0;
}

//void fun(int n)
//{
//	cout << n << endl;
//}