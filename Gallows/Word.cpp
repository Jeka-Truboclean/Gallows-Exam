#include "Word.h"
#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

// Filling file with words in binary system
Word::Word()
{
	srand(time(NULL));
	list.open("list.txt", ios::in | ios::out | ios::trunc);
	list << "0111001101110111011011110111001001100100\n"
		<< "0110011101101111011101010111001101100101\n"
		<< "0110000101110000011100000110110001100101\n"
		<< "011100000110111101110100011000010111010001101111\n" 
		<< "0110001101101111011011010111000001110101011101000110010101110010\n" 
		<< "0111001101101111011011100110100101100011\n" 
		<< "011000100111010101110100011101000110010101110010011001100110110001111001\n";
}

// Choosing word for a game randomly and decode
void Word::Fill()
{
	int ch = rand() % 7 + 1;
	char character = '\0';
	int slash_n = 0;
	string binaryString;
	switch (ch)
	{
	case 1:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			if (character != '\n')
			{
				binaryString += character;
			}
			Sleep(1);

		} while (character != '\n');
		break;
	case 2:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 1)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 1)
			{
				binaryString += character;
			}


		} while (character != '\n');
		break;
	case 3:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 2)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 2)
			{
				binaryString += character;
			}


		} while (character != '\n');
		break;
	case 4:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 3)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 3)
			{
				binaryString += character;
			}
		} while (character != '\n');
		break;
	case 5:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 4)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 4)
			{
				binaryString += character;
			}
		} while (character != '\n');
		break;
	case 6:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 5)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 5)
			{
				binaryString += character;
			}
		} while (character != '\n');
		break;
	case 7:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			Sleep(1);
			if (character == '\n' && slash_n == 6)
			{
				break;
			}
			else if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 6)
			{
				binaryString += character;
			}
		} while (character != '\n');
		break;
	}

	//cout << binaryString << endl;

	if (binaryString.length() % 8 != 0) {
		cout << "Error: The binary string length must be a multiple of 8." << endl;
		exit(1);
	}

	for (size_t i = 0; i < binaryString.length(); i += 8) {

		string binaryChunk = binaryString.substr(i, 8);

		character = static_cast<char>(bitset<8>(binaryChunk).to_ulong());
		//cout << "Binary: " << binaryChunk << "  Character: " << character << endl;
		word += character;
	}
}

string Word::GetWord() // Get word for using
{
	return word;
}
