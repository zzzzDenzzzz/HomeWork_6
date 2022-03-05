/*»спользу€ два указател€ на массив целых чисел, скопировать один массив в другой.
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

void copy(int *array_1, int *array_2, int length)
{
	for (int i = 0; i < length; i++)
	{
		*(array_2 + i) = *(array_1 + i);
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	const int LENGTH = 10;
	int array_1[LENGTH];
	int *ptr_array_1 = array_1;
	initArray(ptr_array_1, LENGTH);
	printArray(ptr_array_1, LENGTH);

	int array_2[LENGTH];
	int *ptr_array_2 = array_2;

	copy(ptr_array_1, ptr_array_2, LENGTH);

	printArray(ptr_array_2, LENGTH);

	return 0;
}