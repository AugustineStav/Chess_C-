#pragma once
#include "Piece.h"

class King : public Piece
{
private:
	bool firstMove;

public:
	King();
	King(Color team);
	~King();
	bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
};

