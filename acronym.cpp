//  ola2b by Naomi Igbinovia, CSCI 2170-004, Due: 02/21/22
//  Program ID: acronym.cpp / generates and displays the acronyms
//  for each of the strings in a data file named “acronym.dat”.
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program takes all the strings from a data file,
//  runs through each word with a for loop to find the first letter
//  of each word, capitalizes each of them, and returns them all as an acronym.

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <stdio.h>
#include <cctype>
using namespace std;

//function declaration is made
string getacro(string str);

int main()
{
//main variables are defined
    string str;
    string filename;
    string holder;
    ifstream myIn;

//the input file is asked for, opened, and checked whether the input file is opened correctly
    cout << "Enter file name: ";
    cin >> filename;

    myIn.open(filename.c_str());
    assert(myIn);

//the while loop will run as long as there is a string to obtain in the file
    while (getline(myIn, str))
    {
//the function is called and displayed accordingly
        holder = getacro(str);
        cout << str << " -> " << holder << endl;

    }
//once the entire file is read, the file is closed
    myIn.close();
}

//function is defined
string getacro(string str)
{
//function variables are defined
    string temp = "";
    char val;
    char val2;

//for every character within the string, the for loop will run
    for (int i = 0; i < str.length(); i++)
    {
//if the loop is at the beginning of the string, the first character will be
// captialized and added to the temp string
        if (i == 0)
        {
            val = toupper(str[i]);
            temp += val;
        }
//if the loop is at a space in the string, the loop will move to the next character,
// captialize it, and add it to the temp string
        if (str[i] == (' '))
        {
            val2 = toupper(str[i+1]);
            temp += val2;
        }
    }
//once the string has been read completely, the acronym gathered in the temp string
// is returned to the main function
    return temp;
}
