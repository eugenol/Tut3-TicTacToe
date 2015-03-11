// Tut3-TicTacToe.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main(/*int argc, char* argv[]*/)
{
	TicTacToe Game;
	int row, col;
	char answer;

	while (1) //Game Loop
	{
		while (Game.isWon() == TicTacToe::IN_PROGRESS)
		{
			system("cls");
			Game.print();
			cout << "Player " << Game.getPlayer() << ": Enter your move: row,column" << endl;
			cin >> row;
			cin.ignore(1);
			cin >> col;
			while (!Game.move(row - 1, col - 1))
			{
				cout << "Invalid Move" << endl;
				cout << "Player " << Game.getPlayer() << ": Enter your move: row,column" << endl;
				cin >> row;
				cin.ignore(1);
				cin >> col;
			}
		}

		system("cls");
		Game.print();

		if (Game.isWon() == TicTacToe::DRAW)
			cout << "The Game Was Drawn";
		else if (Game.isWon() == TicTacToe::PLAYER1)
			cout << "Player 1 Won!";
		else if (Game.isWon() == TicTacToe::PLAYER2)
			cout << "Player 2 Won!";
		cout << endl << endl;

		cout << "Would you like to play again ? (Y/N) > ";
		cin >> answer;
		
		if (answer == 'N' || answer == 'n')
			break;
		else if (answer == 'Y' || answer == 'y')
			Game.restart();
	}

	return 0;
}

