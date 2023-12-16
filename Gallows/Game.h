#pragma once
#include "Game.h"
#include <iostream>
using namespace std;

class Game 
{
public:
	bool CheckExist(string word, string letter);
	bool CheckWin(string word, string letter);
	void CheckLetter(string word, string letter);
	void PrintState(int attempts);
	string CheckLetterCase(string letter);
	bool CheckLetterRep(string letter);
};

