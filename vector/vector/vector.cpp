#include"vector.h"

vector::vector()
{
	std::cout << "vector 无参构造，size 为 0 ！" << std::endl;
	vec = new int[capacity];
	if (vec == nullptr)
	{
		std::cout << "构造失败" << std::endl;
	}
	else
	{
		std::cout << "现在vector容量为：" << capacity << std::endl;
	}
}

vector::vector(int n)
{
	std::cout << "vector的有参构造" << std::endl;
	size = n;
	while (capacity < n)
	{
		capacity *= 2;
	}
	vec = new int[capacity];
	if (vec == nullptr)
	{
		std::cout << "构造失败" << std::endl;
	}
}

vector::vector(vector& v)
{
	std::cout << "This is copy" << std::endl;
	size = v.size;
	capacity = v.capacity;
	int* vec = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		vec[i] = v.vec[i];
	}
	this->vec = vec;
	vec = nullptr;
	std::cout << "原来v的地址：" << v.vec << std::endl;
	std::cout << "新的v的地址: " << this -> vec << std::endl;
}

vector::vector(vector&& v)noexcept
{
	std::cout << "This is std::move()" << std::endl;
	size = v.size;
	capacity = v.capacity;
	vec = v.vec;
	v.vec = nullptr;
}

vector::~vector()
{
	std::cout << "vector de xigou hanshu" << std::endl;
	delete[] vec;
	vec = nullptr;
}

int vector::operator[](int n)
{
	return this->vec[n];
	
}

int vector::my_size()
{
	return size;
}

int vector::my_rongliang()
{
	return capacity;
}

void vector::push_back(int n)
{
	if (size >= capacity)
	{
		capacity *= 2;
		int* temp = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			temp[i] = vec[i];
		}
		temp[size] = n;
		delete[] vec;
		vec = temp;
		temp = nullptr;
		std::cout << "vec的新地址为：" << &vec << std::endl;
		std::cout << "成功在第" << size << "个位置插入" << n << std::endl;
		size++;
	}
	else
	{
		vec[size] = n;
		std::cout << "成功在第" << size << "个位置插入" << n << std::endl;
		size++;
	}
}

void vector::insert_fro(int n, int num)
{
	if (size >= capacity)
	{
		capacity *= 2;
		int* temp = new int[capacity];
		for (int i = 0; i < n; i++)
		{
			temp[i] = vec[i];
		}
		vec[n] = num;
		for (int i = n + 1; i < size + 1; i++)
		{
			temp[i] = vec[i - 1];
		}
		size++;
		std::cout << "成功在第" << n << "个位置插入" << num << std::endl;
	}
	else
	{
		for (int i = size + 1; i > n; i--)
		{
			vec[i] = vec[i - 1];
		}
		vec[n] = num;
		size++;
		std::cout << "成功在第" << n << "个位置插入" << num << std::endl;
	}
}

void vector::insert_bac(int n, int num)
{
	
}

void vector::pop()
{
	std::cout << "被删除的元素： " << vec[size - 1] << std::endl;
	vec[size - 1] = 0;
	std::cout << "原来size的大小：" << size << std::endl;
	size--;
	std::cout << "原来size的大小：" << size << std::endl;
}

void vector::earse(int n)
{
	for (int i = n; i < size; i++)
	{
		vec[i] = vec[i + 1];
	}
	vec[size - 1] = 0;
}

void vector::clear()
{
	std::cout << "使用clear()函数清空数组" << std::endl;
	for (int i = 0; i < size; i++)
	{
		vec[i] = 0;
	}
	size = 0;
}

bool vector::empty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

int vector::back()
{
	return vec[size - 1];
}

int vector::front()
{
	if (!(this->empty()))
	{
		return vec[0];
	}
	std::cout << "vector为空" << std::endl;
}

int vector::at(int n)
{
	if (n < size)
	{
		return vec[n];
	}
	std::cout << "下表超出范围" << std::endl;
}

void vector::erase(int n)
{
	std::cout << "第n个元素为: " << vec[n - 1];
	for (int i = n; i < size; i++)
	{
		vec[i - 1] = vec[i];
	}
	vec[size - 1] = 0;
	size--;
	std::cout << "第n个参数已被成功删除" << std::endl;
}

void vector::remove(int n)
{
	int temp = 0;
	for (int i = 0; i < size - temp; i++)
	{
		if (vec[i] == n)
		{
			temp++;
		}
		vec[i] = vec[i + temp];
	}
	std::cout << "共找到" << temp << "个" << n << std::endl;
	while (temp)
	{
		vec[size - 1] = 0;
		size--;
	}
}

int vector::find(int n)
{
	for (int i = 0; i < size; i++)
	{
		if (vec[i] == n)
		{
			return i;
		}
	}
	return -1;
}