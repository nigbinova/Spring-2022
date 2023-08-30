//  cla11 by Naomi Igbinovia, CSCI 2170-004, Due: 02/24/2022
//  Program ID: books.cpp / sorts book titles in ascending order and searches
//  for title locations
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program opens a file of book titles, sorts and prints said
//  titles in ascending order, and lets the user search for the book's location
//  with their input.

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//  arrray size is declared and initalized
const int SIZE = 30;

//  functions are declared
void ReadData(ifstream & myIn, string titles[], int& size);
void DisplayData (const string titles[], int size);
void SortTitles(string data[], int size);
int LinearSearch (const string titles[], int size, string toFind);

int main()
{
//  variables are declared
    ifstream myIn;
    string titles[SIZE];
    int numBook;
    string oneTitle;
    int index;
    int size;
    string toFind;
    int loc;

//  data file is opened and checked if it was opened correctly
    myIn.open("booktitles.dat");
    assert(myIn);

//  functions are called
    ReadData(myIn, titles, numBook);

    SortTitles (titles, numBook);

    DisplayData(titles, numBook);

//  input statement is declared to the user and stored in the toFind variable
    cout << "Enter the book title: " << endl;
    getline(cin,toFind);

//  while the user is inputting book titles to find
    while(toFind.empty() == false)
    {
//  the linear search function is called to try and find the user's title
        loc = LinearSearch(titles, numBook, toFind);

//  if the book title is found, the book's location is found
        if (loc >=0)
        {
            cout << "The book is at location: " << ((loc)+1) << "." << endl;
        }

// if not, the program returns a messages stating the title couldn't be found
        else
        {
            cout << "The book is not in the collection." << endl << endl;
        }

//  the user's input is asked for again until the user enters nothing
        cout << "Enter the book title: " << endl;
        getline(cin,toFind);
    }

//  the data file is closed
    myIn.close();
    return 0;
}

//  the data reading function is defined
void ReadData(ifstream & myIn, string titles[], int& size)
{
//  the size variable is initalized
    size = 0;

//  while the array size hasn't been met and there's a book title to read in
    while ((size < SIZE) && getline(myIn, titles[size]))
    {

//  the size is counted
        size++;
    }
}

//  the display data function is defined
void DisplayData (const string titles[], int size)
{

//  each title is given a location number and printed alongside said location number
//  in the display
    for (int i = 0; i < size; i++)
    {
        cout << i+1 << " : " << titles[i+1] << endl;
    }
}

//  the sorting function is defined
void SortTitles(string titles[], int size)
{
//  variables are defined
    int minIndex;
    string temp;

//  before any titles are run through this for loop, the start of the array is set to 0
    for (int i = 0; i < size -1; i++)
    {
        minIndex = i;
// for every title that runs through the program after the start is initalized
//  if the current title ranks higher than the current start of the array,
//  the array is adjusted
        for (int j = i + 1; j < size; j++)
        {
            if (titles[j] < titles[minIndex])
                minIndex = j;
        }
//  if the minIndex doesn't match the start of the index, a temp string is brought
//  in to fix it
        if (minIndex != i)
        {
            temp = titles[minIndex];
            titles[minIndex] = titles[i];
            titles[i] = temp;
        }
    }
}

//  the linear search is defined
int LinearSearch (const string titles[], int size, string toFind)
{
//  variables are defined and initalized
    int position = -1;
    bool found = false;
    int index;

    index=0;

//  while the title is not found and the array hasn't reached the end of its size
    while (!found && index < size)
    {
//  if the index matches the user string input, found is returned as true and the
//   postion is set the found index
        if (titles[index] == toFind)
        {
            found = true;
            position = index;
        }
//  if not, the program is keeps looking for the user string input
        index++;
    }

//at the end, the postion is either returned as the found postion or -1
    return position;
}

