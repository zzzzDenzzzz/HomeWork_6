/*Дана шахматная доска размером 8х8 и шахматный конь. Программа должна запросить у пользователя координаты клетки поля и поставить туда коня.
Задача программы найти и вывести путь коня, при котором он обойдет все клетки доски, становясь в каждую клетку только один раз.
(Так как процесс отыскания пути для разных начальных клеток может затянуться, 
то рекомендуется сначала опробовать задачу на поле размером 6х6). В программе необходимо использовать рекурсию.*/

#include <iostream>
#include<Windows.h>

const int SIZE_BOARD = 8;
int chessboard[SIZE_BOARD][SIZE_BOARD]{ 0 };

const int MOVE = 8;
const int COORDINATE = 2;
int knights_move[MOVE][COORDINATE]
{
	{ 1, -2},
	{ 2, -1},
	{ 2,  1},
	{ 1,  2},
	{-1,  2},
	{-2,  1},
	{-2, -1},
	{-1, -2}
};

int rating_board[SIZE_BOARD][SIZE_BOARD]
{
	{2, 3, 4, 4, 4, 4, 3, 2},
	{3, 4, 6, 6, 6, 6, 4, 3},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{4, 6, 8, 8, 8, 8, 6, 4},
	{3, 4, 6, 6, 6, 6, 4, 3},
	{2, 3, 4, 4, 4, 4, 3, 2}
};

void printBoard()
{
	for (int i = 0; i < SIZE_BOARD; i++)
	{
		for (int j = 0; j < SIZE_BOARD; j++)
		{
			if (chessboard[i][j] < 10)
			{
				std::cout << " ";
			}
			std::cout << chessboard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int count_move = 0;
int count_operation = 0;

bool knightsMove(int x, int y)
{
	if ((x < 0) || (x >= SIZE_BOARD) || (y < 0) || (y >= SIZE_BOARD))
	{
		return false;
	}

	if (chessboard[x][y] != 0)
	{
		return false;
	}

	chessboard[x][y] = ++count_move;
	count_operation++;

	if (count_move == SIZE_BOARD * SIZE_BOARD)
	{
		return true;
	}

	int variable;
	int min;
	int best_step = 0;
	bool flag = false;
	for (int i = 0; i < MOVE; i++)
	{
		if (x + knights_move[i][0] >= 0 && x + knights_move[i][0] < SIZE_BOARD &&
			y + knights_move[i][1] >= 0 && y + knights_move[i][1] < SIZE_BOARD &&
			chessboard[x + knights_move[i][0]][y + knights_move[i][1]] == 0)
		{
			if (flag == false)
			{
				min = rating_board[x + knights_move[i][0]][y + knights_move[i][1]];
				best_step = i;
				flag = true;
			}
			
			variable = rating_board[x + knights_move[i][0]][y + knights_move[i][1]];

			if (variable < min)
			{
				best_step = i;
				min = variable;
			}
		}
	}

	for (int i = best_step; i < MOVE; i++)
	{
		if (knightsMove(x + knights_move[i][0], y + knights_move[i][1]))
		{
			return true;
		}
	}
	
	count_move--;
	count_operation++;
	chessboard[x][y] = 0;

	return false;
}

int main()
{	
	int x = 0;
	int y = 7;
	knightsMove(x, y);
	printBoard();
	std::cout << std::endl;
	std::cout << "(" << x << " , " << y << ") ";
	std::cout << "counter operation = " << count_operation << std::endl;

	return 0;
}