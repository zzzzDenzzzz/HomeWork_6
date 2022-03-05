/*Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число и играющий должен угадать его.
После ввода пользователем числа программа сообщает, сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы).
После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток. В программе необходимо использовать рекурсию.*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void randomNumber(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
		{
			array[i] = 1 + rand() % 9;
		}
		else
		{
			array[i] = rand() % 10;
		}
	}
}

int inputNumber()
{
	int number;
	while (true)
	{
		std::cout << "Введите число: ";
		std::cin >> number;
		if (number >= 1000 && number <= 9999)
		{
			return number;
		}
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!!!" << std::endl;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Oops!!!" << std::endl;
		}
	}
}

void printNumber(int array[], int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

void outputNumber(int number, int array[], int length_array)
{
	if (number == 0)
	{
		return;
	}
	array[length_array - 1] = number % 10;
	outputNumber(number / 10, array, length_array - 1);
}

bool game(int array_1[], int array_2[], int length_array)
{
	
	int counter_cows = 0;
	int counter_bulls = 0;
	int variable = 10;

	for (int i = 0; i < length_array; i++)
	{
		if (array_1[i] == array_2[i])
		{
			counter_cows++;
			array_2[i] += variable;
			array_1[i] += variable;
		}
	}

	for (int i = 0; i < length_array; i++)
	{
		for (int j = 0; j < length_array; j++)
		{
			if (array_1[i] == array_2[j] && array_2[j] >= variable)
			{
				continue;
			}
			else if (array_1[i] == array_2[j] && i != j)
			{
				array_1[i] += variable;
				counter_bulls++;
			}
		}
	}

	for (int i = 0; i < length_array; i++)
	{
		if (array_2[i] >= variable)
		{
			array_2[i] -= variable;
		}
	}
	std::cout << "быков - " << counter_bulls << std::endl;
	std::cout << "коров - " << counter_cows << std::endl;

	if (counter_cows == 4)
	{
		std::cout << "Вы угадали число!!!" << std::endl;
		return true;
	}
	return false;
}

int main()
{
	SetConsoleOutputCP(1251);
	srand((unsigned int)time(NULL));

	const int LENGTH = 4;
	int random_number[LENGTH];
	randomNumber(random_number, LENGTH);

	bool game_over = false;
	int counter = 0;

	while (!game_over)
	{
		int number = inputNumber();

		int gamer_number[LENGTH];
		outputNumber(number, gamer_number, LENGTH);

		//printNumber(random_number, LENGTH);
		game_over = game(gamer_number, random_number, LENGTH);
		std::cout << "Количество попыток: " << ++counter << std::endl << std::endl;
	}
	
	return 0;
}