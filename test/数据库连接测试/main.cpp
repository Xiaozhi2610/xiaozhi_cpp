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
		cout << "�������������ӷ�ʽ: ";
		cin >> con;
	}
	if (con == 2)
	{
		std::cout << "��������Ҫ���ӵ�����IP��ַ: ";
		std::cin >> host;
		std::cout << "��������Ҫ��¼���û�: ";
		std::cin >> user;
		std::cout << "�������û��ĵ�¼����: ";
		std::cin >> pw;
		std::cout << "������Ҫ���ӵ����ݿ�����: ";
		std::cin >> database_name;
		std::cout << "������Ҫ���ӵĶ˿ں�: ";
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
			cout << "��ӭ�´�ʹ��" << endl;
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