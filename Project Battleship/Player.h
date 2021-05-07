#pragma once
#ifndef PLAYER
#define PLAYER
#include "Opponent.h"
using namespace std;
class Player
{
public:
	int shipsx[5];
	int shipsy[5];
	vector <int> guessx();
	vector <int> guessy();
};
#endif
