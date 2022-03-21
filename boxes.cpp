//  ola4 by Naomi Igbinovia, CSCI 2170-004, Due: 03/14/2022
//  Program ID: boxes.cpp / counts how many boxes each class
//  brings in and determines a winner
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program opens a data file of class names and box amounts,
//  sorts and counts their totals, and prints the results in ascending and the winner

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
using namespace std;

//  array size is declared and initalized
const int SIZE = 50;

//  functions are declared
void ReadData (ifstream & myIn, string names[], int boxes[], int& size);
void FindWinner(string names[], int boxes[], int size, int& largest, string& largest2);
void DisplayData (string names[], int boxes[], int size, int largest, string& largest2);
int LinearSearch (const string names[], int size, string toFind);

int main()
{
//   variables are declared
    ifstream myIn;
    string names[SIZE];
    int boxes[SIZE];
    int size;
    int largest;
    string largest2;

//  data file is opened and checked if it was opened correctly
    myIn.open("boxes.dat");
    assert(myIn);

//  functions are declared
    ReadData (myIn, names, boxes, size);
    FindWinner(names, boxes, size, largest,largest2);
    DisplayData (names, boxes, size, largest,largest2);

    return 0;
}

//  data reading function is defined
void ReadData (ifstream & myIn, string names[], int boxes[], int& size)
{
//  function variables are declared and initalized
    string toFind;
    size = 0;
    int quantity = 0;
    string name;
    int index;

//  while the class names and quanities are being read in from the data file
    while (myIn >> name >> quantity)
    {
//  the toFind variable is set to the current name being read in
        toFind = name;

//  the LinearSearch function is read
        index = LinearSearch(names, size, toFind);

//  if the index returned is not -1, a repeat has been found in the names array and
//  current quantity is on to in the boxes array
        if (index >= 0)
        {
            boxes[index] += quantity;
        }

//  if not, a new spot in both arrays are made
        else
        {
            names[size] = toFind;

            boxes[size] = quantity;
            size++;
        }
    }
}

//  the find winner function is defined
void FindWinner(string names[], int boxes[], int size, int& largest, string& largest2)
{
//  the function variables are defined and initalized
    int smallest = 0;
    largest = 0;

//  for every value in the boxes
    for (int i = 0; i < size; i++)
    {
//  if the current value is smaller than the current smallest value, the smallest
//  variable is reassigned
        if (boxes[i] < smallest)
        {
            smallest = boxes[i];
        }

//  if the current value is larger than the current largest value, the largest
//  varible is reassigned and the corresponding name is assigned
        if (boxes[i] > largest)
        {
            largest = boxes[i];
            largest2 = names[i];
        }
    }
}

//  the displaying data function is defined
void DisplayData (string names[], int boxes[], int size, int largest, string& largest2)
{
//  for every element in the array
    for (int i = 0; i < size -1; i++)
    {
//  for every two set of elements
        for (int x = 0; x < (size - i - 1); x++)
        {
//  the two current elements are compared
            if(boxes[x] > boxes [x+1])
            {
//  elements are swapped if they aren't in ascending order
                int temp1 = boxes[x];
                string temp2 = names[x];

                boxes[x] = boxes [x+1];
                names[x] = names[x+1];

                boxes[x+1] = temp1;
                names[x+1] = temp2;
            }

        }

    }

//  for every element in both arrays
    for (int i = 0; i < size; i++)
    {
//  each class name and quantity is displayed in ascending order
        cout << left << setw(10) << names[i] << left << setw(5) << boxes[i] << endl;
    }
    cout << '\n';

//  the winner is displayed
    cout << "The winner is " << largest2 << " who sold " << largest << " boxes." << endl;
}

//  the linear search function is defined
int LinearSearch (const string names[], int size, string toFind)
{
//  function varibales are defined and initalized
    int position = -1;
    bool found = false;
    int location = 0;

//  while the class name is not found and array hasn't reached the end of its size
    while (!found && location < size)
    {
//  if the index location matches the class name, found is returned as true and the
//  position is set to the found location
        if (names[location] == toFind)
        {
            found = true;
            position = location;
        }
//  if not, the program keeps looking for the class name
        location++;
    }
//  at the end, the position is either returned as -1 or the found location
    return position;
}
    
