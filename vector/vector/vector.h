#pragma once
#include <iostream>
class vector
{
public:
	vector();

	vector(int n);

	vector(vector& v);

	vector(vector&& v)noexcept;

	~vector();

	int operator[](int n);

	int my_size();

	int my_rongliang();

	void push_back(int n);

	void insert_fro(int n, int num);

	void insert_bac(int n, int sum);

	void pop();

	void earse(int n);

	void clear();

	bool empty();

	int back();

	int front();

	int at(int n);

	void erase(int n);

	void remove(int n);

	int find(int n);

private:
	size_t size = 0;
	int* vec = nullptr;
	int capacity = 8;
};

