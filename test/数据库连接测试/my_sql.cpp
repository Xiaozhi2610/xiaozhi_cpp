#define _CRT_SECURE_NO_DEPRECATE
#include "my_sql.h"

my_sql::my_sql():
	host("127.0.0.1"),user("root"),pw("Xz261025"),database_name("xiaozhi"),port(3306)
{
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to datebase : Error:%s\n", mysql_error(con));
		return;
	}
	else
	{
		std::cout << "���ݿ����ӳɹ�����ӭʹ��" << std::endl;
	}
}

my_sql::my_sql(const char* host, const char* user, const char* pw, const char* database_name, const int port):
	host(host),user(user),pw(pw),database_name(database_name),port(port)
{
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");
	if (!mysql_real_connect(con, host, user, pw, database_name, port, NULL, 0))
	{
		fprintf(stderr, "Failed to connect to datebase : Error:%s\n", mysql_error(con));
		return;
	}
	else
	{
		std::cout << "���ݿ����ӳɹ�����ӭʹ��" << std::endl;
	}
}

my_sql::~my_sql()
{
	mysql_close(con);
	std::cout << "MySQL�ɹ��ر�" << std::endl;
}

void my_sql::insert()
{
	int flag = 1;
	int n = 0;
	while (flag)
	{
		std::cout << "ѡ�����ѧ���ķ�ʽ: 1(��������)/n(����n��ѧ��): ";
		std::cin >> n;
		if (n == 1)
		{
			student stu;
			sprintf(sql, "insert into xiaozhi (id,name,sfzh) values(%d,'%s','%s') ", stu.student_id, stu.student_name.c_str(), stu.student_sfzh.c_str());
			if (mysql_query(con, sql))
			{
				fprintf(stderr, "Failed to insert to datebase : Error:%s\n", mysql_error(con));
			}
			else
			{
				std::cout << "�ɹ������ѧ��" << std::endl;
			}
			std::cout << "�Ƿ�Ҫ������������? 0(NO)/1(YES): ";
			std::cin >> flag;
		}
		else if (n > 1)
		{
			for (int i = 1; i <= n; i++)
			{
				std::cout << "�����" << i << "��ѧ������Ϣ: " << std::endl;
				student stu;
				sprintf(sql, "insert into xiaozhi (id,name,sfzh) values(%d,'%s','%s') ", stu.student_id, stu.student_name.c_str(), stu.student_sfzh.c_str());
				if (mysql_query(con, sql))
				{
					fprintf(stderr, "Failed to insert to datebase : Error:%s\n", mysql_error(con));
				}
				else
				{
					std::cout << "�ɹ������ѧ��" << std::endl;
				}
			}
			std::cout << "�Ƿ�Ҫ������������? 0(NO)/1(YES): ";
			std::cin >> flag;
		}
		else
		{
			std::cout << "������������Ҫ����ѧ���ĸ���: ";
			std::cin >> n;
		}
	}
}


