#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <mysql.h>
#include "my_sql.h"
#include "other.h"

using namespace std;


int main()
{
	show_con();
	my_sql xiazhi_mysql;
	myprint_menu();
	int flag = 1;
	int choose = 0;
	cin >> choose;
	while (true)
	{
		switch (choose)
		{
		case 1:
			xiazhi_mysql.insert();
			break;
		case 6:
			cout << "欢迎下次使用" << endl;
			return 0;
		default:
			break;
		}
		myprint_menu();
		cin >> choose;
	}




	return 0;
}