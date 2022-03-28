#include "Board.h"
#include "King.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"

Board::Board()
{
	int i = 0, j = 0;
	std::string location = "";

	King* blackKing = new King('1', 'k', "d1", true);
	King* whiteKing = new King('0', 'K', "d8", true);

	Queen* blackQueen = new Queen('1', 'q', "e1", true);
	Queen* whiteQueen = new Queen('0', 'Q', "e8", true);

	Rook* blackRook1 = new Rook('1', 'r', "a1", true);
	Rook* blackRook2 = new Rook('1', 'r', "h1", true);
	Rook* whiteRook1 = new Rook('0', 'R', "a8", true);
	Rook* whiteRook2 = new Rook('0', 'R', "h8", true);
	
	Pawn* whitePawn1 = new Pawn('0', 'P', "a7", true);
	Pawn* whitePawn2 = new Pawn('0', 'P', "b7", true);
	Pawn* whitePawn3 = new Pawn('0', 'P', "c7", true);
	Pawn* whitePawn4 = new Pawn('0', 'P', "d7", true);
	Pawn* whitePawn5 = new Pawn('0', 'P', "e7", true);
	Pawn* whitePawn6 = new Pawn('0', 'P', "f7", true);
	Pawn* whitePawn7 = new Pawn('0', 'P', "g7", true);
	Pawn* whitePawn8 = new Pawn('0', 'P', "h7", true);
	
	Pawn* blackPawn1 = new Pawn('1', 'p', "a2", true);
	Pawn* blackPawn2 = new Pawn('1', 'p', "b2", true);
	Pawn* blackPawn3 = new Pawn('1', 'p', "c2", true);
	Pawn* blackPawn4 = new Pawn('1', 'p', "d2", true);
	Pawn* blackPawn5 = new Pawn('1', 'p', "e2", true);
	Pawn* blackPawn6 = new Pawn('1', 'p', "f2", true);
	Pawn* blackPawn7 = new Pawn('1', 'p', "g2", true);
	Pawn* blackPawn8 = new Pawn('1', 'p', "h2", true);

	Bishop* blackBishop1 = new Bishop('1', 'b', "c1", true);
	Bishop* blackBishop2 = new Bishop('1', 'b', "f1", true);
	Bishop* whiteBishop1 = new Bishop('0', 'B', "c8", true);
	Bishop* whiteBishop2 = new Bishop('0', 'B', "f8", true);

	Knight* blackKnight1 = new Knight('1', 'n', "b1", true);
	Knight* blackKnight2 = new Knight('1', 'n', "g1", true);
	Knight* whiteKnight1 = new Knight('0', 'N', "b8", true);
	Knight* whiteKnight2 = new Knight('0', 'N', "g8", true);

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			board[i][j] = nullptr;
		}
	}

	blackKing->setPlayerOnBoard(this->board);
	whiteKing->setPlayerOnBoard(this->board);
	blackRook1->setPlayerOnBoard(this->board);
	blackRook2->setPlayerOnBoard(this->board);
	whiteRook1->setPlayerOnBoard(this->board);
	whiteRook2->setPlayerOnBoard(this->board);
	
	whitePawn1->setPlayerOnBoard(this->board);
	whitePawn2->setPlayerOnBoard(this->board);
	whitePawn3->setPlayerOnBoard(this->board);
	whitePawn4->setPlayerOnBoard(this->board);
	whitePawn5->setPlayerOnBoard(this->board);
	whitePawn6->setPlayerOnBoard(this->board);
	whitePawn7->setPlayerOnBoard(this->board);
	whitePawn8->setPlayerOnBoard(this->board);

	blackPawn1->setPlayerOnBoard(this->board);
	blackPawn2->setPlayerOnBoard(this->board);
	blackPawn3->setPlayerOnBoard(this->board);
	blackPawn4->setPlayerOnBoard(this->board);
	blackPawn5->setPlayerOnBoard(this->board);
	blackPawn6->setPlayerOnBoard(this->board);
	blackPawn7->setPlayerOnBoard(this->board);
	blackPawn8->setPlayerOnBoard(this->board);

	blackBishop1->setPlayerOnBoard(this->board);
	blackBishop2->setPlayerOnBoard(this->board);
	whiteBishop1->setPlayerOnBoard(this->board);
	whiteBishop2->setPlayerOnBoard(this->board);

	blackKnight1->setPlayerOnBoard(this->board);
	blackKnight2->setPlayerOnBoard(this->board);
	whiteKnight1->setPlayerOnBoard(this->board);
	whiteKnight2->setPlayerOnBoard(this->board);

	blackQueen->setPlayerOnBoard(this->board);
	whiteQueen->setPlayerOnBoard(this->board);

}

/*
Function prints the board
*/
void Board::printBoard() const
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			if (board[i][j] != nullptr)
			{
				std::cout << this->board[i][j]->getType() << "\t";
			}
			else 
			{
				std::cout << "#" << "\t";
			}
		}
		std::cout << std::endl;
	}
}

int Board::movePlayer(const std::string src, const std::string dst, const bool isBlackTurn)
{
	char row = src[1], column = src[0];
	char Drow = dst[1], Dcolumn = dst[0];
	int final_src_location = (((57 - int(row)) * 10) + (int(column) - 97));
	int final_dst_location = (((57 - int(Drow)) * 10) + (int(Dcolumn) - 97));
	if ((1 > (final_src_location/10) > 8 || 1 > (final_src_location%10) > 8) || (1 > (final_dst_location / 10) > 8 || 1 > (final_dst_location % 10) > 8))
	{
		return 5;
	}
	Piece* player = board[((final_src_location/10)-1)][(final_src_location%10)];
	if (player != nullptr)
	{
		if (!((player->getTeam() != '0' && isBlackTurn) || (player->getTeam() == '0' && !isBlackTurn)))
		{
			return 2;
		}
		int canMakeMove = player->validMove(this->board, final_dst_location);
		if (canMakeMove == 0 || canMakeMove == 1)
		{
			player->move(this->board, final_dst_location);
			player->movedOnce();
			return canMakeMove;
		}
		return canMakeMove;
	}
	return 2;
}

void Board::setBoard(Piece* board[ROWS][COLUMNS])
{
	int i = 0, j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{
			this->board[i][j] = board[i][j];
		}
	}
}

Piece** Board::getBoard() const
{
	return (Piece**)this->board;
}

