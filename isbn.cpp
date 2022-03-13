//  ola3b by Naomi Igbinovia, CSCI 2170-004, Due: 03/02/2022
//  Program ID: isbn.cpp / checks if potential ISBN numbers are valid
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program reads a data file of ISBN numbers, converts their strings
//  into integers, calculates their check digits and checks if each ISBN number is valid
//  or not

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <stdlib.h>
using namespace std;

//the function declarations are made
bool IsValidISBN(string isbn);
int CheckDigit(string isbn);

int main()
{
//the variables are declared
    string isbn;
    bool isValid;
    ifstream myIn;

//the data file is opened and checked whether it was opened correctly or not
    myIn.open("isbn.dat");
    assert(myIn);

//while there is data to be read in from the data file to isbn string, the
//isValidISBN function is called.If the function returns true, it's displayed
//as a valid ISBN number. If false, it's displayed as an invalid ISBN number
    while ( myIn >> isbn)
    {
        isValid = IsValidISBN(isbn);

        if ( isValid )
            cout << isbn << " is a valid ISBN number" << endl;
        else
            cout << isbn << " is not a valid ISBN number" << endl;
    }

//once the main function is done, the datafile is closed
    myIn.close();
    return 0;
}

//the CheckDigit function is defined
int CheckDigit(string isbn)
{
//the function variables are declared and initalized
    int holder[13];
    int temp = 0;
    int sum = 0;

//for every character in the current isbn string, each is converted into an integer
// and stored in the holder array
    for (int i = 0; i < 13; i++)
    {
        temp = (isbn[i]-'0');
        holder[i] = temp;
    }

//for every number in the holder array, if the array location is even, the number in
//its place is mutlipled by 1 and added to the sum. If the array location is odd, the
//number in its place is multipled by 3 and added to the sum
    for (int i = 0; i < 12; i++)
    {
        if (i % 2 == 0)
        {
            temp = holder[i] * 1;
            sum = sum + temp;
        }
        else if (i % 2 != 0)
        {
            temp = holder[i] * 3;
            sum = sum + temp;
        }
    }
//the sum after the for loop calculation is further calucated to compute the check number,
// then the check number is returned
    sum = sum % 10;
    sum = 10 - sum;
    if (sum == 10)
    {
        sum = 0;
    }

    return sum;
}

//the IsValidISBN functin is defined
bool IsValidISBN(string isbn)
{
//the functin varibles are declared
    int holder[13];
    int temp;

//every character in the ISBN string is converted into integers again
    for (int i = 0; i < 13; i++)
    {
        temp = (isbn[i]-'0');
        holder[i] = temp;
    }
//the last number of the ISBN is made a variable
    int finalnum = holder[12];

//if the last number matches the check number, true is retuned. Otherwise, false is returned
    if (finalnum == (CheckDigit(isbn)))
    {
        return true;
    }

    else
    {
        return false;
    }

}
