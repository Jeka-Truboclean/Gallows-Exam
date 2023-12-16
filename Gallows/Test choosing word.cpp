#include <iostream>
#include <bitset>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;



int main()
{
	fstream list;
	list.open("list.txt", ios::in | ios::out | ios::trunc);
	list << "0111001101110111011011110111001001100100\n"
		<< "0110011101101111011101010111001101100101\n"
		<< "0110000101110000011100000110110001100101\n"
		<< "011100000110111101110100011000010111010001101111\n";

	/*
	char character = '\0';
	int n = 42;
	list.seekg(n, ios::beg);
	do
	{
		character = '\0';
		list.get(character);
		cout << character;
		Sleep(1);

	} while (character != '\n');
	*/

	int ch;
	cout << "Choose\n> ";
	cin >> ch;
	char character = '\0';
	int slash_n = 0;
	switch (ch)
	{
	case 1:
		list.seekg(0, ios::beg);
		do
		{
			character = '\0';
			list.get(character);
			cout << character;
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
			if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 1)
			{
				cout << character;
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
			if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 2)
			{
				cout << character;
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
			if (character == '\n')
			{
				character = '\0';
				slash_n++;
				continue;
			}
			if (slash_n == 3)
			{
				cout << character;
			}


		} while (character != '\n');
		break;
	}

}