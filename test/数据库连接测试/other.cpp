#include "other.h"
#include "my_sql.h"

student::student()
{
	std::cout << "����һ��ѧ��ing..." << std::endl;
	std::cout << "������ѧ��ѧ�ţ� ";
	std::cin >> student_id;
	std::cout << "������ѧ�������� ";
	std::cin >> student_name;
	std::cout << "������ѧ�����֤�ţ� ";
	std::cin >> student_sfzh;
	std::cout << "�Ѵ������..." << std::endl;
}

//student::student(int student_id, string student_name, string student_sfzh) :student_id(student_id), student_name(student_name), student_sfzh(student_sfzh)
//{
//	std::cout << "�Ѵ������..." << std::endl;
//}

void student::show_information()
{
	std::cout << "ѧ����ѧ�ţ� " << this->student_id;
	std::cout << "ѧ���������� " << this->student_name;
	std::cout << "ѧ�������֤�ţ� " << this->student_sfzh;
}

void show_con() 
{
	std::cout << "ѡ����Ҫ�������ݿ�ķ�ʽ�� " << std::endl;
	std::cout << "1. Ĭ�ϱ�������" << std::endl;
	std::cout << "2. ʹ���������ݿ�����" << std::endl;
}

void myprint_menu()
{
	std::cout << "���ݿ�������£�" << std::endl;
	std::cout << "1. ����ѧ����Ϣ" << std::endl;
	std::cout << "2. �޸�ѧ����Ϣ" << std::endl;
	std::cout << "3. ɾ��ѧ����Ϣ" << std::endl;
	std::cout << "4. ����ѧ����Ϣ" << std::endl;
	std::cout << "5. ��ʾ��¼��Ϣ" << std::endl;
	std::cout << "6. �˳����ݿ�" << std::endl;
}



