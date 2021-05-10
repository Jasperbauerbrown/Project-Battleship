#include "Opponent.h"
Opponent::opponent();
Opponent::~opponent();
void Opponent::runGuess(int guessNum)
{
    srand((unsigned)time(0));
    do
    {
        opponent.tryAgain = false;
        opponent.xGuess = ((rand() % 4) + 1);
        opponent.yGuess = ((rand() % 4) + 1);
        if (guessNum > 0)
        {
            for (int i = guessNum; i >= 0; i--)
            {
                if (opponent.xGuess == opponent.guessx[i] && opponent.yGuess == opponent.guessy[i]) opponent.tryAgain = true;
            }
        }
    } while (opponent.tryAgain == true);
}
