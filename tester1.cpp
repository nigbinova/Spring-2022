
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
// variable declaration and initialization
    string className;
    string catName;
    int count = 0;

    float temp1,  temp2 = 0;
    float totalPoints, userPoints = 0;
    float avg, percent, finalAvg = 0;

    string select1;

//  explanation for user
    cout << "Intro: " << endl;


//  labeling information
    cout << "Please enter your class name: " << endl;
    getline(cin, className);

//  while loop that runs until the user has no more categories to calculate for final grade
    cout << "What category would you like to calculate for: " << endl;// while loop
//  getline(cin, catName);
    cin >> catName;
    while(catName != "None")
    {

        cout << "How many grades are in this category: " << endl;
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            cout << "How many total points for assignment " << (i+1) << "?" << endl;
            cin >> temp1;
            totalPoints = totalPoints + temp1;

            cout << "How many points did you score out of " << temp1 << "?" << endl;
            cin >> temp2;
            userPoints = userPoints + temp2;
        }

        cout << "What percentage of your grade is this category: " << endl;
        cin >> percent;

        if (percent > 1)
        {
            percent = (percent / 100);
        }
//  section grade is calculated and printed
        avg = (userPoints / totalPoints) * 100;
        percent = (percent * avg);

        cout << "For the " << catName << "," << endl;
        cout << "Grade: " << avg << endl;
        cout << "Percentage: " << percent << endl;

        finalAvg = finalAvg +  percent;
        cout << "overall: " << finalAvg << endl;

        cout << "What category would you like to calculate for: " << endl;
    //  getline(cin, catName);
        cin >> catName;

    }

    cout << "Have you taken your final yet?" << endl;
    cout << "Select 'y' for yes or 'n' for no: " << endl;
    cin >> select1;
    if (select1 == "y")
    {
        cout << "How many points total for final: " << endl;
        cin >> totalPoints;
        cout << "How many points did your score on your final: " << endl;
        cin >> userPoints;
        cout << "What percentage of your grade is your final: " << endl;
        cin >> percent;
        if (percent > 1)
        {
            percent = (percent / 100);
        }

        avg = (userPoints / totalPoints) * 100;
        percent = (percent * avg);

        finalAvg = finalAvg + percent;

        cout << "final: " << finalAvg << endl;
    }
    else if (select1 == "n")
    {
        float need = 0;
        float goal = 0;

        cout << "What score do you want for the class: " << endl;
        cin >> goal;
        cout << "What is the weight of your final: " << endl;
        cin >> percent;
        if (percent > 1)
        {
            percent = (percent / 100);
        }

        need = (goal - finalAvg * (1 - percent)) / percent;
        cout << "You need: " << need << endl;
    }

//  cout << "final: " << finalAvg << endl;

    return 0;
}
     