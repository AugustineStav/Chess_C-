#include "Pawn.h"
#include "Board.h"


Pawn::Pawn(Color team) : Piece('P', team) 
{
	firstMove = true;
	turnDoubleJumpedOn = -1;
}

bool Pawn::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
{
	//move diagonally
	if (
		(let == (startLet + 1) || let == (startLet - 1)) &&
		(
			(
				isOnTeam(WHITE) &&
				num == (startNum + 1) 
			) 
			||
			(
				isOnTeam(BLACK) &&
				num == (startNum - 1)
			)
		)
	)
	{	
		//en passant (possibly also capturing enemy at destination):
		if (
			//the neighboring piece must be an enemy vulnerable to en passant (just did a double jump):
			board->getPieceAt(let, startNum)->isVulnerableToEnPassant(turnCounter) &&
			isEnemyOf(board->getPieceAt(let, startNum)) &&
			//the destination must be an enemy or empty:
			isNotOnTeamOf(board->getPieceAt(let, num))
			)
		{
			//remove the en passanted opposing pawn
			//DELETE THE REMOVED PAWN:
			board->setToEmpty(let, startNum);
			firstMove = false;
			return true;
		}

		//capture enemy at destination:
		if (isEnemyOf(board->getPieceAt(let, num)))
		{
			firstMove = false;
			return true;
		}
	}

	//more forward to an empty space:
	if (
		let == startLet && board->getPieceAt(let, num)->isEmpty() &&
		(
			(
			isOnTeam(WHITE) &&
			num == startNum + 1
			) ||
			(
			isOnTeam(BLACK) &&
			num == startNum - 1
			)
		)
	)
	{
		firstMove = false;
		return true;
	}

	//double jump over an empty space to an empty space :
	if (
		firstMove && let == startLet && board->getPieceAt(let, num)->isEmpty() &&
		(
			(
			isOnTeam(WHITE) &&
			num == startNum + 2 &&
			board->getPieceAt(let, startNum + 1)->isEmpty()
			) ||
			(
			isOnTeam(BLACK) &&
			num == startNum - 2 &&
			board->getPieceAt(let, startNum - 1)->isEmpty()
			)
		)
	)
	{
		firstMove = false;
		turnDoubleJumpedOn = turnCounter;
		return true;
	}

	//invalid move:
	return false;
}

bool Pawn::isVulnerableToEnPassant(int turnCounter)
{
	if (isOnTeam(WHITE))
	{
		return (turnCounter == this->turnDoubleJumpedOn);
	}
	else
	{
		return (turnCounter == this->turnDoubleJumpedOn + 1);
	}
}

Pawn::Pawn() 
{
	firstMove = true;
	turnDoubleJumpedOn = -1;
}

Pawn::~Pawn()
{
}
