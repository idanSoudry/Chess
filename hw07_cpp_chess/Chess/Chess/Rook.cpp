#include "Rook.h"

#define ROWS 8
#define COLUMNS 8


Rook::Rook(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{}

bool Rook::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest)
{

	int dst_row = (dest / 10) - 1;
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;

	if (!((dst_row != src_row && src_column == dst_column) || (dst_row == src_row && src_column != dst_column)))
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
	if (dst_row == src_row)
	{
		if (src_column < dst_column)
		{
			for (int i = src_column + 1; i < dst_column; i++)
			{
				if (board[src_row][i] != nullptr)
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = src_column - 1; i > dst_column; i--)
			{
				if (board[src_row][i] != nullptr)
				{
					return false;
				}
			}
		}
	}
	else if (dst_column == src_column)
	{
		if (dst_row > src_row)
		{
			for (int i = src_row + 1; i < dst_row; i++)
			{
				if (board[i][src_column] != nullptr)
				{
					return false;
				}
			}
		}
		else
		{
			for (int i = src_row - 1; i > dst_row; i--)
			{
				if (board[i][src_column] != nullptr)
				{
					return false;
				}
			}
		}
	}

	return true;
}


