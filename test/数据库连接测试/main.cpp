#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <mysql.h>
#include "my_sql.h"
#include "other.h"

using namespace std;

char host[] = "127.0.0.1";
char user[] = "root";
char pw[] = "Xz261025";
char database_name[] = "xiaozhi";
int port = 3306;
string temp;

int main()
{
	show_con();
	int con = 0;
	cin >> con;
	while (con != 1 && con != 2)
	{
		cout << "请重新输入连接方式: ";
		cin >> con;
	}
	if (con == 2)
	{
		std::cout << "请输入需要连接的主机IP地址: ";
		std::cin >> host;
		std::cout << "请输入需要登录的用户: ";
		std::cin >> user;
		std::cout << "请输入用户的登录密码: ";
		std::cin >> pw;
		std::cout << "请输入要连接的数据库名称: ";
		std::cin >> database_name;
		std::cout << "请输入要连接的端口号: ";
		std::cin >> port;
	}
	my_sql xiazhi_mysql(host,user,pw,database_name,port);
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
		case 2:
			xiazhi_mysql.update();
			break;
		case 3:
			xiazhi_mysql.my_delete();
			break;
		case 4:
			xiazhi_mysql.my_find();
			break;
		case 6:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
		myprint_menu();
		cin >> choose;
	}




	return 0;
}