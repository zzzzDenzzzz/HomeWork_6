/*Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.*/

#include<iostream>

int GCD(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		return GCD(b, a - b);
	}
	else
	{
		return GCD(a, b - a);
	}
}

int main()
{
	int number_1 = 4398;
	int number_2 = 2964;

	int result = GCD(number_1, number_2);
	std::cout << "(" << number_1 << "," << number_2 << ") = " << result << std::endl;

	return 0;
}