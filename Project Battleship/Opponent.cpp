#include "Opponent.h"

Opponent::Opponent();
Opponent::~Opponent();
void runGuess(int guessNum)
{
    srand((unsigned)time(0));
    do
    {
        tryAgain = false;
        xGuess = ((rand() % 4) + 1);
        yGuess = ((rand() % 4) + 1);
        if (guessNum > 0)
        {
            for (int i = guessNum; i >= 0; i--)
            {
                if (guessx[i] == xGuess && guessy[i] == yGuess) tryAgain = true;
            }
        }
    }while(tryAgain = true)
    guessx[guessNum] = xGuess;
    guessy[guessNum] = yGuess;
}
