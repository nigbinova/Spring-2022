// cla6 by Naomi Igbinovia, CSCI 2170-004, Due: 02/10/2022
// Program ID: statistics.cpp / numbers from a file are sorted
// to find the smallest, largest, and average values.
// Author: Naomi Igbinovia
// Installation: MTSU
// Remarks: This programs takes all the numbers from a data file,
// sorts  through them to find the smallest and largest values, counts
// them to find a total count, adds them together to find a total sum,
// and divides the sum by the count to find the average. Then, the
// smallest, largest, count, and average.

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//Declarations are made
void ComputeStatistics(ifstream & myIn, int &  value,  int & smallest, int & largest, int & count, float & sum, float & average);
void DisplayResults (int & count, int & smallest, int & largest, float & average);

int main()
{
    int value, smallest, largest, count = 0;
    float sum,  average = 0;

    string filename;
    ifstream myIn;

//The input file is asked for, opened, and checked whether the input file is opened correctly
    cout << "Enter file name here: ";
    cin >> filename;

    myIn.open(filename.c_str());
    assert(myIn);

//The other functions are called into the main function
    ComputeStatistics( myIn, value, smallest,largest, count, sum, average);
    DisplayResults (count, smallest, largest, average);

    return 0;
}

void ComputeStatistics(ifstream & myIn, int & value, int & smallest, int & largest, int & count, float & sum, float & average)
{
    cout << "The values read are: " << endl;

//While is run until no data is left in the file
    while (myIn >> value)
    {

//If the count is 0, the smallest and largest value is set to the current value
        if (count == 0)
        {
            smallest = value;
            largest = value;
        }
//Each value is printed, counted, checked if it's the smallest, largest, and added to the overall sum
        cout << value;
        cout << '\n';
        count++;

        if (value <  smallest)
        {
            smallest = value;
        }

         if (value > largest)
        {
            largest = value;
        }

        sum += value;
    }

//The sum is divided by the count to make the average
    average = (sum/count);

//When all the data is read, the file is closed
    myIn.close();
}

void DisplayResults(int & count, int & smallest, int & largest, float & average)
{
//The count, smallest, largest, and average values are printed
    cout << "Total " << count << " numbers." << endl;
    cout << "The largest number is " << largest << ", and the smallest number is " << smallest << ".";
//  cout << "largest: " << << endl;
    cout << "The average of these numbers is  ";
    cout << fixed << setprecision(1) << average << "." << endl;
}
