#include "Bishop.h"

Bishop::Bishop(Color team) : FarMovingPiece('B', team) {}

Bishop::Bishop()
{
}


Bishop::~Bishop()
{
}

bool Bishop::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
{
	if (startLet == let && startNum == num)
	{
		return false;
	}

	if (canMoveDiagonalUpRight(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveDiagonalUpLeft(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveDiagonalDownRight(startLet, startNum, let, num, board))
	{
		return true;
	}

	if (canMoveDiagonalDownLeft(startLet, startNum, let, num, board))
	{
		return true;
	}

	return false;
}
