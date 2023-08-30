// cla3b by Naomi Igbinovia, CSCI 2170-004, Due: 01/27/2022
// Program ID: inorder.cpp / three integer values inputted
//  and sorted in ascending order
// Author: Naomi Igbinovia
// Installation: MTSU
// Remarks: This program takes three integer values inputted
// by the user, sorts them, in ascending order and displays the output
#include <iostream>
using namespace std;

int main()
{
    int val1, val2, val3;

    //prompt for college hour value
    cout << "Please enter three integer values: ";
    cin >> val1 >> val2 >> val3;

    //determine class ranking and display output
    if (val1 < val2 && val1 < val3)
    {
        if (val2 < val3)
        {
            cout << "The three values in ascending order are: " << val1 << " " << val2 << " " <<  val3;
        }
        else
        {
            cout << "The three values in ascending order are: " << val1 << " " << val3 << " " <<  val2;
        }
    }

    else if (val1 < val2 && val1 > val3)
    {
        cout << "The three values in ascedning order are: " <<  val3 << " " << val1 << " " << val2;
    }

    else if (val1 > val2 && val1 < val3)
    {
        cout << "The three values in ascedning order are: " << val2 << " " <<  val1 << " " << val3;
    }

    else if (val1 > val2 && val1 > val3)
    {
        if (val2 > val3)
        {
            cout << "The three values in ascending order are: " << val3 << " " << val2 << " " << val1;
        }
        else
        {
            cout << "The three values in ascending order are: " << val2 << " " <<  val3 << " " << val1;
        }
    }
    return 0;
}
