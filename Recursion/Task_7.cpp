/*Напишите рекурсивную функцию, которая принимает одномерный массив из 100 целых чисел, заполненных случайным образом,
и находит позицию, с которой начинается последовательность из 10 чисел, сумма которых минимальна.*/

#include <iostream>
#include <random>
#include <chrono>
#include <stdlib.h>

int position;
const int LENGTH = 100;

int minSumTen(int array[LENGTH], int current_postition = 0)
{
    int sum = 0;
    for (int i = current_postition; i < current_postition + 10; i++)
    {
        sum += array[i];
    }
    if (current_postition < 10)
    {
        std::cout << "current position:  " << current_postition << "; sum: " << sum << std::endl;
    }
    else
    {
        std::cout << "current position: " << current_postition << "; sum: " << sum << std::endl;
    }

    if (LENGTH - current_postition == 10)
    {
        position = current_postition;
        return sum;
    }
    else
    {
        int sum_1 = minSumTen(array, current_postition + 1);
        if (sum <= sum_1)
        {
            position = current_postition;
            return sum;
        }
        else
        { 
            return sum_1;
        }
    }
}

int main()
{
    std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> rnd(-99, 99);

    int array[LENGTH];
    for (int i = 0; i < LENGTH; ++i) 
    { 
        array[i] = rnd(generator);
    }
    for (int i = 0; i < LENGTH; ++i) 
    { 
        if (array[i] >= 0 && array[i] < 10)
        {
            std::cout << "  ";
        }
        if (array[i] >= 10)
        {
            std::cout << " ";
        }
        if (array[i] < 0 && array[i] > -10)
        {
            std::cout << " ";
        }
        std::cout << array[i] << ' ';
        if ((i + 1) % 10 == 0 && i != 0)
        {
            std::cout << ::std::endl;
        }
    }
    std::cout << std::endl << std::endl;

    minSumTen(array);

    std::cout << std::endl;
    std::cout << "Minimum position: " << position << std::endl << std::endl;

    return 0;
}