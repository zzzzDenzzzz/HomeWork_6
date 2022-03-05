/*Написать рекурсивную функцию, которая вычисляет сумму всех чисел в диапазоне от a до b.
Пользователь вводит a и b. Проиллюстрируйте работу функции примером.*/

#include<iostream>

int enterNumber()
{
	int number;
	std::cout << "Enter number: ";
	std::cin >> number;
	return number;
}

void printResult(int result)
{
	std::cout << "result = " << result << std::endl;
}

int sum(int a, int b)
{
	if (a == b)
	{
		return b;
	}
	if (a < b)
	{
		return a + sum(a + 1, b);
	}
	else
	{
		return b + sum(b + 1, a);
	}
}

int main()
{
	int a = enterNumber();
	int b = enterNumber();
	int result = sum(a, b);
	printResult(result);

	return 0;
}