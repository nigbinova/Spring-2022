//  cla8 by Naomi Igbinovia, CSCI-004, Due: 02/17/2022
//  Program ID: sdv.cpp / array elements are used to
//  calculate the mean and standard deviation.
//  Author: Naomi Igbinovia
//  Installation: MTSU
//  Remarks: This program takes all the elements in an
//  array, calculates the mean and standard deviation in
//  functions, and displays both outputs.

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cassert>
#include <cmath>
#include <cstdio>
using namespace std;

//the array size is initalized
const int SIZE = 50;

//declarations are made
void ComputeMean(int count, int values[], float &sum, float &mean);
void ComputeSdv(int count, int values[], float &mean, float &SDsum, float &SDfinal);

int main()
{
//variables are defined
    int values[SIZE];
    int count;
    float sum, mean, SDsum, SDfinal;

    string filename;
    ifstream myIn;

//input file is opened and checked whether the input file is opened correctly
    cout << "Enter the data file name: ";
    cin >> filename;

    myIn.open(filename.c_str());
    assert(myIn);

//variables are initalized
    sum = 0;
    count = 0;

//while is run until count is equal to or greater than SIZE and no data is left in the file
    //as the while loop runs, all the elements are counted
    while ((count < SIZE) && (myIn >> values[count]))
    {
        count++;
    }

//these functions calculated the mean and standard deviation of all the elements in the array
    ComputeMean(count, values, sum, mean);
    ComputeSdv(count, values, mean, SDsum, SDfinal);

//this for loop displays every element in the array
    cout << "The values read are: " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << values[i] << endl;
    }

//the mean and standard deviation are displayed
    cout << "The mean is ";
    cout << fixed << setprecision(2) << mean << "." <<  endl;
    cout << "The standard deviation is ";
    cout << fixed << setprecision(2) << SDfinal << "." << endl;

//the input file is closed
    myIn.close();

    return 0;
}

void ComputeMean(int count, int values[], float &sum, float &mean)
{
//this for loop adds every value together to calculate the sum
    for (int i = 0; i < count; i++)
    {
        sum += values[i];
    }

//the mean is calculated
    mean = (sum/count);
}

void ComputeSdv(int count, int values[], float &mean, float &SDsum, float &SDfinal)
{
//this for loop calculates the first part of the standard deviation formula
    for (int i = 0; i < count; i++)
    {
        SDsum += (pow((values[i] - mean), 2.0));
    }

//the last part of the standard deviation is calculated
    SDfinal = sqrt(SDsum/count);

}

