#include "Piece.h"
#include "GameProcces.h"

Piece::Piece(const char team, const char type, const std::string location, const bool firstMove)
{
	// add exceptions
	this->team = team;
	this->type = type;
	char row = location[1], column = location[0];
	int final_location = (((int(row)) - 48) * 10) + (int(column) - 97);
	this->location = final_location;
	this->firstMove = firstMove;
}

/*
Function is moving the piece from onw place to other place on the board
*/
void Piece::move(Piece* board[ROWS][COLUMNS], int dest)
{
	int source = this->getLocation();
	int DestRow = 0, DestColumn = 0, SourceRow = 0, SourceColumn = 0;
	DestRow = (dest / 10) - 1;
	DestColumn = dest % 10;
	SourceRow = (source / 10) - 1;
	SourceColumn = source % 10;
	board[DestRow][DestColumn] = board[SourceRow][SourceColumn];
	board[SourceRow][SourceColumn] = nullptr;
	this->location = (DestRow+1) * 10 + DestColumn;
}

int Piece::validMove(Piece* board[ROWS][COLUMNS], int dest)
{
	int location = this->getLocation();
	int row = (location / 10) - 1;
	int column = location % 10;
	int DestRow = (dest / 10) - 1;
	int DestColumn = dest % 10;

	if (location == dest)
	{
		return 7;
	}

	if (board[row][column] != nullptr)
	{
		if (board[DestRow][DestColumn] != nullptr)
		{
			if (board[row][column]->getTeam() == board[DestRow][DestColumn]->getTeam())
			{
				return 3;
			}
		}
		if (correct_move(board, location, dest) && not_making_chess(board, dest, location))
		{
			if (making_chess_on_enemy(board, dest, location))
			{
				return 1;
			}
			return 0;
		}
		else if (!correct_move(board, location, dest))
		{
			return 6;
		}
		else if (!not_making_chess(board, dest, location))
		{
			return 4;
		}
	}
	else
	{
		return 2;
	}
}

/*
Function return true if the the next move going to eat other team piece
*/

Piece* Piece::isEmpty(Piece* board[ROWS][COLUMNS], int dest)
{
	int row = (dest / 10);
	int column = dest % 10;

	if (board[row][column] != nullptr)
	{

		Piece* check = board[row][column];
		return check;
	}
	return nullptr;
}



bool Piece::not_making_chess(Piece* board[ROWS][COLUMNS], int dest, int src)
{
	int Srow = (src / 10) - 1, Scolumn = src % 10;
	int Drow = (dest / 10) - 1, Dcolumn = dest % 10;

	Piece* savePiece = board[Drow][Dcolumn];
	board[Srow][Scolumn]->location = dest;
	board[Drow][Dcolumn] = board[Srow][Scolumn];
	board[Srow][Scolumn] = nullptr;

	int myKing = findKing('k', board);
	if (this->getTeam() == '0')
	{
		myKing = findKing('K', board);
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			int currentPlace = (i * 10) + j;
			Piece* currentPiece = Piece::isEmpty(board, currentPlace);
			if (currentPiece != nullptr)
			{
				bool chess = currentPiece->correct_move(board, currentPiece->getLocation(), myKing);
				if (chess == true && (currentPiece->getTeam() != board[(myKing/10)-1][myKing%10]->getTeam()))
				{
					board[Srow][Scolumn] = board[Drow][Dcolumn];
					board[Srow][Scolumn]->location = src;
					board[Drow][Dcolumn] = savePiece;
					return false;
				}
			}
		}
	}
	board[Srow][Scolumn] = board[Drow][Dcolumn];
	board[Srow][Scolumn]->location = src;
	board[Drow][Dcolumn] = savePiece;

	return true;
}

bool Piece::making_chess_on_enemy(Piece* board[ROWS][COLUMNS], int dest, int src)
{
	int Srow = (src / 10) - 1, Scolumn = src % 10;
	int Drow = (dest / 10) - 1, Dcolumn = dest % 10;

	Piece* savePiece = board[Drow][Dcolumn];
	board[Srow][Scolumn]->location = dest;
	board[Drow][Dcolumn] = board[Srow][Scolumn];
	board[Srow][Scolumn] = nullptr;

	int myKing = findKing('k', board);
	if (this->getTeam() == '1')
	{
		myKing = findKing('K', board);
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			int currentPlace = (i * 10) + j;
			Piece* currentPiece = Piece::isEmpty(board, currentPlace);
			if (currentPiece != nullptr)
			{
				bool chess = currentPiece->correct_move(board, currentPiece->getLocation(), myKing);
				if (chess == true && (currentPiece->getTeam() != board[(myKing / 10) - 1][myKing % 10]->getTeam()))
				{
					board[Srow][Scolumn] = board[Drow][Dcolumn];
					board[Srow][Scolumn]->location = src;
					board[Drow][Dcolumn] = savePiece;
					return true;
				}
			}
		}
	}
	board[Srow][Scolumn] = board[Drow][Dcolumn];
	board[Srow][Scolumn]->location = src;
	board[Drow][Dcolumn] = savePiece;

	return false;
}


void Piece::setPlayerOnBoard(Piece* board[ROWS][COLUMNS])
{
	int location = this->getLocation();
	int row = (location / 10) - 1, column = location % 10;
	board[row][column] = this;
}

void Piece::movedOnce()
{
	this->firstMove = false;
}


int Piece::findKing(char type, Piece* board[ROWS][COLUMNS])
{
	int i = 0, j = 0, currentPlace = 0;

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			currentPlace = i * 10 + j;
			if ((board[i][j]->isEmpty(board, currentPlace)) != nullptr)
			{
				if (board[i][j]->getType() == type)
				{
					return board[i][j]->getLocation();
				}
			}
		}
	}
	return 0;
}

/*
return the type
*/
char Piece::getType() const
{
	return this->type;
}

/*
return the team
*/
char Piece::getTeam() const
{
	return this->team;
}

/*
return the location
*/
int Piece::getLocation() const
{
	return this->location;
}

/*
set the type
*/
void Piece::setType(const char type)
{
	this->type = type;
}

/*
set the team
*/
void Piece::setTeam(const char team)
{
	this->team = team;
}

/*
set the location
*/
void Piece::setLocation(const std::string location)
{
	char row = location[1], column = location[0];
	int final_location = ((57 - (int(row))) * 10) + (int(column) - 97);
	this->location = final_location;
}
