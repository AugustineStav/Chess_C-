#include <iostream>
#include "Piece.h"

Piece::Piece()
{
}

Piece::Piece(char symbol, Color team)
{
	this->symbol = symbol;
	this->team = team;
}

Color Piece::getTeam()
{
	return this->team;
}

bool Piece::isOnTeam(Color team)
{
	return (this->getTeam() == team);
}

bool Piece::isEnemyOf(Piece* piece)
{
	return ((piece->getTeam() != this->getTeam()) && 
		!piece->isEmpty()  && !this->isEmpty());
}

bool Piece::isNotOnTeamOf(Piece * piece)
{
	return (this->getTeam() != piece->getTeam());
}

bool Piece::isEmpty()
{
	return (this->team == NEUTRAL);
}

bool Piece::isVulnerableToEnPassant(int turnCounter)
{
	return false;
}

Piece::~Piece()
{
}

void Piece::display()
{
	std::cout << symbol;
	switch (this->team)
	{
		case (NEUTRAL) :
		{
			std::cout << "x ";
			break;
		}
		case (BLACK) :
		{
			std::cout << "b ";
			break;
		}
		case (WHITE) :
		{
			std::cout << "w ";
			break;
		}
		
	}
}

bool Piece::canMoveFromTo(int startLet, int startNum, int let, int num, Board* board, int turnCounter)
{
	return false;
}
