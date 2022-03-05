/*Написать рекурсивную функцию нахождения степени числа.*/

#include<iostream>

template<typename T>
T myPow(T number, int degree)
{
	if (degree == 0)
	{
		return 1;
	}
	return number * myPow(number, degree - 1);
}

template<typename T>
void printResult(T number, T result, int degree)
{
	std::cout << number << "^" << degree << "=" << result << std::endl;
}

int main()
{
	int number = 2;
	int degree = 7;
	int result = myPow(number, degree);
	printResult(number, result, degree);

	return 0;
}