//cla4b by Naomi Igbinoiva, CSCI 2170-004, Due: 02/03/2022
// Program ID: coin.cpp / a coin program is flipped until 3
// heads in a row is achieved.
// Author: Naomi Igbinovia
// Installation: MTSU
// Remarks: This program uses a random number generator to flip
// a coin, if 3 heads in a row is achieved then the program
// finishes and the total number of flips is printed. If not,
// the coin keeps flipping.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
// the variables are defined
    int val;
    int count3, totalcount;

// the counting variables are set to zero and time value of seed is activated
    count3 = 0;
    totalcount = 0;
    srand(time(0));

//while 3 heads in a row counter is not equal 3, the loop will run
    while (count3 < 3)
    {
//if the random value is even, it counts as heads and the count3 and totalcount is added to.
        val = rand();
        if (val % 2 == 0)
        {
            cout << "Head";
            cout << '\n';
            count3++;
            totalcount++;
        }
//if not, counts3 is started over and totalcount is added to.
        else
        {
            cout << "Tail";
            cout << '\n';
            count3 = 0;
            totalcount++;
        }
    }
//the final output is displayed.
    cout << "It took " << totalcount << " flips to get 3 consecutive heads.";

    return 0;
}