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
			currentPlayer = PLAYER2;
		}
		return true;
	}
}

void TicTacToe::print()
{
	cout << " | 1 | 2 |3" << endl;
	cout << "1| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "2| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "2| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

int TicTacToe::isWon()
{
	bool p1flag = false, p2flag = false, drawflag = false;

	for (int i = 0; i < 3; i++)
	{
		p1flag = false;
		p2flag = false;
		drawflag = true;

		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
			{
				p1flag = true;
				p2flag = false;
			}
			else if (board[i][j] == 'O')
			{
				p1flag = false;
				p2flag = true;
			}
			else
			{
				p1flag = false;
				p2flag = false;
			}
		}
		if (p1flag)
			return PLAYER1;
		else if (p2flag)
			return PLAYER2;


	}
	return TicTacToe::IN_PROGRESS;
}


