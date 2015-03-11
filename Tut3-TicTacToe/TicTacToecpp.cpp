#include <iostream>
#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
{
	//Initialize the board, set all squares blank, set player to player 1
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
	//clear the board: set all squares blank, set player to player 1
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
		return false; // Invalid move
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
	cout << " | 1 | 2 | 3 |" << endl;
	cout << "1| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << endl;
	cout << "2| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << endl;
	cout << "3| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << endl << endl;
}

int TicTacToe::isWon()
{
	int player1 = 0, player2 = 0, empty = 0;

	//check rows
	for (int i = 0; i < 3; i++)
	{
		player1 = player2 = 0;

		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
				++player1;
			else if (board[i][j] == 'O')
				++player2;
			else
				++empty;
		}

		if (player1 == 3)
			return PLAYER1;
		else if (player2 == 3)
			return PLAYER2;
	}

	//check columns
	for (int i = 0; i < 3; i++)
	{
		player1 = player2 = 0;

		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == 'X')
				++player1;
			else if (board[j][i] == 'O')
				++player2;
		}

		if (player1 == 3)
			return PLAYER1;
		else if (player2 == 3)
			return PLAYER2;
	}

	//check diagonal 1
	player1 = player2 = 0;
	for (int i = 0; i < 3; i++)
	{

		if (board[i][i] == 'X')
			++player1;
		else if (board[i][i] == 'O')
			++player2;
	}

	if (player1 == 3)
		return PLAYER1;
	else if (player2 == 3)
		return PLAYER2;

	//check diagonal 2
	player1 = player2 = 0;
	for (int i = 0; i < 3; i++)
	{

		if (board[2-i][i] == 'X')
			++player1;
		else if (board[2-i][i] == 'O')
			++player2;
	}

	if (player1 == 3)
		return PLAYER1;
	else if (player2 == 3)
		return PLAYER2;

	if (empty == 0)
		return DRAW;

	return IN_PROGRESS;
}


