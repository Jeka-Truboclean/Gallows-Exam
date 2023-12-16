#include "Word.h"
#include "Game.h"
#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <chrono>
#include <time.h>
using namespace std;

// Setting timer
#define start_clock chrono::system_clock::now();
#define end_clock chrono::system_clock::now();
#define calculat_time chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

// Main game
int main()
{
	srand(time(NULL));
	int ch_again; // Choosing between (play again / exit)
	int count_trys = 0; // Trys counter

	do
	{
		auto start_time = start_clock; // Start timer
		Game game; // Main object for a game
		int attempts = 0; // Failed letters counter
		string letter; // Letters container
		Word word; // Object word to get WORD
		word.Fill(); // Fill file with words in binary system

		// Main guessing word system
		do
		{
			game.PrintState(attempts);
			cout << "Word -> ";
			game.CheckLetter(word.GetWord(), letter);
			cout << "Enter letter: ";
			string cash; // Created for getting letter one by one and for better functionality
			cin >> cash;
			letter += cash;
			
			if (game.CheckLetterRep(letter) == 1)
			{
				if (game.CheckExist(word.GetWord(), cash) == 0)
				{
					attempts++;
				}
				cout << "Word -> ";
				game.CheckLetter(word.GetWord(), letter);
				system("cls");
			}
			else
			{
				system("cls");
				cout << "Enter another!\n";
				letter.pop_back();
			}
			if (game.CheckWin(word.GetWord(), letter) == 1)
			{
				break;
			}
		} while (attempts < 6);

		// Results
		game.PrintState(attempts);
		if (game.CheckWin(word.GetWord(), letter) == 1)
		{
			cout << "\tYou win!!!\n";
		}
		cout << "Word -> " << word.GetWord() << endl;
		cout << "Letters: " << letter << endl;
		auto end_time = end_clock;
		auto elapsed_time = calculat_time;
		cout << "Time: " << elapsed_time.count() << " seconds." << endl;

		// Ask for a repetition
		cout << "Try again?\n1 - Again\n2 - Exit\n> ";
		do
		{
			cin >> ch_again;
			if (ch_again == 1) { system("cls"); count_trys++; }
			else if (ch_again != 2)
			{
				system("cls");
				cout << "Choose another variant!" << endl;
				game.PrintState(attempts);
				if (game.CheckWin(word.GetWord(), letter) == 1)
				{
					cout << "\tYou win!!!\n";
				}
				cout << "Word -> " << word.GetWord() << endl;
				cout << "Letters: " << letter << endl;
				cout << "Time: " << elapsed_time.count() << " seconds." << endl;
				cout << "Try again?\n1 - Again\n2 - Exit\n> ";
			}
		} while (ch_again != 1 && ch_again != 2);
	} while (ch_again != 2);

	cout << "Try(s): " << count_trys + 1 << "\n";
	
	return 0;
}