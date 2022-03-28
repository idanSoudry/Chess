#pragma once
#ifndef ROOK
#define ROOK

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8


class Rook : public Piece
{
public:
	Rook(const char team, const char type, const std::string location, const bool firstMove);

	bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest);
};

#endif // !ROOK
