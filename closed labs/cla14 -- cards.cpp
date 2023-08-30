//  cla14 by Naomi Igbinovia, CSCI 2170-004, Due: 03/22/2022
//  Program ID: struct.cpp / forms and displays a deck of cards
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program uses an array of structs to form and
//  display a deck of cards

#include <iostream>
#include <iomanip>
using namespace std;

//  the struct is declared
struct CardInfo
{
    string suit;
    int value;
    int points;
};

//  array size is declared and initalized
const int SIZE = 52;

int main()
{
//  the array of structs is declared
    CardInfo deck[SIZE];

//  for every element in the array, the suit name, value, and point amount
//  are assigned to a element range
    for (int i = 0; i < SIZE; i++)
    {

//  elements 0 - 12 are assigned the Diamond suit, with the associated values
//  and points
        if (i < 13)
        {
            deck[i].suit = "Diamond";
            deck[i].value = (i+1);
            deck[i].points = 0;

//  if the element is equal to 10, the points are set to -100
            if (i == 10)
            {
                deck[i].points = -100;
            }

        }

//  elements 13 - 25 are assigned the Club suit with the associated values
//  and points
        else if ((i >= 13) && (i < 26))
        {
            deck[i].suit = "Club";
            deck[i].value = (i-12);
            deck[i].points = 0;
        }
//  elements 26 - 38 are assigned the Heart suit with the associated values
//  and points
        else if ((i >= 26) && (i < 39))
        {
            deck[i].suit = "Heart";
            deck[i].value = (i-25);

//  elements 26 - 34 are reassigned 5 as their points, and elements 35 - 38 are
//  reassigned 10 as their points
            if ((i >= 26) && (i < 35))
            {
                deck[i].points = 5;
            }
            else
            {
                deck[i].points = 10;
            }
        }

//  the remaining elements are assigned the Spade suit with the associated values
//  and points
        else
        {
            deck[i].suit = "Spades";
            deck[i].value = (i-38);
            deck[i].points = 0;

//  if the element is equal to 50, the points are reassigned to 100
            if (i == 50)
            {
                deck[i].points = 100;
            }
        }
    }

//  the title is displayed
    cout << left << setw(10) << "SUIT" << left << setw(10) << "VALUE" << left << setw(10) << "POINTS" << endl;

//  for every element in the array
    for (int i = 0; i < SIZE; i++)
    {

//  if the value is equal to 1, the value is displayed as "A" for ace
        if (deck[i].value == 1)
        {
            cout << left << setw(10) << deck[i].suit << left << setw(10) << "A" << left << setw(10) << deck[i].points << endl;
        }

//  if the value is equal to 11, the value is displayed as "J" for jack
        else if (deck[i].value == 11)
        {
            cout << left << setw(10) << deck[i].suit << left << setw(10) << "J" << left << setw(10) << deck[i].points << endl;
        }

//  if the value is equal to 12, the value is displayed as "Q" for queen
        else if (deck[i].value == 12)
        {
            cout << left << setw(10) << deck[i].suit << left << setw(10) << "Q" << left << setw(10) << deck[i].points << endl;
        }

//  if the value is equal is 13, the value is displayed as "K" for king
        else if (deck[i].value == 13)
        {
            cout << left << setw(10) << deck[i].suit << left << setw(10) << "K" << left << setw(10) << deck[i].points << endl;
        }
//  if none of the values match the previous if statements, the value is displayed as it is
        else
        {
            cout << left << setw(10) << deck[i].suit << left << setw(10) << deck[i].value << left << setw(10) << deck[i].points << endl;
        }
    }

}
