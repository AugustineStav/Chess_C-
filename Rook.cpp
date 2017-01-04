#include "Rook.h"
#include "Board.h"

//ADD ABILITY TO CASTLE

Rook::Rook()
{
	firstMove = true;
}

Rook::Rook(Color team) : FarMovingPiece('R', team) 
{
	firstMove = true;
}

Rook::~Rook()
{
}

bool Rook::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
{
	if (startLet == let && startNum == num)
	{
		return false;
	}

	if (canMoveUp(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveDown(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveLeft(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveRight(startLet, startNum, let, num, board))
	{
		return true;
	}

	return false;
}
