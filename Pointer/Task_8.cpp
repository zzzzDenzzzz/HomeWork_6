/*»спользу€ указатель на массив целых чисел, посчитать сумму элементов массива.
»спользовать в программе арифметику указателей дл€ продвижени€ по массиву, а также оператор разыменовани€.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

void initArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(array + i) = 1 + rand() % 9;
	}
}

void printArray(int *array, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
}

void sumArray(int *array, int length, int *sum)
{
	for (int i = 0; i < length; i++)
	{
		*sum += *(array + i);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 10;
	int arr[LENGTH];
	initArray(arr, LENGTH);
	printArray(arr, LENGTH);

	int result = 0;
	sumArray(arr, LENGTH, &result);
	std::cout << "sum = " << result;

	return 0;
}