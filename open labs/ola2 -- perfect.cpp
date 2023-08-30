//  ola2a by Naomi Igbinovia, CSCI 2170-004, Due: 02/21/22
//  Program ID: perfect.cpp / displays all the perfect numbers
//  that is between 0 and 10000 exclusive
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program goes through all numbers between 1 and 9999
//  and uses and for and while loop to check if there are any perfect
//  numbers there. If there are, they are displayed.

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
//the variables are defined
    int div;
    int sum;

//the title statement is displayed
    cout << "These are the perfect numbers between 1 and 9999: " << endl;

//for every number starting at 1 until 9999 is reached, this for loop will run
    for (int num = 1; num <= 9999; num++)
    {
//the variables are initalized
        div = 1;
        sum = 0;

//while the potential divisor is less than the number, the loop will run
        while (div < num)
        {
//if the remainder of the number divided by the potential divisor is 0,
//the potential divisor is now "confirmed" and is added to the sum to be
// checked if it's a perfect number
            if (num % div == 0)
                sum += div;

//regardless if the divisor checks out or not, the divisor will go up to check
//for my potential divisors
            div++;
        }

//after the while loop, if the final sum is equal to the number in question,
//the perfect number is confirmed and displayed
        if (sum == num)
        {
            cout << num << endl;
        }
    }
    return 0;
}
