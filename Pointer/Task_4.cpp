/*Используя указатели и оператор разыменования, определить наибольшее из двух чисел.*/

#include<iostream>

int max(int *number_1, int *number_2)
{
	return (*number_1 > *number_2) ? *number_1 : *number_2;
}

int main()
{
	int a = 10;
	int b = 100;
	int max_number = max(&a, &b);

	std::cout << "number_1 = " << a << std::endl;
	std::cout << "number_2 = " << b << std::endl;
	std::cout << "max number = " << max_number << std::endl;

	return 0;
}