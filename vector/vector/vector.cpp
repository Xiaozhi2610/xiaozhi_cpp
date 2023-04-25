#include"vector.h"

vector::vector()
{
	std::cout << "vector 无参构造，size 为 0 ！" << std::endl;
	vec = new int[capacity];
	std::cout << "现在vector容量为：" << capacity << std::endl;
}

vector::vector(int n)
{
	if (n == 0)
	{
		std::cout << "参数\"n\"不能为 0 ,构造失败 ！" << std::endl;
	}
	else
	{
		std::cout << "vector的有参构造" << std::endl;
		size = n;
		while (capacity < n)
		{
			capacity *= 2;
		}
		vec = new int[capacity];
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

vector vector::operator[](int n)
{
	return this->vec[n];
}

ostream& vector::operator<<(int n)
{

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

void vector::insert(int n, int num)
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