#pragma once
#ifndef KING
#define KING

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8

class King : public Piece
{
public:
	King(const char team, const char type, const std::string location, const bool firstMove);

	bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest);
};

#endif // !ROOK
