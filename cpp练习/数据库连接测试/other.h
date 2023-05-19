#pragma once
#include <iostream>
#include <string>
#include "my_sql.h"
using std::string;



class student
{
public:
	student();

	/*student(int student_id, string student_name, string student_sfzh);*/

	void show_information();


public:
	int student_id;
	string student_name;
	string student_sfzh;
};

void show_con();

void myprint_menu();

