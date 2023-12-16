#pragma once
#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class Word
{
protected:
	fstream list;
	string word;
public:
	Word();
	void Fill();
	string GetWord();
};

