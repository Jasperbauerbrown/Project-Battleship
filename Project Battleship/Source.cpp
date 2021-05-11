/* Final Project BattleShip
 * Jasper, Jacob
 * 5/3/2021
 * 
 * Jasper:  Added computer ship generator and player ship input.
 */
#include "board.h"
#include <string>
using namespace std;
opponent opponent;
player player;
gameBoard board1;
gameBoard board2;
string contString;
int temp1, temp2, playerGuessX, playerGuessY, guessNum = 0;
bool new1 = true, new2 = true, range = true, exitBool, withinBounds, winner;

int main() {
    srand((unsigned)time(0));
    for (int i = 0; i < 5; i++) {
        do {
            temp1 = ((rand() % 5));
            temp2 = ((rand() % 5));
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

    for (int i = 0; i < 5; i++)
    {
        board1.addShips(opponent.shipsx[i], opponent.shipsy[i]);
    }

    cout << system("clear") << "------------------------------------------------" << endl << "             WELCOME TO BATTLESHIP" << endl
    << "------------------------------------------------" << endl << "BEGIN BY ENTERING THE COORDINATES FOR YOUR SHIPS" << endl
    << "------------------------------------------------" << endl;
	
    for (int i = 0; i < 5; i++) {
        cout << "Enter new set of numbers for ship " << i + 1 << endl;
        do {
            do {
                range = true;
                cout << "X for ship " << i + 1 << endl;
                cin >> temp1;
                if (temp1 <= 0 || temp1 > 5) {
                    range = false;
                    cout << "Incorrect value.  Please use value between 1 and 5." << endl;
                }
            } while (range == false);
            do {
                range = true;
                cout << "Y for ship " << i + 1 << endl;
                cin >> temp2;
		               if (temp2 <= 0 || temp2 > 5) {
                    range = false;
                    cout << "Incorrect value.  Please use value between 1 and 5." << endl;
                }
            } while (range == false);
            new2 = true;
            for (int t = 0; t < i; t++) {
                if ((temp2 - 1) == player.shipsx[t] && (temp1 - 1) == player.shipsy[t]) {
                    new2 = false;
                    cout << "You already used that position.  Please enter a new position." << endl;
                }
            }
        } while (new2 == false);
        player.shipsx[i] = (temp2 - 1);
        player.shipsy[i] = (temp1 - 1);
    }

    for (int i = 0; i < 5; i++)
    {
        board2.addShips(player.shipsx[i], player.shipsy[i]);
    }

    cout << system("clear") << endl << "This is your board (your ships are marked by XX): " << endl;
    board2.printBoard(false);

    cout << endl << endl << "And this is your opponents board: " << endl;
    board1.printBoard(true);
    cout << endl << "Press enter to continue";
    cin.ignore();
    getline(cin, contString);
    cout << system("clear");

    do
    {
        do
        {
            withinBounds = false;
            cout << "Please enter the X coordinate of your guess (1-5)" << endl;
            cin >> playerGuessX;
            if (playerGuessX > 0 && playerGuessX < 6) withinBounds = true;
            else cout << "Please enter a valid coordinate" << endl;
        }while(withinBounds == false);
        do
        {
		withinBounds = false;
            cout << "Please enter the Y coordinate of your guess (1-5)" << endl;
            cin >> playerGuessY;
            if (playerGuessY > 0 && playerGuessY < 6) withinBounds = true;
            else cout << "Please enter a valid coordinate" << endl;
        }while(withinBounds == false);
        if (board1.guess(playerGuessY - 1, playerGuessX - 1) == true)
        {
            exitBool = true;
            winner = true;
        }
        board1.printBoard(true);

        cout << "Your opponent will now guess" << endl;
        opponent.runGuess(guessNum);
        if (board2.guess(opponent.returnGuessx(guessNum), opponent.returnGuessy(guessNum)) == true)
        {
            exitBool = true;
            winner = false;
        }
        board2.printBoard(false);
        cout << endl << "Press enter to continue";
        cin.ignore();
        getline(cin, contString);
        cout << system("clear");

        guessNum++;
    }while(exitBool == false);

    if (winner == true)
    {
        cout << "You win!" << endl << "Press enter to exit";
        getline(cin, contString);
    }
    else
    {
        cout << "You lost!" << endl << "Press enter to exit";
        getline(cin, contString);
    }
    return 0;
}
