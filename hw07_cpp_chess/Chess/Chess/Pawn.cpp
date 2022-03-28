#include "Pawn.h"

Pawn::Pawn(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{}

bool Pawn::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest)
{
	int dst_row = (dest / 10) - 1;
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;
	int difference = 0;
	difference = src_row - dst_row;
	difference = std::abs(difference);

	if (this->getTeam() == '0')
	{
		if (!(src_row - dst_row > 0))
		{
			return false;
		}
	}
	else if (this->getTeam() != '0')
	{
		if (!(dst_row - src_row > 0))
		{
			return false;
		}
	}

	if (!this->firstMove)
	{
		if (difference != 1)
		{
			return false;
		}
		if (board[dst_row][dst_column] == nullptr)
		{
			if (!(src_column == dst_column))
			{
				return false;
			}
		}
		else
		{
			if (!((src_column == dst_column - 1) || (src_column == dst_column + 1)))
			{
				return false;
			}
		}
	}
	else
	{
		if (!(difference == 1 || difference == 2))
		{
			return false;
		}
		if (board[dst_row][dst_column] == nullptr)
		{
			if (!(src_column == dst_column))
			{
				return false;
			}
		}
		else
		{
			if (!(((src_column == dst_column - 1) || (src_column == dst_column + 1) || (src_column == dst_column)) && difference == 1))
			{
				return false;
			}
		}
	}
	return true;
}
