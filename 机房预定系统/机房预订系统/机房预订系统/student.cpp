#include "student.h"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;

void student::see_com()
{
	fstream fstu;
	fstu.open(COMPUTER, std::ios::in);
	if (fstu)
	{
		cout << "this is open:" << endl;
	}
	else
	{
		cout << "this open error!" << endl;
		return;
	}
	string temp;
	while (fstu >> temp)
	{
		cout << temp << endl;
	}
	fstu.close();
}



void student::stu_book()
{





}

void student::see_book()
{




}

void student::cancle()
{


}

void teacher::see_com()
{
	fstream fstu;
	fstu.open(COMPUTER, std::ios::in);
	if (fstu)
	{
		cout << "this is open:" << endl;
	}
	else
	{
		cout << "this open error!" << endl;
		return;
	}
	string temp;
	while (fstu >> temp)
	{
		cout << temp << endl;
	}
	fstu.close();
}

void teacher::work_approve()
{



}

void root::add_student()
{



}

void root::add_teacher()
{




}

void root::dele_student()
{





}

void root::dele_teacher()
{





}