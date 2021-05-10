#include "Opponent.h"
Opponent::opponent();
Opponent::~opponent();
void Opponent::runGuess(int guessNum)
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
                if (xGuess == guessx[i] && yGuess == guessy[i]) tryAgain = true;
            }
        }
    } while (tryAgain == true);
    guessx[guessNum] = xGuess;
    guessy[guessNum] = yGuess;
}
