#include "Knight.h"
#define KNIGHTMOVES 3
Knight::Knight(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{
}

bool Knight::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest)
{
	int dst_row = (dest / 10) - 1;
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;

	int row_mov = 0, column_mov = 0;
	row_mov = src_row - dst_row;
	column_mov = dst_column - src_column;
	row_mov = std::abs(row_mov);
	column_mov = std::abs(column_mov);

	bool con = true;
	int i = 0;

	if (board[dst_row][dst_column] != nullptr)
	{
		if (board[dst_row][dst_column]->getTeam() == board[src_row][src_column]->getTeam())
		{
			return false;
		}
	}


	if (src_column == dst_column || src_row == dst_row)
	{
		return false;
	}

	if (!((row_mov == 2 && column_mov == 1) ||
		 (row_mov == 1 && column_mov == 2)))
	{
		return false;
	}

	return true;
}
