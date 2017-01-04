#pragma once
#include "Piece.h"
class Knight :
	public Piece
{
public:
	Knight();
	Knight(Color team);
	~Knight();
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
};

