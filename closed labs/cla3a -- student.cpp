// cla3a by Naomi Igbinovia, CSCI 2170-004, Due: 01/27/2022
// Program ID: student.cpp / total hour amount used to determine
// class rank
// Author: Naomi Igbinovia
// Installtion: This program takes an hour integer amount inputted
// by the user to determine and display the correct class rank.

#include <iostream>
using namespace std;

int main()
{
    int totalHours;

    cout << "Please enter your total credit hours entered: ";
    cin >> totalHours;

    if (totalHours < 0)
    {
        cout << "This is an invalid input.";
    }

    else if (totalHours <= 15)
    {
        cout << "You are a freshman.";
    }

    else if (totalHours > 15 && totalHours <= 45)
    {
        cout << "You are a sophmore.";
    }
    else if (totalHours > 45 && totalHours <= 75)
    {
        cout << "You are a junior.";
    }
    else
    {
        cout << "You are a senior.";
    }

    return 0;
}
