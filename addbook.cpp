//  cla12 by Naomi Igbinovia, CSCI 2170-004, Due: 03/04/2022
//  Program ID: addbook.cpp / allows user to add new books to a collection
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program reads in the displays all the books in its current
//  collection. The user is asked to under a book title to be added to the collection.
//  If the book is already in the collection, the program returns a statement explaining
//  so. If the user inputs a book title with a location less than 0, the program returns
//  an error message. If the user inputs a new book title and a valid location, the new
//  book is added to collection. The user is asked to add books until only a newline
//  character is read.

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

//the constant for the array is declared and initalized
const int SIZE =  50;

//the function declarations are made
void ReadData(ifstream & myIn, string titles[], int& size);
void DisplayData(const string titles[], int size);
void AddAtLocation(string titles[],int &size, string toAdd, int loc);

int main()
{
//the variables are defined here
    ifstream myIn;
    string titles[SIZE];
    string oneTitle;
    int index;
    int size;
    string toAdd;
    int loc;

//the data file is opened and checked whether it was opened correctly or not
    myIn.open("booktitles.dat");
    assert(myIn);

//the ReadData function is called into the main to read every title from the
//datafile into the titles array
    ReadData(myIn, titles, size);

//the DisplayData function is called into the mian to display all the books in
//the current collection (stored in the array)
    cout << "Books in the collection: " << endl;
    DisplayData(titles,size);

//the user is asked to enter a book title to be added to the collection
//the user's input is then stored in the toAdd string variable
    cout << '\n';
    cout << "Please enter the title to add to the collection:  " << endl;
    getline(cin, toAdd);

//while is run until the user enters no title to be added to collection
    while (toAdd.empty() == false)
    {

//the user is asked to enter a location for the book to be potentially stored
        cout << "Please enter the location to add the new book: " << endl;
        cin >> loc;
        cin.ignore(100, '\n');

//the AddAtLocation function is run to determine if the book can be stored or not
        AddAtLocation(titles, size,toAdd, loc-1);

//the user is asked again to enter a book title to be added to the collection to
//keep the while loop going
        cout << '\n';
        cout << "Please enter the title to add to the collection: " << endl;
        getline(cin, toAdd);
    }

//the data file is closed
    myIn.close();
    return 0;

}

//the ReadData function is defined
void ReadData(ifstream & myIn, string titles[], int& size)
{
//size is declared
    size = 0;

//while the current size hasn't reached the constant maximum and there's still contents
//in the datafile to be read into the titles array, the size counter will increase
    while ((size < SIZE) && getline(myIn, titles[size]))
    {
        size++;
    }
}

//the DisplayData function is defined
void DisplayData (const string titles[], int size)
{
//for every book title in the array, if the title isn't a newline character, the title
//is displayed with a count number
    for (int i = 0; i < size; i++)
    {
        if (titles[i] != "")
        {
            cout << i+1 << " : " << titles[i] << endl;
        }
    }
}

//the AddAtLocation function is defined
void AddAtLocation(string titles[],int &size, string toAdd, int loc)
{

//the function variables are declared and initalized
    bool found = false;
    int index = 0;

//if the location given is less than one, the book cannot be stored and an error
// messgae is returned
    if (loc <= -1)
    {
        cout << "This book cannot be stored." << endl;
    }


    else
    {
//while the location is being checked if the book is already stored,
//if the book is found, found becomes true and a message that it's already
//in the collection
        while (!found && index < size)
        {
            if (titles[index] == toAdd)
            {
                found = true;
                cout << "The book is already in the collection. Insertion not carried out." << endl;
            }

        index++;
        }

//if the location number cannot be found, the space is made for the book in
// the array and the new book is added and displayed in an updated collection
        if (!found)
        {


            for (int i = size; i >= loc; i--)
            {
                titles[i+1] = titles[i];
            }
            titles[loc] = toAdd;
            size = size+1;

            cout << '\n';
            cout << "After insertion: " << endl;
            DisplayData(titles, size);

        }
    }
}
