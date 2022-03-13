//  cla10 by Naomi Igbinovia, CSCI 2170-004, Due: 02/22/22
//  Program ID: frequency.cpp / counts how many of each alphabet character is
//  in a user given string and displays the frequency
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Reamrks: This program takes a user given string, counts how many of each alphabet
//  character is in the string, and displays the results

#include <iostream>
#include <string>
using namespace std;

//array size is declared and initalized
const int SIZE = 26;

int main()
{
// variables are declared and initalized
    string seq;
    char ch;
    int frequency [SIZE] = {};
    int count;
    string alpha;

    count = 0;

// the user's input string is asked for and stored in the seq string variable
    cout << "Enter text: ";
    getline(cin, seq);

// for every character within the length of the seq string,
    for (int i = 0; i < seq.length(); i++)
    {

// all the characters are made lowercase
        ch = tolower(seq[i]);

// the chval is assigned to the current character being read in the string,
        int chval =  ch;

// the frequency for that character is counted for
        int index = chval-97;

        if (chval >= 97 && chval <= 122)
        {
            frequency[index] += 1;

            chval = 0;
        }
    }

// for every letter in the alphabet, the program will display the frequency
// of each letter in the given string
    for (int i = 0; i < 26; i++)
    {
        alpha = char('a'+i);
        cout << alpha << " : " << frequency[i] << endl;
    }
}
