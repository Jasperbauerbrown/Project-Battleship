#pragma once
#ifndef OPPONENT
#define OPPONENT
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class opponent {
public:
    opponent();
    ~opponent();
    int shipsx[5];
    int shipsy[5];
    vector <int> guessx;
    vector <int> guessy;
    void runGuess(int);
    int returnGuessx(int);
    int returnGuessy(int);
    int xGuess;
    int yGuess;
    bool tryAgain;
};
#endif
