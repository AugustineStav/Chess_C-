#pragma once
#include "Piece.h"
#include "Empty.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

//SHOULD ADD EN PASSANT OPTIONS HERE: MAYBE FLAGS IN A LIST OF ALL PAWNS THAT ARE VULNERABLE

class Board
{
private:
	void addPiece(int i, int j, Piece* piece);
	Piece* game[9][9];

	Empty* empty;

	Rook* rookBlack;
	Knight* knightBlack;
	Bishop* bishopBlack;
	Queen* queenBlack;
	King* kingBlack;

	Rook* rookWhite;
	Knight* knightWhite;
	Bishop* bishopWhite;
	Queen* queenWhite;
	King* kingWhite;

public:
	Board();
	~Board();

	void printBoard();
	void setToEmpty(int let, int num);
	Piece* getPieceAt(int let, int num);
	bool movePieceFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
	//bool isOnTeam(int startLet, int startNum, Color team);
};

