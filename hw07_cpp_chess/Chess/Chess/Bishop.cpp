#include "Bishop.h"

Bishop::Bishop(const char team, const char type, const std::string location, const bool firstMove) : Piece(team, type, location, firstMove)
{

}

bool Bishop::correct_move(Piece* board[ROWS][COLUMNS], int src, int dest) //not enough documentation -> supposed to detailed about this method
{
	int dst_row = (dest / 10) - 1; 
	int dst_column = dest % 10;
	int src_row = (src / 10) - 1;
	int src_column = src % 10;
	int row_mov = 0, column_mov = 0; 
	row_mov = src_row - dst_row;	 // supposed doing it in the init commend
	column_mov = src_column - dst_column;		// supposed doing it in the init commend
	int i = 0, j = 0;
	
	if (board[dst_row][dst_column] != nullptr) //not enough documentation
	{
		if (board[dst_row][dst_column]->getTeam() == board[src_row][src_column]->getTeam())
		{
			return false;
		}
	}

	if(std::abs(row_mov) != std::abs(column_mov)) //not enough documentation -> supposed to detailed about this check
	{
		return false;
	}

	if (src_row > dst_row && src_column < dst_column)  //not enough documentation -> supposed to detailed about this check
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
	else if (src_row < dst_row&& src_column < dst_column)  //not enough documentation -> supposed to detailed about this check
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
	else if (src_row > dst_row && src_column > dst_column)  //not enough documentation -> supposed to detailed about this check
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
	else if (src_row < dst_row && src_column > dst_column) //not enough documentation -> supposed to detailed about this check
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
	

	return true;
}
