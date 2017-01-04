#include "Queen.h"

Queen::Queen(Color team) : FarMovingPiece('Q', team) {}

Queen::Queen()
{
}

Queen::~Queen()
{
}

bool Queen::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
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
