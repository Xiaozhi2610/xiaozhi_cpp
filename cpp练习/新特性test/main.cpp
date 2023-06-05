#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <memory>
#include <cstdlib>
#include <array>

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

//void fun()
//{
//	std::vector<string> v;
//	copy(std::istream_iterator<string>(cin), std::istream_iterator<string>(), std::back_inserter(v));
//	sort(v.begin(), v.end());
//	unique_copy(v.begin(), v.end(), std::ostream_iterator<string>(cout, "\n"));
//}
//
//class xiaozhi
//{
//public:
//	int n = 10;
//	static const int a = 10;
//	void f()
//	{
//		cout << n << endl;
//	}
//};

//template <typename T>
//class xiaozhi
//{
//public:
//	xiaozhi()
//	{
//		cout << typeid(a).name() << endl;
//	}
//
//public:
//	T a = 0;
//};
//
//template <>
//class xiaozhi<int>
//{
//public:
//	xiaozhi()
//	{
//		cout << "int telihua" << endl;
//	}
//
//public:
//	int a = 0;
//};
//
//void fun()
//{
//	xiaozhi<int> xz;
//	xiaozhi<double> xxz;
//
//
//}

//void fun()
//{
//	std::allocator<int> my__alloc;
//	int* p = my__alloc.allocate(10);
//	/*for (int i = 0; i < 10; i++)
//	{
//		cin >> p[i];
//	}*/
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p[i] << " ";
//	}
//}

//void fun()
//{
//	std::array<int, 0> ary;
//	ary[0] = 10;
//	cout << ary[0] << endl;
//}

//std::string operator""_s(const char* str,size_t size)
//{
//	return { str };
//}
//
//void fun()
//{
//	cout << "xiaozhizhi"_s << endl;
//
//}


//int fun()
//{
//	static int a = 10;
//	auto p = [=] {
//		++a;
//	};
//	cout << sizeof(p) << endl;
//	p();
//	return a;
//}

//struct xiaozhi
//{
//	/*char a;
//	short b;*/
//	int c[];
//};

//void fun()
//{
//	//xiaozhi xz;
//	auto p = (xiaozhi*)malloc(sizeof(xiaozhi) + 10 * sizeof(int));
//	memset(p, 0, 40);
//	cout << sizeof(xiaozhi) << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		p->c[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << p->c[i] << " 0";
//	}
//	cout << endl;
//}

//void fun()
//{
//	int a[2] = { 1,2 };
//	auto [x,y] = a;
//	cout << x << " " << y << endl;
//	//cout << typeid(e2).name() << endl;
//}

//struct xiaozhi
//{
//	xiaozhi() = default;
//	xiaozhi(int a,int b):a(a),b(b)
//	{
//		cout << "(int a,int b):a(a),b(b)" << endl;
//	}
//	int a;
//	int b;
//	int n{};
//};
//
//void fun()
//{
//	xiaozhi xz(10, 20);
//	xiaozhi xxz{ 1,2 };
//	xiaozhi xzz;
//}

void fun()
{
	int a[5] = { 0,1,2,3,4 };
	for (int i = 0; i < 5; i++)
	{
		cout << i[a] << endl;
	}
}

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

	/*int a = fun();
	cout << a << endl;*/

	fun();






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