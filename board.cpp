#include <iostream>
#include "Board.h"

void Board::addPiece(int let, int num, Piece* piece)
{
	game[num][let] = piece;
}

void Board::printBoard()
{
	std::cout << "  ";
	for (char i = 'A'; i <= 'H'; i++)
	{
		std::cout << i << " " << " ";
	}

	std::cout << std::endl;

	for (int num = 8; num >= 1; num--)
	{
		std::cout << num << " ";
		for (int let = ACOORD; let <= HCOORD; let++)
		{
			game[num][let]->display();
		}
		std::cout << num << std::endl;
	}

	std::cout << "  ";
	for (char i = 'A'; i <= 'H'; i++)
	{
		std::cout << i << " " << " ";
	}

	std::cout << std::endl;
}

void Board::setToEmpty(int let, int num)
{
	game[num][let] = empty;
}

Piece * Board::getPieceAt(int let, int num)
{
	return game[num][let];
}

bool Board::movePieceFromTo(int startLet, int startNum, int let, int num, Board * board, int turnCounter)
{
	if (game[startNum][startLet]->canMoveFromTo(startLet, startNum, let, num, this, turnCounter))
	{
		//perhaps make the pieces change the places?????
		game[num][let] = game[startNum][startLet];
		game[startNum][startLet] = empty;
		return true;
	}
	return false;
}

/*
bool Board::isOnTeam(int startLet, int startNum, Color team)
{
	return game[startNum][startLet]->isOnTeam(team);
}
*/

Board::Board()
{
	empty = new Empty();

	rookBlack = new Rook(BLACK);
	knightBlack = new Knight(BLACK);
	bishopBlack = new Bishop(BLACK);
	queenBlack = new Queen(BLACK);
	kingBlack = new King(BLACK);

	rookWhite = new Rook(WHITE);
	knightWhite = new Knight(WHITE);
	bishopWhite = new Bishop(WHITE);
	queenWhite = new Queen(WHITE);
	kingWhite = new King(WHITE);

	for (int num = 3; num <= 6; num++)
	{
		for (int let = ACOORD; let <= HCOORD; let++)
		{
			addPiece(let, num, empty);
		}
	}

	addPiece(ACOORD, 8, rookBlack);
	addPiece(HCOORD, 8, rookBlack);
	addPiece(BCOORD, 8, knightBlack);
	addPiece(GCOORD, 8, knightBlack);
	addPiece(CCOORD, 8, bishopBlack);
	addPiece(FCOORD, 8, bishopBlack);
	addPiece(DCOORD, 8, queenBlack);
	addPiece(ECOORD, 8, kingBlack);

	for (int let = ACOORD; let <= HCOORD; let++)
	{
		addPiece(let, 7, new Pawn(BLACK));
	}

	addPiece(ACOORD, 1, rookWhite);
	addPiece(HCOORD, 1, rookWhite);
	addPiece(BCOORD, 1, knightWhite);
	addPiece(GCOORD, 1, knightWhite);
	addPiece(CCOORD, 1, bishopWhite);
	addPiece(FCOORD, 1, bishopWhite);
	addPiece(DCOORD, 1, queenWhite);
	addPiece(ECOORD, 1, kingWhite);

	for (int let = ACOORD; let <= HCOORD; let++)
	{
		addPiece(let, 2, new Pawn(WHITE));
	}
}


Board::~Board()
{
}
