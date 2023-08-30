// cla4a by Naomi Igbinovia, CSCI 2170-004, Due: 02/01/2022
// Program ID: leapyear.cpp / years from a file are calculated
//  as a leap year or not.
// Author: Naomi Igbinovia
// Installtion: MTSU
// Remarks: This program takes all the years in an data file,
// checks to make sure the file was opened correctly, then with
// a while loop, every year is either caluclated and displayed
//  as a leap year with "yes" or not with "no". Then the file is closed.

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
//variables are defined 
    int year;
    ifstream myIn;

//input file is opened and checked whether the input file is opened correctly
    myIn.open("years.dat");
    assert(myIn);

//while is run until no data is left in the file
    while (myIn >> year)
    {
//if year is divisible by 4 but not 100, "yes" is the displayed output
        if (year % 4 == 0 && year % 100 != 0)
        {
            cout << "yes";
            cout << '\n';
        }
//if year is divisible by 100 and 400, "yes" is the displayed output
        else if (year % 100 == 0 && year % 400 == 0)
        {
            cout << "yes";
            cout << '\n';
        }
//otherwise, no is the displayed output
        else
        {
            cout << "no";
            cout << '\n';
        }
    }
//the input file is closed
    myIn.close();

    return 0;
}
