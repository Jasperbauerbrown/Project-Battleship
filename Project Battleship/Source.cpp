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
	for (int i = 0; i < 6; i++) {
		do {
			temp1 = ((rand() % 5) + 1);
			temp2 = ((rand() % 5) + 1);
			new1 = true;
			new2 = true;
			for (int j = 0; j < 6; j++) {
				if (temp1 == opponent.shipsx[j]) {
					new1 = false;
				}
				if (new1 == false) {
					for (int l = 0; l < 6; l++) {
						if (temp2 == opponent.shipsy[l]) {
							new2 = false;
						}
					}
				}
			}
		} while (new2 == false);
		opponent.shipsx[i] = temp1;
		opponent.shipsy[i] = temp2;
	}
	for (int i = 0; i < 6; i++) {
		cout << opponent.shipsx[i] << " " << opponent.shipsy[i] << endl;
	}
	for (int i = 0; i < 6; i++) {
		cout << "Enter new set of numbers for ship " << i + 1 << endl;
		do {
			do {
				range = true;
				cout << "X for ship " << i + 1 << endl;
				cin >> temp1;
				if (temp1 < 0 || temp1 > 6) {
					range = false;
					cout << "Incorrect value.  Please use value between 1 and 6." << endl;
				}
			} while (range == false);
			do {
				range = true;
				cout << "Y for ship " << i + 1 << endl;
				cin >> temp1;
				if (temp1 < 0 || temp1 > 6) {
					range = false;
					cout << "Incorrect value.  Please use value between 1 and 6." << endl;
				}
			} while (range == false);
			new1 = true;
			new2 = true;
			for (int j = 0; j < 6; j++) {
				if (temp1 == player.shipsx[j]) {
					new1 = false;
				}
				if (new1 == false) {
					for (int l = 0; l < 6; l++) {
						if (temp2 == player.shipsy[l]) {
							new2 = false;
						}
					}
				}
			}
		} while (new2 == false);
		player.shipsx[i] = temp1;
		player.shipsy[i] = temp2;
	}
	for (int i = 0; i < 6; i++) {
		cout << player.shipsx[i] << " " << player.shipsy[i] << endl;
	}
}
