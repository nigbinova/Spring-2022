//  cla7 by Naomi Igbinovia, CSCI 2170-004, Due: 02/15/2022
//  Program ID: read.cpp / book data is read into a program
//  and displayed in a table format.
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program takes book data in a data file,
//  checks to make sure the file was opened correctly, then
//  with a while loop, the title, author, rating, price, and
//  year are displayed in a table format. Then the file is
//  closed and the total count is displayed.

#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
using namespace std;

//declarations are made
void DisplayTableHeading();
void DisplayOneLine(string title, string author, float rating, float price, int year);

int main()
{
//all variables are defined and initalized
    int month;
    int day;
    int year;
    string title;
    string author;
    float rating;
    float price;
    int count;


    count = 0;
    month = 0;
    day = 0;
    year = 0;
    rating = 0;
    price = 0;

//input file is opened and checked whether the input file is opened correctly
    ifstream myIn("library.dat");
    assert(myIn);

//DisplayTableHeading is called
    DisplayTableHeading();

//while there is a title to be read, the title, author, rating, month, day, year, and price will be read into the DisplayOneLine function to display all the information in the required format
    while (getline(myIn,title))
    {
        getline(myIn, author);

        myIn >> rating;
        myIn.ignore(100, '\n');

        myIn >> month >> day >> year;

        myIn >> price;
        myIn.ignore(100,'\n');

        DisplayOneLine(title, author, rating, price, year);

        count++;
    }
//the input file is closed
    myIn.close();

//the total count of books are displayed
    cout << "There are a total of " << count << " books." << endl;
    return 0;
}

// this function prints the heading of the output table of information
void DisplayTableHeading()
{
    cout << left;
    cout << fixed << showpoint << setprecision(2);
    cout << setw(25) << "TITLE" << setw(25) << "AUTHOR" << "\t"
        << "RATING" << "\t" << "PRICE" << "\t" << "YEAR"<< endl << endl;
    return;
}

// this function prints one line of information for one book
void DisplayOneLine(string title, string author, float rating, float price, int year)
{
    cout << setw(25) << title << setw(25) << author << "\t" << rating << "\t"
    << price << "\t" << year << endl;
    return;
}

