#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//  the functions are declared
void InitialCalculations (float & average, float & percent, float & finalAverage, float & totalPercent);
void NoFinal (float finalAverage, float totalPercent);
void GivenFinal (float & average, float & percent, float & finalAverage);
void PendingFinal (float & percent, float finalAverage);


int main()
{
//  the main function variables are declared and initialized
    string className;
    float average, percent, finalAverage, totalPercent = 0;
    int select = 0;

//  a summary statement is displayed to the user about what the calculator is
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
/*
    cout << "Please enter the name of your class to start: " << endl;
    getline(cin, className);

    cout << '\n' << endl;
*/

//  a line of code is printed to get the user ready to start entering information
//  while the first function is called
    cout << "Okay, let's start by calculating your current grade." << endl;

//  this function computes the current grade of the student without their final
    InitialCalculations (average, percent, finalAverage, totalPercent);

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

//  after their current grade is calculated the student is prompted to make a
//  selection on what action they'd like to take towards their final. they can
//  compute the current grade without their final, compute their final grade
//  with their final, or help the user calculate what they'd need on their final
//  to get a desired grade.
    cout << " Now that your current grade has been computed, please choose an option for your final: " << endl;
    cout << " ------------------------------------------------------------------------------------- " << endl;
    cout << "If you want to compute your overall grade without your final - | ENTER 1 | " << endl;
    cout << "If you want to compute your overall grade with your final - | ENTER 2 | " << endl;
    cout << "If you want to calculate what score you need on your final for a desired grade - | ENTER 3 | " << endl;
    cout << "Enter your choice here: " << endl;
    cin >> select;

    cout << '\n' << endl;

//  if the user selects 1, the no final function runs, computing their current
//  grade without their final
    if (select == 1)
    {
        NoFinal (finalAverage, totalPercent);
    }

//  if the user selects 2, the given final function runs, computing their final
//  grade with theit final
    else if (select ==  2)
    {

        GivenFinal (average, percent, finalAverage);
    }

//  if the user selects 3, the pending final function runs, helping the user compute
//  what they'd need on their final to get a desired grade
    else
    {
        PendingFinal (percent, finalAverage);
    }
    return 0;
}

//  the inital calculations function is defined. this function gathers initial information from the
//  the user to calculcate their current grade without their final.
void InitialCalculations (float & average, float & percent, float & finalAverage, float & totalPercent)
{
//  the function variables are declared and initialized
    string catName;
    int count = 0;
    float temp1, temp2 = 0;
    float totalPoints, userPoints = 0;

//  the user is asked what section of their class their calculating for and this value is stored
    cout << "What assignment category are you calculating for?: " << endl;
    cin >> catName;


    cout << '\n' << endl;

//  while the user has not submitted "None" when asked about class sections
    while(catName != "None")
    {
//  the user is asked how many grades are in this section, setting up a for loop to
//  gather the information for each assignment following
        cout << "How many grades are in this category?: " << endl;
        cin >> count;

        for (int i = 0; i < count; i++)
        {
//  the total points available and the number of points the user earned are asked with each
//  assignment to be added to seperate grand total to be used to calulcate the section average
//  later in the program
            cout << "How many total points was assignment " << i+1 << " worth?: " << endl;
            cin >> temp1;
            totalPoints = totalPoints + temp1;

            cout << "How many points did you earn on assingment " << i+1 << " ?: " << endl;
            cin >> temp2;
            userPoints = userPoints + temp2;

            cout << '\n' << endl;
        }

//  the percentage of this section is obtained by the user the calculate the weight of this section and
//  to make sure the final score would be computed correctly
        cout << "What percentage of your final grade is the " << catName << " category?:  " << endl;
        cin >> percent;

//  to make math easier in later calculations, if the percentage value given is not in decimal form
//  it's then converted into decimal form
        if (percent > 1)
        {
            percent = (percent / 100);
        }

//  the total percantage is gathered here in the event the user doesn't want to calculate their final
//  grade at all
        totalPercent = percent;

//  the average of this section is computed, the weight of this section is computed with the average
//  calculated, and the final average in the case the user wants to calculate their final is added on to.
        average = (userPoints / totalPoints) * 100;
        percent = (percent * average);
        finalAverage = finalAverage + percent;

//  the user's average for this section of the class is displayed
        cout << '\n' << endl;
        cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << '\n' << endl;
        cout << "For the  " << catName << " category of your class, " << endl;
        cout << "You have a score of: " << average << "%." <<  endl;

//  the user is asked again if they'd like to add more sections to their current grade calculations, if not
//  they enter "None" and move onto calculating their final grade.
        cout << "Please enter the next category you'd like to compute for," << endl;
        cout << "or enter 'None' to finish up your grade: " << endl;
        cin >> catName;

    }
}

// the no final function is defined. this function calculates the current grade for the user without
// using their current grade only, not their final
void NoFinal (float finalAverage, float totalPercent)
{
//  the function variable is declared and initialized. the user's current grade is calculated in the
//  score variable and then displayed
    float score = 0;
    score = (finalAverage / totalPercent);

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "Your overall grade without your final is " << score << "%." << endl;
}

//  the given final function is defined. this function calculates the final grade for the user with
//  their final
void GivenFinal (float & average, float & percent, float & finalAverage)
{
// the function variables are declared and initalized
    float totalPoints, userPoints = 0;

// the user is asked the same questions as before but prompted for their final: the total points available,
// how many points they earned, and the percentage of their final grade the final takes up
    cout << "How many total points is your final worth?: " << endl;
    cin >> totalPoints;

    cout << "How many points did you earn on your final?: " << endl;
    cin >> userPoints;

    cout << "What percentage of your grade is your final?: " << endl;
    cin >> percent;

//  if the percentage given is not in decimal form, it's quickly converted to be
    if (percent > 1)
    {
        percent = (percent / 100);
    }

//  the average of their final is computed, the weight of their final is computed with their average,
//  the weighted final is added onto their final average for their overall score
    average = (userPoints / totalPoints) * 100;
    percent = (percent * average);
    finalAverage = finalAverage + percent;

//  their overall score with their final is displayed to the user
    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "Your overall score with your final is: " << finalAverage << "%." << endl;
}

// the pending final function is defined. this function calculates what the user would need
// on their final to get a desired score for the class
void PendingFinal (float & percent, float finalAverage)
{
// the function variables are declared and initalized
    float neededFinal, goalGrade = 0;

//  the user is asked what their goal grade is, and how much their final is weighted
    cout << "What grade would like for this class?: " << endl;
    cin >> goalGrade;

    cout << "What is the weight of your final?: " << endl;
    cin >> percent;

//  the percentage is converted into decimal form if it wasn't given in the right format
    if (percent > 1)
    {
        percent = (percent / 100);
    }

//  this equation calculates what the user would need on their final to get their desired grade and
//  this information is then displayed to the user
    neededFinal  = (goalGrade - finalAverage * (1 - percent)) / percent;

    cout << '\n' << endl;
    cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
    cout << '\n' << endl;

    cout << "To get a " << goalGrade << "% in this class, you would need a " << neededFinal << "% on the final exam." << endl;
}
