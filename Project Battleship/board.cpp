/* board.cpp
*  Jasper, Jacob
*  5/10/21
*  cpp for board.h
*/

#include "board.h"

gameBoard::gameBoard()
{
	for (int x = 0; x < 5; x++)
	{
		int number = 1;
		if (x == 0) letter = 'A';
		else if (x == 1) letter = 'B';
        else if (x == 2) letter = 'C';
        else if (x == 3) letter = 'D';
        else if (x == 4) letter = 'E';
        for (int y = 0; y < 5; y++)
        {
            insert = to_string(number).c_str()[0];
            board[x][y] = letter + insert;
            number++;
        }
    }
}
gameBoard::~gameBoard(){}
void gameBoard::printBoard(bool opp)
{
	cout << "--------------------------" << endl;
    for (int x = 0; x < 5; x++)
    {
        for (int y = 0; y < 5; y++)
        {
            if (y == 0) cout << "|";
            if (opp == true && board[x][y] == "XX")
			{
				int number = 1;
	        	string output;
				if (x == 0) letter = 'A';
    	    	else if (x == 1) letter = 'B';
    		    else if (x == 2) letter = 'C';
	        	else if (x == 3) letter = 'D';
	        	else if (x == 4) letter = 'E';
            	insert = to_string(y + 1).c_str()[0];
        	    output = letter + insert;
				cout << " " << output << " |";
			}
			else cout << " " << board[x][y] << " |";
        }
        cout << "\n--------------------------\n";
    }
}
void gameBoard::addShips(int cord1, int cord2)
{
    board[cord1][cord2] = "XX";
}
bool gameBoard::guess(int guessCord1, int guessCord2)
{
	bool exitBool = false;
	int boatsLeft = 0;
	if (board[guessCord1][guessCord2] == "XX")
	{
		cout << "Hit!" << endl;
		board[guessCord1][guessCord2] = "++";
	}
	else
	{
		cout << "Miss!" << endl;
		board[guessCord1][guessCord2] = "OO";
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == "XX") boatsLeft++;
		}
	}
	cout << "There are " << boatsLeft << " boats left" << endl;
	if (boatsLeft == 0)
	{
		exitBool = true;
	}
	return exitBool;
}
