/*»спользу€ указатель на массив целых чисел, изменить пор€док следовани€ элементов массива на противоположный.
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

void modArray(int *array, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		int variable = *(array + i);
		*(array + i) = *(array + length - 1 - i);
		*(array + length - 1 - i) = variable;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 10;
	int array[LENGTH];
	int *ptr_array = array;
	initArray(ptr_array, LENGTH);
	printArray(ptr_array, LENGTH);
	modArray(ptr_array, LENGTH);
	printArray(ptr_array, LENGTH);

	return 0;
}