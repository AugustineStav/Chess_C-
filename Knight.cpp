#include "Knight.h"
#include "Board.h"

Knight::Knight(Color team) : Piece('H', team) {}

Knight::Knight()
{
}


Knight::~Knight()
{
}

bool Knight::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
{
	if (
		(
		(abs(let - startLet) == 2 && abs(num - startNum) == 1) ||
		(abs(let - startLet) == 1 && abs(num - startNum) == 2)
		) &&
		isNotOnTeamOf(board->getPieceAt(let, num))
	)
	{
		return true;
	}
}
