/*»спользу€ указатели и оператор разыменовани€, определить знак числа, введЄнного с клавиатуры.*/

#include<iostream>

void inputNumber(int *a)
{
	std::cout << "Enter number: ";
	std::cin >> *a;
}

void func(int *number)
{
	if (*number == 0)
	{
		std::cout << "ZERO";
	}
	else if (*number < 0)
	{
		std::cout << "MINUS";
	}
	else
	{
		std::cout << "PLUS";
	}
}

int main()
{
	int a;
	inputNumber(&a);
	func(&a);

	return 0;
}