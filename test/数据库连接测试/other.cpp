#include "other.h"
#include "my_sql.h"

student::student()
{
	std::cout << "构造一个学生ing..." << std::endl;
	std::cout << "请输入学生学号： ";
	std::cin >> student_id;
	std::cout << "请输入学生姓名： ";
	std::cin >> student_name;
	std::cout << "请输入学生身份证号： ";
	std::cin >> student_sfzh;
	std::cout << "已创建完成..." << std::endl;
}

//student::student(int student_id, string student_name, string student_sfzh) :student_id(student_id), student_name(student_name), student_sfzh(student_sfzh)
//{
//	std::cout << "已创建完成..." << std::endl;
//}

void student::show_information()
{
	std::cout << "学生的学号： " << this->student_id;
	std::cout << "学生的姓名： " << this->student_name;
	std::cout << "学生的身份证号： " << this->student_sfzh;
}

void show_con() 
{
	std::cout << "选择需要连接数据库的方式： " << std::endl;
	std::cout << "1. 默认本地连接" << std::endl;
	std::cout << "2. 使用其他数据库连接" << std::endl;
}

void myprint_menu()
{
	std::cout << "数据库操作如下：" << std::endl;
	std::cout << "1. 插入学生信息" << std::endl;
	std::cout << "2. 修改学生信息" << std::endl;
	std::cout << "3. 删除学生信息" << std::endl;
	std::cout << "4. 查找学生信息" << std::endl;
	std::cout << "5. 显示登录信息" << std::endl;
	std::cout << "6. 退出数据库" << std::endl;
}



