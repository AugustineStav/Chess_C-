#pragma once
#include "Colors.h"
#include <cmath>

class Board;

class Piece
{
private:
	Coord currLet; //x coordinate
	int currNum; //y coordinate

	char symbol;
	Color team;

public:
	Piece();
	virtual ~Piece();
	Piece(char symbol, Color team);
	
	Color getTeam();
	bool isOnTeam(Color team);
	bool isEnemyOf(Piece* piece);
	bool isNotOnTeamOf(Piece* piece);
	bool isEmpty();
	virtual bool isVulnerableToEnPassant(int turnCounter);
	virtual bool canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter);
	void display();
};

