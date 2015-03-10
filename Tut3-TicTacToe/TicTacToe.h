#ifndef TICTACTOE_H
#define TICTACTOE_H

//#include <string>

class TicTacToe
{
private:
	char board[3][3];
	int currentPlayer;

public:
	TicTacToe();
	~TicTacToe();

	enum game_state{IN_PROGRESS, PLAYER1, PLAYER2, DRAW };
	void restart();
	bool move(int, int);
	void print();
	int isWon();
};
#endif
