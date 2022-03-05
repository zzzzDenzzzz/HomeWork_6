/*»спользу€ указатели и оператор разыменовани€, обмен€ть местами значени€ двух переменных.*/

#include<iostream>

void swap(int *a, int *b)
{
	int variable = *a;
	*a = *b;
	*b = variable;
}

void print(int *a, int *b)
{
	std::cout << "a = " << *a << " ";
	std::cout << "b = " << *b;
	std::cout << std::endl;
}

int main()
{
	int a = 178;
	int b = 253;
	print(&a, &b);
	swap(&a, &b);
	print(&a, &b);

	return 0;
}