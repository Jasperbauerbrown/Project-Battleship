#pragma once
#ifndef PLAYER
#define PLAYER
#include "Opponent.h"
using namespace std;
class Player
{
	int shipsx[6];
	int shipsy[6];
	vector <int> guessx();
	vector <int> guessy();
};
#endif
