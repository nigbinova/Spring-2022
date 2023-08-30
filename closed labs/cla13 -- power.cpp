//  cla13 by Naomi Igbinovia, CSCI 2170-004, Due: 03/15/2022
//  Program ID: power.cpp / finds and returns an x value to the
//  power of a y value
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program prompts the user for two values, x and y,
//  and displays the result of x raised to the power of y.

#include <iostream>
#include <cmath>
using namespace std;

//  the Power function declaration is  made
float Power(float x, float y);

int main()
{
//  the variables are declared and initalized
    float x, y, product = 0;

//  an x value is asked from the user and stored in variable x
    cout << "Please enter a value for x: " << endl;
    cin >> x;

//  a y value is asked from the user and stored in varibale y
    cout << "Please enter a value for y: " << endl;
    cin >> y;

//  the Power function is called and assigned to the product variable
    product = Power(x,y);

//  the product is displayed
    cout << x << " to the power of " << y << " is "  << product << "." << endl;

    return 0;
}

//  the Power function is defined
float Power(float x, float y)
{
//  if the y value is equal to 0, the product is 1
    if (y == 0)
    {
        return 1;
    }

//  if the y value is equal to 1, the product is the x value
    else if (y == 1)
    {
        return x;
    }

//  if the y value is greater than 1 or less than 0, the proper
//   math is done to compute the product
    else if (y > 1)
    {
        return (x * Power(x, (y-1)));
    }

    else
    {
        return (1/(Power(x,(-y))));
    }

