#pragma once
#ifndef OPPONENT
#define OPPONENT
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Opponent {
public:
	int shipsx[5];
	int shipsy[5];
	vector <int> guessx();
	vector <int> guessy();
};
#endif
