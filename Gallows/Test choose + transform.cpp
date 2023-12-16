#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>
using namespace std;

int Check_Lenght(string bin)
{
	if (bin.length() % 8 != 0) {
		cout << "Error: The binary string length must be a multiple of 8." << endl;
		return 1;
	}
}

void Show_Word(string bin)
{
	for (size_t i = 0; i < bin.length(); i += 8) {

		string binaryChunk = bin.substr(i, 8);

		char character = static_cast<char>(bitset<8>(binaryChunk).to_ulong());
		cout << "Binary: " << binaryChunk << "  Character: " << character << endl;
	}
}

int main()
{
	srand(time(NULL));
	fstream list;
	list.open("list.txt", ios::in | ios::out | ios::trunc);
	list << "0111001101110111011011110111001001100100\n"
		<< "0110011101101111011101010111001101100101\n"
		<< "0110000101110000011100000110110001100101\n"
		<< "011100000110111101110100011000010111010001101111\n";

	int ch = rand() % 4 + 1;
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
			//binaryString += to_string(character);
			if (to_string(character) == "48")
			{
				binaryString += "0";
			}
			else if (to_string(character) == "49")
			{
				binaryString += "1";
			}
			//cout << to_string(character) << endl;
			Sleep(1);

		} while (character != '\n');
		//cout << binaryString << endl;
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
				if (to_string(character) == "48")
				{
					binaryString += "0";
				}
				else if (to_string(character) == "49")
				{
					binaryString += "1";
				}
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
				if (to_string(character) == "48")
				{
					binaryString += "0";
				}
				else if (to_string(character) == "49")
				{
					binaryString += "1";
				}
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
				if (to_string(character) == "48")
				{
					binaryString += "0";
				}
				else if (to_string(character) == "49")
				{
					binaryString += "1";
				}
			}


		} while (character != '\n');
		break;
	}

	cout << binaryString << endl;

	if (Check_Lenght(binaryString) == 1)
	{
		return 0;
	}

	Show_Word(binaryString);

}