#pragma once
#include "FarMovingPiece.h"

class Bishop : public FarMovingPiece
{
public:
	Bishop();
	Bishop(Color team);
	~Bishop();
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
};

