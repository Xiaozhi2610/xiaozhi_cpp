#include <iostream>
#include <fstream>
#include "other.h"
#include "student.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;




int main()
{
	int select = 0;


	while (true)
	{
		mune();
		cin >> select;
		while (select < 0 || select > 3)
		{
			cout << "your set is mistake,please ste again: ";
			cin >> select;
		}
		switch (select)
		{
		case 1:
		{
			string account;
			cout << "Please set your name: ";
			cin >> account;
			string pw;
			cout << "Please set your password: ";
			cin >> pw;
			fstream fstu;
			fstu.open(COMPUTER, std::ios::in);


			
			system("cls");
			int flag = 1;
			while (flag)
			{
				stu_mune();
				cin >> flag;
				//student_mune(stu, flag);
			}	
		}

			break;
		case 2: 
		{
			system("cls");
			int flag = 1;
			teacher tea;
			while (flag)
			{
				tea_mune();
				cin >> flag;
				teacher_mune(tea, flag);
			}
		}
			

			break;

		case 3:

			break;
		case 0:
		{
			cout << "Welecome userd again..." << endl;
			return 0;
		}
		}
	}
}