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
		//while (Game.isWon() == TicTacToe::IN_PROGRESS)
		//{
			Game.print();
			cout << "Enter your coordinates r c";
			
			cin >> row >> col;
			Game.move(row-1, col-1);
			Game.print();
			cout << "Enter your coordinates r c";
			cin >> row >> col;
			Game.move(row-1, col-1);
			Game.print();

		//}
	//}

	return 0;
}

