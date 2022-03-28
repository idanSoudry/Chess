#include "GameProcces.h"

GameProcces::GameProcces(Board* board, const bool whiteTurn)
{
	this->board = board;
	this->whiteTurn = true;
}

void GameProcces::setWhiteTurn()
{
	this->whiteTurn = true;
}

void GameProcces::setBlackTurn()
{
	this->whiteTurn = false;
}

void GameProcces::flipTurn()
{
	this->whiteTurn = !this->whiteTurn;
}



char GameProcces::isBlackTrun() const
{
	return !(this->whiteTurn);
}

Board* GameProcces::getBoard() const
{
	return board;
}


