#include "FarMovingPiece.h"
#include "Board.h"

FarMovingPiece::FarMovingPiece()
{
}

FarMovingPiece::FarMovingPiece(char symbol, Color team) : Piece(symbol, team) {}

FarMovingPiece::~FarMovingPiece()
{
}

bool FarMovingPiece::canMoveUp(int testLet, int testNum, int endLet, int endNum, Board* board)
{
	//reached destination on empty space:
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	//if the piece above is empty, try moving up:
	if (testNum + 1 <= 8 && board->getPieceAt(testLet, testNum + 1)->isEmpty())
	{
		return(canMoveUp(testLet, testNum + 1, endLet, endNum, board));
	}
	//otherwise, check if the next piece up is an enemy at the destination:
	else if (testNum + 1 <= 8 && isEnemyOf(board->getPieceAt(testLet, testNum + 1)) &&
		testLet == endLet && testNum + 1 == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveDown(int testLet, int testNum, int endLet, int endNum, Board* board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testNum - 1 >= 1 && board->getPieceAt(testLet, testNum - 1)->isEmpty())
	{
		return(canMoveDown(testLet, testNum - 1, endLet, endNum, board));
	}
	else if (testNum - 1 >= 1 && isEnemyOf(board->getPieceAt(testLet, testNum - 1)) &&
		testLet == endLet && testNum - 1 == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveLeft(int testLet, int testNum, int endLet, int endNum, Board* board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testLet - 1 >= ACOORD && board->getPieceAt(testLet - 1, testNum)->isEmpty())
	{
		return(canMoveLeft(testLet - 1, testNum, endLet, endNum, board));
	}
	else if (testLet - 1 >= ACOORD && isEnemyOf(board->getPieceAt(testLet - 1, testNum)) &&
		testLet - 1 == endLet && testNum == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveRight(int testLet, int testNum, int endLet, int endNum, Board* board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testLet + 1 <= HCOORD && board->getPieceAt(testLet + 1, testNum)->isEmpty())
	{
		return(canMoveRight(testLet + 1, testNum, endLet, endNum, board));
	}
	else if (testLet + 1 <= HCOORD && isEnemyOf(board->getPieceAt(testLet + 1, testNum)) &&
		testLet + 1 == endLet && testNum == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveDiagonalUpRight(int testLet, int testNum, int endLet, int endNum, Board * board)
{
	//reached destination on empty space:
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	//if the piece above and to the right is empty, try moving there:
	if (testNum + 1 <= 8 && testLet + 1 <= HCOORD && board->getPieceAt(testLet + 1, testNum + 1)->isEmpty())
	{
		return(canMoveDiagonalUpRight(testLet + 1, testNum + 1, endLet, endNum, board));
	}
	//otherwise, check if the next piece above and to the right is an enemy at the destination:
	else if (testNum + 1 <= 8 && testLet + 1 <= HCOORD && isEnemyOf(board->getPieceAt(testLet + 1, testNum + 1)) &&
		testLet + 1 == endLet && testNum + 1 == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveDiagonalUpLeft(int testLet, int testNum, int endLet, int endNum, Board * board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testNum + 1 <= 8 && testLet - 1 >= ACOORD && board->getPieceAt(testLet - 1, testNum + 1)->isEmpty())
	{
		return(canMoveDiagonalUpLeft(testLet - 1, testNum + 1, endLet, endNum, board));
	}
	else if (testNum + 1 <= 8 && testLet - 1 >= ACOORD && isEnemyOf(board->getPieceAt(testLet - 1, testNum + 1)) &&
		testLet - 1 == endLet && testNum + 1 == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveDiagonalDownRight(int testLet, int testNum, int endLet, int endNum, Board * board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testNum - 1 >= 1 && testLet + 1 <= HCOORD && board->getPieceAt(testLet + 1, testNum - 1)->isEmpty())
	{
		return(canMoveDiagonalDownRight(testLet + 1, testNum - 1, endLet, endNum, board));
	}
	else if (testNum - 1 >= 1 && testLet + 1 <= HCOORD && isEnemyOf(board->getPieceAt(testLet + 1, testNum - 1)) &&
		testLet + 1 == endLet && testNum - 1 == endNum)
	{
		return true;
	}

	return false;
}

bool FarMovingPiece::canMoveDiagonalDownLeft(int testLet, int testNum, int endLet, int endNum, Board * board)
{
	if (testLet == endLet && testNum == endNum)
	{
		return true;
	}

	if (testNum - 1 >= 1 && testLet - 1 >= ACOORD && board->getPieceAt(testLet - 1, testNum - 1)->isEmpty())
	{
		return(canMoveDiagonalDownLeft(testLet - 1, testNum - 1, endLet, endNum, board));
	}
	else if (testNum - 1 >= 1 && testLet - 1 >= ACOORD && isEnemyOf(board->getPieceAt(testLet - 1, testNum - 1)) &&
		testLet - 1 == endLet && testNum - 1 == endNum)
	{
		return true;
	}

	return false;
}