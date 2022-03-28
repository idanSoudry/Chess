#pragma once
#ifndef GAMEPROCCES
#define GAMEPROCCES

#include <iostream>
#include "Board.h"

using namespace std;

class GameProcces
{
protected:
	Board* board;
	bool whiteTurn;

public:
	GameProcces(Board* board, const bool whiteTurn);
	void setWhiteTurn();
	void setBlackTurn();
	void flipTurn();
	char isBlackTrun() const;
	Board* getBoard() const;
	
};

#endif // !GAMEPROCCES
