/* battleShipBoard.cpp
*  Jacob Ingraham
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int BOARD_SIZE = 5;
	string board[BOARD_SIZE][BOARD_SIZE];
	string insert;
	char letter;
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		int number = 1;
		if (x == 0) letter = 'A';
		else if (x == 1) letter = 'B';
		else if (x == 2) letter = 'C';
		else if (x == 3) letter = 'D';
		else if (x == 4) letter = 'E';
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			insert = to_string(number).c_str()[0];
			board[x][y] = letter + insert;
			number++;
		}
	}
	
	cout << "--------------------------" << endl;
	for (int x = 0; x < BOARD_SIZE; x++)
	{
		for (int y = 0; y < BOARD_SIZE; y++)
		{
			if (y == 0) cout << "|";
			cout << " " << board[x][y] << " |";
		}
		cout << "\n--------------------------\n";
	}

	return 0;
}
