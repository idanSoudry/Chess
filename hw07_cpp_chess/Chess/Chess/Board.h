#pragma once
#ifndef BOARD
#define BOARD

#include <iostream>
#include "Piece.h"

#define ROWS 8
#define COLUMNS 8

class Piece;

class Board
{
protected:
	Piece* board[ROWS][COLUMNS];

public:
	Board();

	void printBoard() const;
	int movePlayer(const std::string src, const std::string dst, const bool isBlackTurn);
	// setters
	void setBoard(Piece* board[ROWS][COLUMNS]);

	// getters
	Piece** getBoard() const;
};

#endif // !BOARD
