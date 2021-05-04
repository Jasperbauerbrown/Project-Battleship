/* Final Project BattleShip
 * Jasper, Jacob
 * 5/3/2021
 */
#include "Player.h"
using namespace std;
Opponent opponent;
Player player;
int temp1;
int temp2;
bool new1 = true;
bool new2 = true;

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
}