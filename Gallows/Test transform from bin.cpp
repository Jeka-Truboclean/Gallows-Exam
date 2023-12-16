#include <iostream>
#include <bitset>
#include <string>
using namespace std;


int Check_Lenght(string bin)
{
    if (bin.length() % 8 != 0) {
        cerr << "Error: The binary string length must be a multiple of 8." << endl;
        return 1; 
    }
}

void Show_Word(string bin)
{
    for (size_t i = 0; i < bin.length(); i += 8) {

        string binaryChunk = bin.substr(i, 8);

        char character = static_cast<char>(bitset<8> (binaryChunk).to_ulong());
        cout << "Binary: " << binaryChunk << "  Character: " << character << endl;
    }
}

int main() {
    string binaryString;
    cout << "Enter a binary string: ";
    getline(cin, binaryString, '\n');

    if (Check_Lenght(binaryString) == 1)
    {
        return 0;
    }

    Show_Word(binaryString);

    return 0;
}