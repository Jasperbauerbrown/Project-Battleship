/* Final Project BattleShip
 * Jasper, Jacob
 * 5/3/2021
 * 
 * Jasper:  Added computer ship generator and player ship input.
 */
#include "Player.h"
using namespace std;
Opponent opponent;
Player player;
int temp1;
int temp2;
bool new1 = true;
bool new2 = true;
bool range = true;

int main() {
	srand((unsigned)time(0));
	for (int i = 0; i < 5; i++) {
		do {
			temp1 = ((rand() % 4) + 1);
			temp2 = ((rand() % 4) + 1);
			new1 = true;
			for (int j = 0; j < 5; j++) {
				if (temp1 == opponent.shipsx[j] && temp2 == opponent.shipsy[j]) {
					new1 = false;
				}
			}
		} while (new1 == false);
		opponent.shipsx[i] = temp1;
		opponent.shipsy[i] = temp2;
	}
	for (int i = 0; i < 5; i++) {
		cout << opponent.shipsx[i] << " " << opponent.shipsy[i] << endl;
	}
	for (int i = 0; i < 5; i++) {
		cout << "Enter new set of numbers for ship " << i + 1 << endl;
		do {
			do {
				range = true;
				cout << "X for ship " << i + 1 << endl;
				cin >> temp1;
				if (temp1 < 0 || temp1 > 5) {
					range = false;
					cout << "Incorrect value.  Please use value between 1 and 6." << endl;
				}
			} while (range == false);
			do {
				range = true;
				cout << "Y for ship " << i + 1 << endl;
				cin >> temp1;
				if (temp1 < 0 || temp1 > 5) {
					range = false;
					cout << "Incorrect value.  Please use value between 1 and 6." << endl;
				}
			} while (range == false);
			new2 = true;
			for (int t = 0; t < i; t++) {
				if (temp1 == player.shipsx[t] && temp2 == player.shipsy[t]) {
					new2 = false;
					cout << "You already used that position.  Please enter a new position." << endl;
				}
			}
		} while (new2 == false);
		player.shipsx[i] = temp1;
		player.shipsy[i] = temp2;
	}
	for (int i = 0; i < 5; i++) {
		cout << player.shipsx[i] << " " << player.shipsy[i] << endl;
	}
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
