#include <iostream>
#include "Board.h"

//ADD QUEENING
//ADD CASTLING
//ADD CHECK CHECKER
//ADD CHECKMATE CHECKER

void runGame(Board* board);
void move(Board* board, Color team, int turnCounter);

int main() 
{
	Board* board = new Board();
	runGame(board);
	return(EXIT_SUCCESS);
}

void move(Board* board, Color team, int turnCounter)
{
	bool moved = false;
	char startChar, destinationChar;
	int startLet, startNum, let, num;

	if (team == WHITE)
	{
		std::cout << "White ";
	} else
	{
		std::cout << "Black ";
	}
	std::cout << "team's turn." << std::endl;

	while (!moved)
	{
		std::cout << "Input LETTER NUMBER of piece to move: ";
		std::cin >> startChar;
		startChar = toupper(startChar);
		std::cin >> startNum;
		startLet = startChar - 'A' + 1;

		if ( startLet < ACOORD || startLet > HCOORD || 
			startNum < 1 || startNum > 8 || 
			!(board->getPieceAt(startLet, startNum)->isOnTeam(team)) )
		{
			std::cout << "Invalid starting coordinates. They must be on your team and on the board." << std::endl;
			continue;
		}

		std::cout << "Input LETTER NUMBER of destination: ";
		std::cin >> destinationChar;
		destinationChar = toupper(destinationChar);
		std::cin >> num;
		let = destinationChar - 'A' + 1;

		if (let < ACOORD || let > HCOORD ||
			num < 1 || num > 8 ||
			!(board->getPieceAt(startLet, startNum)->isOnTeam(team)))
		{
			std::cout << "Invalid ending coordinates. They must be on the board." << std::endl;
			continue;
		}

		moved = board->movePieceFromTo(startLet, startNum, let, num, board, turnCounter);
		if (!moved)
		{
			std::cout << "Invalid move." << std::endl;
		}
	}
}

void runGame(Board* board)
{
	int turnCounter = 1;
	bool checkMate = false; //replace with king checker
	while (!checkMate)
	{ 
		std::cout << "Turn: " << turnCounter << std::endl;
		board->printBoard();
		move(board, WHITE, turnCounter);
		board->printBoard();
		move(board, BLACK, turnCounter);
		turnCounter++;
	}
}