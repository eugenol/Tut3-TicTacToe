// Tut3-TicTacToe.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main(/*int argc, char* argv[]*/)
{
	TicTacToe Game;
	int row, col;

	//while (1) //Game Loop
	//{
		while (Game.isWon() == TicTacToe::IN_PROGRESS)
		{
			Game.print();
			cout << "Player " << Game.getPlayer() << ". Enter your move: r,c" << endl;
			cin >> row;
			cin.ignore(1);
			cin >> col;
			Game.move(row-1, col-1);
			cout << endl;

		}

		if (Game.isWon() == TicTacToe::DRAW)
			cout << "Game Drawn";
		else if (Game.isWon() == TicTacToe::PLAYER1)
			cout << "Player 1 Won";
		else if (Game.isWon() == TicTacToe::PLAYER2)
			cout << "Player 2 Won";
		cout << endl;
	//}

	return 0;
}

