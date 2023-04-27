#pragma once
#include <iostream>
class vector
{
public:
	vector();
	/*{
		std::cout << "vector 无参构造，size 为0！" << std::endl;
		vec = new int[rongliang];
		std::cout << "现在vector容量为：" << rongliang << std::endl;
	}*/

	vector(int n);
	/*{
		std::cout << "vector的有参构造" << std::endl;
		size = n;
		while (rongliang < n)
		{
			rongliang *= 2;
		}
		vec = new int[rongliang];
	}*/

	vector(vector& v);
	/*{
		std::cout << "This is copy" << std::endl;
		size = v.size;
		rongliang = v.rongliang;
		int* vec = new int[rongliang];
		for (int i = 0; i < size; i++)
		{
			vec[i] = v.vec[i];
		}
		std::cout << "原来v的地址：" << v.vec << std::endl;
		std::cout << "新的v的地址: " << vec << std::endl;
	}*/

	vector(vector&& v)noexcept;
	/*{
		std::cout << "This is std::move()" << std::endl;
		size = v.size;
		rongliang = v.rongliang;
		vec = v.vec;
		v.vec = nullptr;
	}*/

	~vector();

	int operator[](int n);

	//std::ostream& operator<<(int n);

	int my_size();
	/*{
		return size;
	}*/

	int my_rongliang();
	/*{
		return rongliang;
	}*/

	void push_back(int n);
	/*{
		if (size + 1 >= rongliang)
		{
			rongliang *= 2;
			int* temp = new int[rongliang];
			for (int i = 0; i < size; i++)
			{
				temp[i] = vec[i];
			}
			temp[size] = n;
			size++;
			delete[] vec;
			vec = temp;
			temp = nullptr;
			std::cout << "vec的新地址为：" << &vec << std::endl;
			std::cout << "成功在第" << size << "个位置插入" << n << std::endl;
		}
		else
		{
			vec[size] = n;
			size++;
			std::cout << "成功在第" << size << "个位置插入" << n << std::endl;
		}
	}*/

	void insert(int n, int num);
	/*{
		if (size + 1 >= rongliang)
		{
			rongliang *= 2;
			int* temp = new int[rongliang];
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
	}*/

	void pop();
	/*{
		std::cout << "被删除的元素： " << vec[size - 1] << std::endl;
		vec[size - 1] = 0;
		std::cout << "原来size的大小：" << size << std::endl;
		size--;
		std::cout << "原来size的大小：" << size << std::endl;
	}*/

	void earse(int n);
	/*{
		for (int i = n; i < size; i++)
		{
			vec[i] = vec[i + 1];
		}
		vec[size - 1] = 0;
	}*/

private:
	size_t size = 0;
	int* vec = nullptr;
	int capacity = 8;
};

