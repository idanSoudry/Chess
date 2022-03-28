#pragma once
#ifndef PAWN
#define PAWN

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8

class Pawn : public Piece
{
public:
	Pawn(const char team, const char type, const std::string location, const bool firstMove);

	bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest);
};

#endif // !PAWN
