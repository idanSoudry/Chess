#pragma once
#ifndef BISHOP
#define BISHOP

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8

using namespace std;

class Bishop : public Piece
{
public:
	Bishop(const char team, const char type, const std::string location, const bool firstMove);

	bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest);
};

#endif // !BISHOP
