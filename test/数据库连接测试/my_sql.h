#pragma once
#include <mysql.h>
#include "other.h"
#include <vector>


class my_sql
{
public:

	my_sql();

	my_sql(const char* honst, const char* user, const char* pw, const char* database_name, const int port);

	~my_sql();

	void insert();

	void update();

	void my_delete();

	void my_find();

private:
	char sql[256];
	const char* host;
	const char* user;
	const char* pw;
	const char* database_name;
	const int port = 0;
	MYSQL* con = mysql_init(NULL);
};