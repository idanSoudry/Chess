#include "King.h"

King::King(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{}

bool King::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest)
{
	int dst_row = (dest / 10) - 1;
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;
	if (!((((dst_row == src_row) && (dst_column == src_column + 1)) || ((dst_row == src_row) && (dst_column == src_column - 1))) || 
		(((dst_row == src_row + 1) && (dst_column == src_column)) || ((dst_row == src_row - 1) && (dst_column == src_column))) || 
		(((dst_row == src_row + 1) && (dst_column == src_column + 1)) || ((dst_row == src_row - 1) && (dst_column == src_column - 1))) || 
		(((dst_row == src_row + 1) && (dst_column == src_column - 1)) || ((dst_row == src_row - 1) && (dst_column == src_column + 1)))))
	{
		return false;
	}
	if (board[dst_row][dst_column] != nullptr)
	{
		if (board[dst_row][dst_column]->getTeam() == board[src_row][src_column]->getTeam())
		{
			return false;
		}
	}
	return true;
}