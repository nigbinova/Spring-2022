/*
Author: Naomi Igbinovia
Assignment: OLA1
Class: CSCI 2170-004 Course Instructor: Dr. Li Due Date: 02/10/2022
Description: This program determines the day of the week a person is born,
using Zeller's formula. The program reads person's birth date (month,
day, year) from a datafile and outputs the day of the week a person is
born. If birth date is invalid, the output is an error message.
*/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    int day;
    int month;
    int year;

    int D;
    int C;
    int fval;
    int weekday;

    ifstream myIn;

//The file is opened here
    myIn.open("birthday.dat");
    assert(myIn);

//while data is in file, the program will run.
    while (cin >> month >> day >> year)
    {
    //Modifications are made to certain dates for the calculation to work.
        if (month == 1)
        {
            month = 11;
            year = year - 1;
        }
        else if (month == 2)
        {
            month = 12;
            year = year - 1;
        }
        else
        {
            month = month-2;
        }

        D = (year % 100);
        C = (year / 100);

//The Zeller calculation is made to determine the correct weekday.
        fval = (day + ((13*month-1)/5)+D+(D/4)+(C/4)-(2*C));
        weekday = (fval % 7);

        if (weekday < 0)
        {
            weekday = weekday +7;
        }

//A Boolean is run to make sure the date is valid:
    //If the date is ruled as "false", "Incorrect Data" is printed as the output.
    //If the date is ruled as "true", the correct weekday is printed as the output.
    bool IsDateValid = true;
        year = year + 1;
        if (year >= 1900 && year <= 2100)
        {
            if ((month == 11 || month == 1 || month == 3 || month == 5 || month == 6 || month == 8 || month == 10) && (day < 1 || day > 31))
            {
                if (month == 11)
                {
                    month = 1;
                }
                else
                {
                    month = month + 2;
                }
                cout << month << " " << day << " " << year << " -> ";
                cout << "Incorrect Data";
                cout << '\n';
                IsDateValid = false;
            }
            else if ((month == 2 || month == 4 || month == 7 || month == 9) && (day < 1 || day > 30))
            {
                month = month + 2;
                cout << month << " " << day << " " << year << " -> ";
                cout << "Incorrect Data";
                cout << '\n';
                IsDateValid = false;
            }
            else if ((month == 12) && (day < 1 || day > 28))
            {
                month = 2;
                if (year % 4 != 0 || year % 400 != 0)
                {
                    cout << month << " " << day << " " << year << " -> ";
                    cout << "Incorrect Data";
                    cout << '\n';
                    IsDateValid = false;
                }
            }
        }

//Furhter calculation for the correct weekday is made based off of the value of the fval
        if (IsDateValid == true)
        {
            if (month == 11 || month == 12)
            {
                month = month - 10;
            }
            else
            {
                month = month + 2;
            }

            if(weekday == 0)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Sunday";
                cout << '\n';
            }
            else if(weekday == 1)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Monday";
                cout << '\n';
            }
            else if(weekday == 2)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Tuesday";
                cout << '\n';
            }

            else if(weekday == 3)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Wednesday";
                cout << '\n';
            }
            else if(weekday == 4)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Thursday";
                cout << '\n';
            }
            else if(weekday == 5)
            {:
                cout << month << " " << day << " " << year << " -> ";
                cout << "Friday";
                cout << '\n';
            }

            else if(weekday == 6)
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Saturday";
                cout << '\n';
            }
            else
            {
                cout << month << " " << day << " " << year << " -> ";
                cout << "Incorrect Data";
                cout << '\n';
            }
        }
    }

    myIn.close();
    return 0;
}