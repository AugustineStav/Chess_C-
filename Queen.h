#pragma once
#include "FarMovingPiece.h"

class Queen : public FarMovingPiece
{
public:
	Queen();
	Queen(Color team);
	~Queen();
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
};

