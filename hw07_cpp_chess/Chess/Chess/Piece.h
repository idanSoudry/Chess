#pragma once
#ifndef PIECE
#define PIECE

#include <iostream>
#include "Board.h"

#define ROWS 8
#define COLUMNS 8

class Board;

class Piece
{
protected:
	int location; // location of the piece (56, row = 5, column = 6)
	char type; // the type of the piece (K/k, Q/q)
	char team; // the team of the piece (white = 0, black = any other number)
	bool firstMove;

public:
	Piece(const char team, const char type, const std::string location, const bool firstMove);
	
	virtual void move(Piece* board[ROWS][COLUMNS], int dest);
	virtual int validMove(Piece* board[ROWS][COLUMNS], int dest);
	
	static int findKing(char type, Piece* board[ROWS][COLUMNS]);
	static Piece* isEmpty(Piece* board[ROWS][COLUMNS], int dest);
	bool not_making_chess(Piece* board[ROWS][COLUMNS], int dest, int src);
	bool making_chess_on_enemy(Piece* board[ROWS][COLUMNS], int dest, int src);
	virtual bool correct_move(Piece* board[ROWS][COLUMNS], int src, int dest) = 0;
	void setPlayerOnBoard(Piece* board[ROWS][COLUMNS]);
	
	void movedOnce();

	// getters
	char getType() const;
	char getTeam() const;
	int getLocation() const;
	
	// setters
	void setType(const char type);
	void setTeam(const char team);
	void setLocation(const std::string location);
};

#endif // !PIECE
