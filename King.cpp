#include "King.h"
#include "Board.h"

King::King(Color team) : Piece('K', team) 
{
	firstMove = true;
}

King::King()
{
	firstMove = true;
}

King::~King()
{
}

bool King::canMoveFromTo(int startLet, int startNum, int let, int num, Board * board, int turnCounter)
{
	if (abs(let - startLet) < 2 && abs(num - startNum) < 2 &&
		!(let == startLet && num == startNum) && isNotOnTeamOf(board->getPieceAt(let, num)))
	{
		return true;
	}
	return false;
}
