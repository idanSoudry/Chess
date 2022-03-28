#pragma once
#ifndef KNIGHT
#define KNIGHT

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8

class Knight : public Piece
{
public:
	Knight(const char team, const char type, const std::string location, const bool firstMove);

	bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest);
};
#endif // !KNIGHT