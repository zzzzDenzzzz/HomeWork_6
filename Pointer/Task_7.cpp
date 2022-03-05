/*Написать примитивный калькулятор, пользуясь только указателями.*/

#include<iostream>

void inputNumber(double *number)
{
	std::cout << "Enter number: ";
	std::cin >> *number;
}

void inputOperation(char *operation)
{
	std::cout << "Enter operation(+, -, /, *): ";
	std::cin >> *operation;
}

void outputResult(double *number_1, char *operation, double *number_2 , double *result)
{
	switch (*operation)
	{
	case '+':
		*result = *number_1 + *number_2;
		break;
	case '-':
		*result = *number_1 - *number_2;
		break;
	case '/':
		*result = *number_1 / *number_2;
		break;
	case '*':
		*result = *number_1 * *number_2;
		break;
	default:
		break;
	}
}

int main()
{
	double a;
	inputNumber(&a);

	char op;
	inputOperation(&op);

	double b;
	inputNumber(&b);

	double result;
	outputResult(&a, &op, &b, &result);
	
	std::cout << a << " " << op << " " << b << " = " << result << std::endl;

	return 0;
}