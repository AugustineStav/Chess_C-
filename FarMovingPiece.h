#pragma once
#include "Piece.h"
#include "Colors.h"

class FarMovingPiece : public Piece
{
public:
	FarMovingPiece();
	FarMovingPiece(char symbol, Color team);
	~FarMovingPiece();
	bool canMoveUp(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveDown(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveLeft(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveRight(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveDiagonalUpRight(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveDiagonalUpLeft(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveDiagonalDownRight(int testLet, int testNum, int endLet, int endNum, Board* board);
	bool canMoveDiagonalDownLeft(int testLet, int testNum, int endLet, int endNum, Board* board);
};

