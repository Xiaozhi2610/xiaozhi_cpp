#include "other.h"
#include <iostream>

using std::cout;
using std::endl;


void mune()
{
	cout << "============== xiaozhi_Computer room reservation system ==============" << endl;
	cout << "\t\t------------------------------------" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|         1. I'm student           |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|         2. I'm teacher           |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|         3. I'm root              |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|         0. Exit                  |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t|                                  |" << endl;
	cout << "\t\t------------------------------------" << endl;
	cout << "Please select your identity: ";
}

void stu_mune()
{
	cout << "============== xiaozhi_Computer room reservation system ==============" << endl;
	cout << "\t\t-------------------------------------" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         1. See computoer room     |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         2. I will booking         |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         3. Visit my booking       |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         4. Visit booking          |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         5. Cancle booking         |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         0. Exit                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t-------------------------------------" << endl;
	cout << "Please selest your choose: ";
}

void tea_mune()
{
	cout << "============== xiaozhi_Computer room reservation system ==============" << endl;
	cout << "\t\t-------------------------------------" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         1. See computoer room     |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         2. I will booking         |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         3. Visit my booking       |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         4. Visit booking          |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         5. Cancle booking         |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|         0. Exit                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t|                                   |" << endl;
	cout << "\t\t-------------------------------------" << endl;
	cout << "Please selest your choose: ";
}

void student_mune(student& stu,int flag)
{
	switch (flag)
	{
	case 1:
	{
		stu.see_com();
		system("pause");
		system("cls");
	}
	break;
	case 2:
	{

	}
	break;
	case 3:
	{

	}
	break;
	case 4:
	{

	}
	break;
	case 5:
	{

	}
	break;
	case 0:
	{
		system("cls");
	}
	}
}

void teacher_mune(teacher& tea, int flag)
{
	switch (flag)
	{
	case 1:
	{
		tea.see_com();
		system("pause");
		system("cls");
	}
	break;
	case 2:
	{

	}
	break;
	case 3:
	{

	}
	break;
	case 4:
	{

	}
	break;
	case 5:
	{

	}
	break;
	case 0:
	{
		system("cls");
	}
	}
}