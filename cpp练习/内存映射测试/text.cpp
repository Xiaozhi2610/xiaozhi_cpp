#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <stack>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

class base
{
public:
	base()
	{
		cout << "base creat" << endl;
	}
	virtual void xz() = 0;

	std::string xiaozhi;
};


class xiaozhi :public base
{
public:
	xiaozhi()
	{
		cout << "xiaozhi creat" << endl;
	}
	xiaozhi(int n) :a(n)
	{
		cout << "xiaozhi creat(int n)" << endl;
	}
	void xz()
	{
		cout << "xiaozhi()" << endl;
	}
	int a = 0;
};

class xiaozhizhi :public base
{
public:
	xiaozhizhi()
	{
		cout << "xiaozhizhi creat" << endl;
	}
	void xz()
	{
		cout << "xiaozhizhi()" << endl;
	}
	int b = 0;
};

void* creat(int n)
{
	switch (n)
	{
	case 1:
	{
		return new xiaozhi();
	}
	case 2:
	{
		return new xiaozhizhi();
	}
	default:
		system("cls");
		cout << "error: nobulabula..." << endl;
		exit(0);
	}
}




int main()
{
	auto n = (size_t)(&((xiaozhi*)0)->a);
	xiaozhi xz(20);
	int temp = *(int*)((size_t)&xz + n);
	cout << temp << endl;






	return 0;
}

