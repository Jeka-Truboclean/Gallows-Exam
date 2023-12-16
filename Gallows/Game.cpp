#include "Game.h"
#include <iostream>
using namespace std;

bool Game::CheckExist(string word, string letter) // Check if a letter is in a word
{
	letter = CheckLetterCase(letter);
	for (int i = 0; i < size(word); i++)
	{
		if (word[i] == letter[0])
		{
			return 1;
		}
	}
	return 0;
}

bool Game::CheckWin(string word, string letter) // Check if word is done
{
	letter = CheckLetterCase(letter);
	string cash;
	for (int i = 0; i < size(word); i++)
	{
		for (int j = 0; j < size(letter); j++)
		{
			if (word[i] == letter[j])
			{
				cash += word[i];
			}
		}
	}
	if (cash == word)
	{
		return 1;
	}

	return 0;
}

void Game::CheckLetter(string word, string letter) // Check and print guassing word with letter
{
	letter = CheckLetterCase(letter);
	bool space;
	for (int i = 0; i < size(word); i++)
	{
		space = 0;
		for (int j = 0; j < size(letter); j++)
		{
			if (word[i] == letter[j])
			{
				cout << letter[j];
				space = 1;
			}
		}
		if (space == 0)
		{
			cout << "_";
		}
	}
	cout << endl;
}

string Game::CheckLetterCase(string letter) // Check if letter case is down
{
	for (int i = 0; i < size(letter); i++)
	{
		if (isupper(letter[i]))
		{
			letter[i] = tolower(letter[i]);
		}
	}
	return letter;
}

bool Game::CheckLetterRep(string letter) // Check if letter has already been used
{
	for (int i = 0; i < letter.length(); i++)
	{
		for (int j = i + 1; j < letter.length(); j++)
		{
			if (letter[i] == letter[j])
			{
				//cout << letter[i] << "\t";
				return false;
			}
		}
	}
	return true;
}

// Print state of the hanged on the gallows
void Game::PrintState(int attempts)
{
	switch(attempts)
	{
	case 0:
		cout << "/==========\n|         |\n|         |\n|\n|\n|\n|\n|\n|\n|\n|\n/\\\n";
		break;
	case 1:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|\n|\n|\n|\n|\n|\n|\n/\\\n";
		break;
	case 2:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|         |\n|         |\n|\n|\n|\n|\n|\n/\\\n";
		break;
	case 3:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|        /|\n|       / |\n|\n|\n|\n|\n|\n/\\\n";
		break;
	case 4:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|        /|\\\n|       / | \\\n|\n|\n|\n|\n|\n/\\\n";
		break;
	case 5:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|        /|\\\n|       / | \\\n|        /\n|       /\n|\n|\n|\n/\\\n";
		break;
	case 6:
		cout << "/==========\n|         |\n|         |\n|       (+.+)\n|        /|\\\n|       / | \\\n|        / \\\n|       /   \\\n|\n|\n|\n/\\\n\tYou lost!!!\n";
		break;
	}
}
