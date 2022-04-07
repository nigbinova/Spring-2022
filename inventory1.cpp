//  ola5 by Naomi Igbinovia, CSCI 2170-004, Due: 03/26/2022
//  Program ID: inventory.cpp + makefile / takes account of eahc part
//  and how much of each part and prints the content
//  for title locations
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program reads in data from the "inventory.dat" to store
//  its starting information of parts and theit quantites and displays them.
//  Then, "operations.dat" is read in to add onto or remove certain quantites
//  from specific parts and the results are displayed again. The entire
//  program is complied uisng a makefile.

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <iomanip>
using namespace std;

//  the struct is defined
struct parts
{
    string name;
    int amount;
};

//  the functions are declared
void AddParts(int count, struct parts tools[], string part, int  quant);
void RemoveParts(int count, struct parts tools[], string part, int  quant);
void DisplayData(struct parts tools[], int count);

//  array size is declared and initalized
const int SIZE = 100;

int main()
{
//  variables are declared and initalized
    parts tools[SIZE];
    ifstream myIn;
    int count = 0;

    string operation;
    string part;
    string quant;

//  the first data file is opened and checked if it was opened correctly
    myIn.open("inventory.dat");
    assert(myIn);

//  while the array size hasn't been met and there's data to read in
    while (count < SIZE && getline(myIn, tools[count].name))
    {
        myIn >> tools[count].amount;
        myIn.ignore(100,'\n');

//  the size is counted
        count++;
    }

//  the first data file is closed
    myIn.close();

//  the warehouse inventory before operations is displayed with a function
    cout << "Warehouse inventory before the operations: " << endl;
    cout << '\n';
    DisplayData(tools, count);
    cout << '\n';

//  the second data file is opened and checked if it was opened correctly
    myIn.open("operations.dat");
    assert(myIn);

//  the first line for the operations.dat is stored in the operation
//  variable before the following while loop
    getline (myIn, operation);

//  while the data file is not empty
    while (!operation.empty())
    {
//  the next line is assigned to the part variable, the following line is
//  assigned to the quant variable, and quant is converted to a int variable
//  so math can be performed

        getline(myIn, part);
        getline(myIn, quant);
        int temp = stoi(quant);

//  if the operation variable is "Add", contents will be added to the quantity
//  of the correspinding part with a function
        if (operation == "Add")
        {
            AddParts(count, tools, part, temp);
        }

//  if the operation varibale is "Remove", contents will be subtracted from the
//  quantity of the corresponding part with a function
        else if (operation == "Remove")
        {
            RemoveParts(count, tools, part, temp);
        }

//  the next line is stored in the operations for the loop to continue
        getline(myIn, operation);
    }

//  the warehouse function after operations is displayed with a function
    cout << "Warehouse inventory after the operations: " << endl;
    cout << '\n';

    DisplayData(tools, count);

//  the second data file is closed
    myIn.close();
    return 0;
}

//  the adding parts function is defined
void AddParts(int count, struct parts tools[], string part, int quant)
{
//  function variables are declared and initalized
    bool found = false;

//  for every array element, if the current tool assigned to the part
//  variable matches with an array element name, the corresponding quantity
//  is added on, and the bool variable is turned true
    for (int i = 0; i < count; i++)
    {
        if (part ==  tools[i].name)
        {
            tools[i].amount = (tools[i].amount + quant);
            found = true;
        }
    }

// if not, an error message is displayed
    if (found == false)
    {
        cout << "This part couldn't be found." << endl;
    }
}

//  the removing parts function is defined
void RemoveParts(int count, struct parts tools[], string part, int  quant)
{
//  function variables are declared and initalized
    bool found = false;

//  for every array element, if the current tool assigned to the part
//  variable matches with an array element name, the corresponding quantity
//  is subtratced from it, and the bool variable is turned true
    for (int i = 0; i < count; i++)
    {
        if (part == tools[i].name)
        {
            tools[i].amount = (tools[i].amount - quant);
            found = true;
        }
    }

//  if not, an error message is displayed
    if (found == false)
    {
        cout << "This part couldn't be found." << endl;
    }
}

//  the display data function is defined
void DisplayData(struct parts tools[], int count)
{
//  a title prompt is displayed
    cout << left << setw(10) << "Part" << left << setw(10) << "Quantity" << endl;
    cout << '\n';

//  each part and its current quanity is displayed
    for (int i = 0; i < count; i++)
    {
        cout << left << setw(10) << tools[i].name << left << setw(10) << tools[i].amount << endl;
    }
    cout << '\n';
}
