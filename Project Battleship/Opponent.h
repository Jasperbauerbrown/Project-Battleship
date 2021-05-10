#pragma once
#ifndef OPPONENT
#define OPPONENT
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Opponent {
private:
	int xGuess;
	int yGuess;
	bool tryAgain;
public:
	Opponent();
	~Opponent();
	int shipsx[5];
	int shipsy[5];
	vector <int> guessx();
	vector <int> guessy();
	void runGuess(int);
};
#endif
