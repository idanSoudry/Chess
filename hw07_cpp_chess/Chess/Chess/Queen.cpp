#include "Queen.h"

Queen::Queen(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{
}

bool Queen::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest)
{
	int dst_row = (dest / 10) - 1;
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;
	int i = 0, j = 0;
	int row_mov = 0, column_mov = 0;
	row_mov = src_row - dst_row;
	column_mov = src_column - dst_column;

	if (board[dst_row][dst_column] != nullptr)
	{
		if (board[src_row][src_column]->getTeam() == board[dst_row][dst_column]->getTeam())
		{
			return false;
		}
	}

	if ((dst_row != src_row && src_column == dst_column) || (dst_row == src_row && src_column != dst_column))
	{
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
	}
	else if (std::abs(row_mov) == std::abs(column_mov))
	{
		if (src_row > dst_row && src_column < dst_column)
		{
			j = src_column;
			for (i = src_row - 1; i > dst_row; i--)
			{
				j++;
				if (board[i][j] != nullptr)
				{
					return false;
				}
			}
		}
		else if (src_row < dst_row && src_column < dst_column)
		{
			j = src_column;
			for (i = src_row + 1; i < dst_row; i++)
			{
				j++;
				if (board[i][j] != nullptr)
				{
					return false;
				}
			}
		}
		else if (src_row > dst_row && src_column > dst_column)
		{
			j = src_column;
			for (i = src_row - 1; i > dst_row; i--)
			{
				j--;
				if (board[i][j] != nullptr)
				{
					return false;
				}
			}
		}
		else if (src_row < dst_row && src_column > dst_column)
		{
			j = src_column;
			for (i = src_row + 1; i < dst_row; i++)
			{
				j--;
				if (board[i][j] != nullptr)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}