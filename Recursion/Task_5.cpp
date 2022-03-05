/*Написать рекурсивную функцию, которая выводит N звезд в ряд, число N задает пользователь.
Проиллюстрируйте работу функции примером.*/

#include<iostream>

void printStars(int number_stars)
{
	if (number_stars <= 0)
	{
		return;
	}
	else
	{
		std::cout << "*";
		printStars(number_stars - 1);
	}
}

int inputNumberStars()
{
	int number_stars;
	std::cout << "Enter number stars: ";
	std::cin >> number_stars;
	return number_stars;
}

int main()
{
	int number_stars = inputNumberStars();
	printStars(number_stars);
	std::cout << std::endl;

	return 0;
}