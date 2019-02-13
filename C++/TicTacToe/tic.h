#pragma once
#include<string>

using namespace std;

enum status { Win, Draw, Continue };

struct playerType
{
	int numOfWins = 0;
	char symbol;
	string name;
};

class ticTacToe 
{
	public:
		void play();

		void displayBoard() const;

		bool isValidMove(int x, int y) const;

		status getXOMove(char moveSymbol);

		status gameStatus();

		void restart();

	private:
		char board[3][3];
		int noOfMoves;
		playerType players[2];
};