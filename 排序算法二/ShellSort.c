#include<stdio.h>
#include<Windows.h>
#include<time.h>

void swap(int *p, int *q)
{
	int *tmp = *p;
	*p = *q;
	*q = tmp;
}

void ShellSort2(int array[], int gap, int size)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (k = gap; k > 0; k--)
	{
		for (i = 0; i < size; i++)
		{
			j = i + k;
			if ((j<size) && (array[i]>array[j]))
				swap(&array[i], &array[j]);
		}
	}
}

void ShellSort1(int array[], int gap,int size)
{
	int i = 0;
	int j = 0;
	int tmp;
	for (int k = gap; k > 0; k--)
	{
		for (i = k; i < size; i += k)
		{
			j = i - k;
			tmp = array[i];
			while ((j>=0)&&(array[j]>tmp))
			{
				array[j + k] = array[j];
				j -= k;
			}
			array[j + k] = tmp;
		}
	}
}

void test()
{
	int array[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	int gap = size / 3 + 1;
	ShellSort2(array, gap,size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}

}

int main()
{
	test();
	system("pause");
	return 0;
}