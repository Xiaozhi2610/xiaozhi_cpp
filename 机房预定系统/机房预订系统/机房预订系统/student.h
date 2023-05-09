#pragma once
#define STUDENT "student.txt"
#define TRECHAR "teacher.txt"
#define ROOT "root.txt"
#define COMPUTER "computer.txt"

#include <string>


using std::string;


class person
{

public:
	string account;
	string pw;
};

class student:public person
{
public:
	void see_com();//over

	void stu_book();

	void see_book();

	void cancle();

public:
	int stu_class;
	int age;
	string name;
	string group;
};

class teacher :public person
{
public:

	void see_com();

	void work_approve();

public:
	string name;
	string group;
	long long salary;
};

class root :public person
{
public:

	void add_student();

	void add_teacher();

	void dele_student();

	void dele_teacher();


public:
	string user_name;
};

class computer
{



public:
	int com_class[3];
	int com_seat[30];
};