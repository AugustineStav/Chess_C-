#pragma once
#include "FarMovingPiece.h"

class Rook : public FarMovingPiece
{
private:
	bool firstMove;

public:
	Rook();
	Rook(Color team);
	~Rook();
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
};

