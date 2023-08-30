// cla5 by Naomi Igbinovia, CSCI 2170-004, Due: 02/08/2022
// Program ID: count.cpp / word counter
// Author: Naomi Igbinovia
// Installtion: MTSU
// Remarks: This program takes an string inputted from the user,
// counts how many spaces are found, adds 1 to the total of
// spaces found, and returns the total count as the total number
// of words found in the string.

#include <iostream>
#include <string>
using namespace std;
int  main()
{
//define the variables.
    string::size_type words;
    string text;
    int totalcount;

//ask the user to input a line of text for the program to read.
    cout << "Please enter a line of text: ";
    getline(cin, text);
    totalcount = 0;

//set the words variable to find every space in the given string.
    words = text.find (" ");

//find and count every space character found in the string.
//then add one more to the total count to account for all the words in the string.
    while (words != string::npos)
    {
        totalcount++;
        words = text.find(" ", words+1);
    }
    totalcount++;
//display how many total words were found in the output.
    cout << "There are " << totalcount << " words in this sentence.";
    return 0;
}
