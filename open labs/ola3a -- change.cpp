//  ola3a by Naomi Igbinovia, CSCI 2170-004, Due: 03/02/2022
//  Program ID: change.cpp / inital values are converted into change
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program takes a given value from a data file and
//  uses a function to convert into change and displays the results.

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//declarations are made
void ComputeCoin(int coinValue, int& num, int& amountLeft);

int main()
{
//variables are defined
    int coinValue;
    int num;
    int amountLeft;


    ifstream myIn;

//input file is opened and checked whether the input file is opened correctly
    myIn.open("coins.dat");
    assert(myIn);

//while is run until there's no more data in the file
//the while loop displays the inital value and the new change after the function
//is called a few times

    while (myIn >> amountLeft)
    {
        cout <<  amountLeft << " cents can be changed using: " << endl;
        ComputeCoin(25, num, amountLeft);
        cout << num << " quarter(s)" << endl;
        ComputeCoin(10,  num,  amountLeft);
        cout << num << " dime(s)." <<  endl;
        cout << amountLeft << " cent(s)" << endl;
        cout << '\n' << endl;
    }

//the data file is closed
    myIn.close();
    return 0;
}

//the function is defined
void ComputeCoin(int coinValue, int& num, int& amountLeft)
{
//function variable is initialized
    num = 0;

//while the amountLeft minus the current coin value is greater than 0,
//a coin in the current currency would be counted
    while (amountLeft - coinValue >= 0)
    {
        amountLeft = amountLeft - coinValue;
        num++;
    }
}
