#pragma once
/* board.h
*  Jasper, Jacob
*  5/10/21
*  Print the board, insert boats, and guesses into the board
*/

#include "Player.h"
#ifndef GAME_BOARD
#define GAME_BOARD

class gameBoard
{
public:
	gameBoard();
	~gameBoard();
	string board[5][5];
	string insert;
	char letter;
	void printBoard(bool);
	void addShips(int, int);
	bool guess(int, int);
};
#endif
