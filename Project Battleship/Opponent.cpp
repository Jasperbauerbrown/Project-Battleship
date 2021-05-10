#include "Opponent.h"

Opponent::Opponent();
Opponent::~Opponent();
int runGuess(int guessNum)
{
    srand((unsigned)time(0));
    do
    {
        tryAgain = false;
        xGuess = ((rand() % 4) + 1);
        yGuess = ((rand() % 4) + 1);
        if (guessx[guessNum] == xGuess && guessy[guessNum] == yGuess) tryAgain = true;
    }while(tryAgain = true)
}
