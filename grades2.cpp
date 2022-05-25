#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void InitialCalculations (float & average, float & percent, float & finalAverage, float & totalPercent);

void NoFinal (float finalAverage, float totalPercent);

void GivenFinal (float & average, float & percent, float & finalAverage);
void PendingFinal (float & percent, float finalAverage);


/*void NoFinal
void PendingFinal
void GivenFinal
*/
int main()
{
    string className;
    float average, percent, finalAverage, totalPercent = 0;
    int select = 0;

    cout << "/////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << "//                                                                                 //" << endl;
    cout << "//                              GRADE CALCULATOR                                   //" << endl;
    cout << "// Hello! Calculating your grades can be complicated, but this calculator          //" << endl;
    cout << "// will take that overwhelm away! This tool will determine your current grade      //" << endl;
    cout << "// in a class, can help you calculate your final grade if you have finals score,   //" << endl;
    cout << "// and can compute what grade you need for your final exam to get your desired     //" << endl;
    cout << "// grade in the class.                                                             //" << endl;
    cout << "//                                                                                 //" << endl;
    cout << "/////////////////////////////////////////////////////////////////////////////////////" << endl;


    cout << '\n' << endl;

    cout << "Please enter the name of your class to start: " << endl;
    getline(cin, className);

    cout << '\n' << endl;

    cout << "Okay, let's start by calculating your current grade." << endl;

    InitialCalculations (average, percent, finalAverage, totalPercent);

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;


    cout << " Now that your current grade has been computed, please choose an option for your final: " << endl;
    cout << " ------------------------------------------------------------------------------------- " << endl;
    cout << "If you want to compute your overall grade without your final - | ENTER 1 | " << endl;
    cout << "If you want to compute your overall grade with your final - | ENTER 2 | " << endl;
    cout << "If you want to calculate what score you need on your final for a desired grade - | ENTER 3 | " << endl;
    cout << "Enter your choice here: " << endl;
    cin >> select;

cout << '\n' << endl;

    if (select == 1)
    {
        NoFinal (finalAverage, totalPercent);
    }
    else if (select ==  2)
    {

        GivenFinal (average, percent, finalAverage);
    }
    else
    {
        PendingFinal (percent, finalAverage);
    }
    return 0;
}

void InitialCalculations (float & average, float & percent, float & finalAverage, float & totalPercent)
{
    string catName;
    int count = 0;
    float temp1, temp2 = 0;
    float totalPoints, userPoints = 0;

    cout << "What assignment category are you calculating for?: " << endl;
    cin >> catName;

    cout << '\n' << endl;

    while(catName != "None")
    {
        cout << "How many grades are in this category?: " << endl;
        cin >> count;

        for (int i = 0; i < count; i++)
        {
            cout << "How many total points was assignment " << i+1 << " worth?: " << endl;
            cin >> temp1;
            totalPoints = totalPoints + temp1;

            cout << "How many points did you earn on assingment " << i+1 << " ?: " << endl;
            cin >> temp2;
            userPoints = userPoints + temp2;

            cout << '\n' << endl;
        }

        cout << "What percentage of your final grade is the " << catName << " category?:  " << endl;
        cin >> percent;

        if (percent > 1)
        {
            percent = (percent / 100);
        }

        totalPercent = percent;

        average = (userPoints / totalPoints) * 100;
        percent = (percent * average);
        finalAverage = finalAverage + percent;

        cout << '\n' << endl;
        cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << '\n' << endl;
        cout << "For the  " << catName << " category of your class, " << endl;
        cout << "You have a score of: " << average << "%." <<  endl;

//      finalAverage = finalAverage + percent;

//      cout << '\n' << endl;
        cout << "Please enter the next category you'd like to compute for," << endl;
        cout << "or enter 'None' to finish up your grade: " << endl;
        cin >> catName;

    }
}


void NoFinal (float finalAverage, float totalPercent)
{
    float score = 0;
    score = (finalAverage / totalPercent);

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "Your overall grade without your final is " << score << "%." << endl;
}

void GivenFinal (float & average, float & percent, float & finalAverage)
{
    float totalPoints, userPoints = 0;


    cout << "How many total points is your final worth?: " << endl;
    cin >> totalPoints;

    cout << "How many points did you earn on your final?: " << endl;
    cin >> userPoints;

    cout << "What percentage of your grade is your final?: " << endl;
    cin >> percent;
    if (percent > 1)
    {
        percent = (percent / 100);
    }

    average = (userPoints / totalPoints) * 100;
    percent = (percent * average);
    finalAverage = finalAverage + percent;

cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "Your overall score with your final is: " << finalAverage << "%." << endl;
}

void PendingFinal (float & percent, float finalAverage)
{
    float neededFinal, goalGrade = 0;

    cout << "What grade would like for this class?: " << endl;
    cin >> goalGrade;

    cout << "What is the weight of your final?: " << endl;
    cin >> percent;
    if (percent > 1)
    {
        percent = (percent / 100);
    }

    neededFinal  = (goalGrade - finalAverage * (1 - percent)) / percent;

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "To get a " << goalGrade << "% in this class, you would need a " << neededFinal << "% on the final exam." << endl;
}
