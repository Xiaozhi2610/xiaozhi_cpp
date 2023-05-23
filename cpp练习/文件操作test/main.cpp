#pragma warning(disable:4996)
#include <list>
#include <vector>
#include<stdio.h>
int main()
{
	int a[3], t;
	for (int i = 0; i < 3; i++)
		scanf("%d", &a[i]);
	if (a[0] > a[1])
	{
		t = a[0];
		a[0] = a[1];
		a[1] = t;
	}
	if (a[0] > a[2])
	{
		t = a[0];
		a[0] = a[2];
		a[2] = t;
	}
	if (a[1] > a[2])
	{
		t = a[1];
		a[1] = a[2];
		a[2] = t;
	}
	getchar();
	getchar();
	char c[3];
	for (int i = 0; i < 3; i++)
		c[i] = getchar();
	for (int i = 0; i < 3; i++)
	{
		if (c[i] == 'A')
			printf("%d ", a[0]);
		if (c[i] == 'B')
			printf("%d ", a[1]);
		if (c[i] == 'C')
			printf("%d ", a[2]);
	}
	return 0;
}