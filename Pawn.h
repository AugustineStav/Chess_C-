#pragma once
#include "Piece.h"
#include "Colors.h"

class Pawn : public Piece
{
private:
	bool firstMove;
	int turnDoubleJumpedOn; //set to value that will not match existing turns (so that an unmoved pawn is not vulnerable to en passant)
public:
	Pawn();
	Pawn(Color team);
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
	bool isVulnerableToEnPassant(int turnCounter);
	~Pawn();
};

