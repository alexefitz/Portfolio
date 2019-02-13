#include<iostream>
#include<iomanip>
#include<Windows.h>
#include"tic.h"

using namespace std;

void ticTacToe::play() //only function to be called in main file, dependent on every other function
{
	status done = Continue;
	char player = 'X';
	char temp;

	//makes sure board is clear before starting program
	restart();

	//input to get both players' names, stores in user-defined list
	cout << "Player 1, what is your name? ";
	cin >> players[0].name;
	cout << "\n";

	cout << "Player 2, what is your name? ";
	cin >> players[1].name;
	cout << "\n";
	{
		cout << players[0].name << ", what symbol would you like to be? (X/O): ";
		cin >> temp;
		cout << "\n";
	} while (toupper(temp) != 'X' && toupper(temp) != 'O');

	if (toupper(temp) == 'X')
	{
		players[0].symbol = 'X';
		players[1].symbol = 'O';
	}
	else
	{
		players[0].symbol = 'O';
		players[1].symbol = 'X';
	}

	//checkpoint, loops back to this point when someone wants to play again.
playAgain:
	displayBoard();

	while (done == Continue)
	{
		//calls function to ask player for what square they would like to select
		done = getXOMove(player);

		if (done != Continue)
		{
			//increments score based on who won the round
			if(done == Win)
				if (players[0].symbol == player)
					players[0].numOfWins++;
				else if (players[1].symbol == player)
					players[1].numOfWins++;
			//prints out player data
			cout << players[0].name << "- " << players[0].numOfWins << "\n";
			cout << players[1].name << "- " << players[1].numOfWins << "\n\n";

			//displays game status
			if (players[0].numOfWins > players[1].numOfWins)
				cout << players[0].name << " is winning!\n";
			else if (players[1].numOfWins > players[0].numOfWins)
				cout << players[1].name << " is winning!\n";
			else
				cout << "Players are tied!\n";

			cout << "\n";
			break;
		}//end if

		//acts as a player count
		if (player == 'X')
			player = 'O';
		else
			player = 'X';
	}

	//makes sure user enters correct input
	do
	{
		cout << "Would you like to restart? (y/n): ";
		cin >> temp;

		if (toupper(temp) != 'N' && toupper(temp) != 'Y')
			cout << "Invalid response. \n";
		else if (toupper(temp) == 'Y')
			break;

	} while (toupper(temp) != 'N');

	//if users want to play again, board is reset, one-way flag is set back to false,
	//then code jumps back up to checkpoint
	if (toupper(temp) == 'Y')
	{
		restart();
		done = Continue;
		goto playAgain;
	}

}

//displays board
void ticTacToe::displayBoard() const 
{
	cout << " 1    2    3 \n\n"; 

	for (int row = 0; row < 3; row++)
	{
		cout << row + 1;

		for (int col = 0; col < 3; col++)
		{
			cout << setw(3) << board[row][col];
			if (col != 2)
				cout << " |";
		}//end inner for col loop
		cout << "\n";
		if (row != 2)
			cout << " ____|____|___\n"
			<< "     |    |    \n";
	}//end outer row loop
	cout << "\n";
}

//checks if user selected a real square and if the square is not taken
bool ticTacToe::isValidMove(int row, int col) const 
{
	if (0 <= row && row <= 2 && 0 <= col && col <= 2 && board[row][col] == ' ')
		return true;
	else
		return false;
}

//takes user input
status ticTacToe::getXOMove(char playerSymbol) 
{
	int row, col;
	do 
	{
		if (players[0].symbol == playerSymbol)
		{
			cout << players[0].name << ", Enter row: ";
			cin >> row;
			cout << "\n";

			cout << players[0].name << ", Enter column: ";
			cin >> col;
			cout << "\n";
		}//end if
		else
		{
			cout << players[1].name << ", Enter row: ";
			cin >> row;
			cout << "\n";

			cout << players[1].name << ", Enter column: ";
			cin >> col;
			cout << "\n";
		}//end else
	} while (!isValidMove(row - 1, col - 1));

	row--;
	col--;

	noOfMoves++;

	board[row][col] = playerSymbol;
	displayBoard();

	//sets game status, as well as displays who has won the game 
	status gStatus = gameStatus();
	if (gStatus == Win) 
	{
		if (players[0].symbol == playerSymbol)
		{
			cout << players[0].name << " wins!\n\n";
		}
		else
		{
			cout << players[1].name << " wins!\n\n";
		}
		return Win;
	}//end if
	else if (gStatus == Draw) 
	{
		cout << "This game is a draw!\n";
		return Draw;
	}
	else
		return Continue;
}
//checks game status
status ticTacToe::gameStatus() 
{
	for (int row = 0; row < 3; row++)
		if (board[row][0] != ' ' && (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]))
			return Win;

	for (int col = 0; col < 3; col++)
		if (board[0][col] != ' ' && (board[0][col] == board[1][col]) && (board[1][col] == board[2][col]))
			return Win;

	if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		return Win;

	if (board[2][0] != ' ' && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
		return Win;

	if (noOfMoves < 9)
		return Continue;
	return Draw;
}

//clears board of all selections and sets each square back to blank
void ticTacToe::restart() 
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			board[row][col] = ' ';
	noOfMoves = 0;
}
