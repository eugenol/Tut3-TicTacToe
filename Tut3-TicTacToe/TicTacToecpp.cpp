#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	currentPlayer = PLAYER1;;
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::restart()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}

	currentPlayer = PLAYER1;;
}

bool TicTacToe::move(int row, int col)
{
	if (board[row][col] != ' ' || row > 2 || row < 0 || col > 3 || col < 0)
	{
		return false;
	}
	else
	{
		if (currentPlayer == PLAYER1)
		{
			board[row][col] = 'X';
			currentPlayer = PLAYER2;
		}
		else
		{
			board[row][col] = 'O';
			currentPlayer = PLAYER1;
		}
		return true;
	}
}

void TicTacToe::print()
{
	cout << " | 1 | 2 | 3" << endl;
	cout << "1| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "2| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "3| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

int TicTacToe::isWon()
{
	int player1_r = 0, player2_r = 0, player1_c = 0, player2_c = 0;
	int player1_d1 = 0, player2_d1 = 0, player1_d2 = 0, player2_d2 = 0;
	int empty = 0;

	//check rows
	for (int i = 0; i < 3; i++)
	{
		player1_r = player2_r = 0;

		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
				++player1_r;
			else if (board[i][j] == 'O')
				++player2_r;
			else
				++empty;
		}

		if (player1_r == 3)
			return PLAYER1;
		else if (player2_r == 3)
			return PLAYER2;
	}

	//check columns
	for (int i = 0; i < 3; i++)
	{
		player1_c = player2_c = 0;

		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == 'X')
				++player1_c;
			else if (board[j][i] == 'O')
				++player2_c;
		}

		if (player1_c == 3)
			return PLAYER1;
		else if (player2_c == 3)
			return PLAYER2;
	}

	//check diagonal 1
	player1_d1 = player2_d1 = 0;
	for (int i = 0; i < 3; i++)
	{

		if (board[i][i] == 'X')
			++player1_d1;
		else if (board[i][i] == 'O')
			++player2_d1;
	}

	if (player1_d1 == 3)
		return PLAYER1;
	else if (player2_d1 == 3)
		return PLAYER2;

	//check diagonal 2
	player1_d2 = player2_d2 = 0;
	for (int i = 0; i < 3; i++)
	{

		if (board[2-i][i] == 'X')
			++player1_d2;
		else if (board[2-i][i] == 'O')
			++player2_d2;
	}

	if (player1_d2 == 3)
		return PLAYER1;
	else if (player2_d2 == 3)
		return PLAYER2;

	if (empty == 0)
		return DRAW;

	return IN_PROGRESS;
}


