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

void my_sql::update()
{
	int flag = 1;

	while (flag)
	{
		string name;
		string sfzh;
		int id;
		std::cout << "������Ҫ�޸�ѧ����ѧ��: ";
		std::cin >> id;
		std::cout << "������Ҫ�޸�ѧ��������: ";
		std::cin >> name;
		std::cout << "������Ҫ�޸�ѧ�������֤��: ";
		std::cin >> sfzh;
		sprintf(sql, "update xiaozhi set name = '%s',sfzh = '%s'" "where id = %d", name.c_str(), sfzh.c_str(), id);
		if (mysql_query(con, sql))
		{
			fprintf(stderr, "Failed to update to datebase : Error:%s\n", mysql_error(con));
		}
		else
		{
			std::cout << "�ɹ��޸ĸ�ѧ��" << std::endl;
		}
		std::cout << "�Ƿ�Ҫ�����޸�����? 0(NO)/1(YES): ";
		std::cin >> flag;
	}

}

void my_sql::my_delete()
{
	int flag = 1;

	while (flag)
	{
		string name;
		string sfzh;
		int id;
		std::cout << "������Ҫɾ��ѧ����ѧ��: ";
		std::cin >> id;
		sprintf(sql, "delete from xiaozhi where id = %d",id);
		if (mysql_query(con, sql))
		{
			fprintf(stderr, "Failed to delete to datebase : Error:%s\n", mysql_error(con));
		}
		else
		{
			std::cout << "�ɹ�ɾ����ѧ��" << std::endl;
		}
		std::cout << "�Ƿ�Ҫ����ɾ������? 0(NO)/1(YES): ";
		std::cin >> flag;
	}
}

void my_sql::my_find()
{
	int id = 0;
	std::cout << "������Ҫ����ѧ����ѧ��: ";
	std::cin >> id;
	sprintf(sql, "select * from xiaozhi where id = %d", id);
	if (mysql_query(con, sql))
	{
		fprintf(stderr, "Failed to find to datebase : Error:%s\n", mysql_error(con));
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;
	int num = 0;
	int i = 0;
	/*while ((row = mysql_fetch_row(res)) != NULL)
	{
		if (row[0] != NULL && row[1] != NULL && row[2] != NULL)
		{
			std::cout << "idΪ: " << atoi(row[0]) << " ";
			std::cout << "����Ϊ: " << row[1] << " ";
			std::cout << "���֤��Ϊ: " << row[2] << std::endl;
		}
		else
		{
			break;
		}
	}*/
	while ((row = mysql_fetch_row(res)))    // ���������
	{
		std::cout << "idΪ: " << atoi(row[0]) << " ";
		std::cout << "����Ϊ: " << row[1] << " ";
		std::cout << "���֤��Ϊ: " << row[2] << std::endl;
	}
}