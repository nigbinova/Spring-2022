// cla2 by Naomi Igbinovia, CSCI 2170-004, Due: 01/24/2022
// Program ID: conversion.cpp / USD amount converted to Euro
// Author: Naomi Igbinovia
// Installation: MTSU
// Remarks: This program takes a USD value given by the user,
//  computes the value to Euro, and displays the output.

#include <iostream>
#include <iomanip>
using namespace std;

const float  euro = 0.87;
int main()
{
    float initAmount;
    float  newAmount;

    //prompt for a US Dollar value
    cout << "Hello! Please enter an amount of US Dollar that you'd like to convert: ";
    cin >> initAmount;
    cout << "You entered $" << initAmount<< fixed << setprecision(2);
    cout << '\n' << endl;

    //convert to the Euro value
    newAmount = (euro * initAmount);

    //display output
    cout << "1 dollar = 0.87 EUR." << endl;
    cout << initAmount << fixed << setprecision(2) << " US Dollar is equivalent to " << newAmount << fixed << setprecision(2) << " EUR." << endl;

    return 0;
}
       
