// '''This program reads the data from the file "runners.txt" to calculate the average and total numbers of miles run for each person. It uses structs for its underlying data structure.
// The data is displayed using a table and setw() is implemented to align the data properly. ''' 

// Insert libraries 
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

// Use struct 
struct Runner {
    string name;
    double runningData[8];
    double average;
    double totalMiles;
};

// Function to get data from "runners.txt" 
// Precondition: "runners.txt" must be readable and able to open. 
// Postcondition: The data values in the text file are stored. 
void getData(ifstream& inf, Runner runners[], int count);

// Function to calculate the average and total number of miles run for each person. 
// Precondition: Must have access to data from "runners.txt." 
// Postcondition: Averages and totals are calculated. 
void calculateAverage(Runner runners[], int count);

// Function to display the data.
// Precondition: All calculations must be done and access is gained to the data file. 
// Postcondition: The data is printed to the console. 
void print(Runner runners[], int count);

// Main function 
int main()
{
    Runner runners[5];
    ifstream inputfile("runners.txt");
    if (inputfile)
    {
        getData(inputfile, runners, 5);
    }
    else
    {
        cout << "Sorry! Unable to open the file." << endl;
        return 0;
    }
    inputfile.close();
    calculateAverage(runners, 5);
    print(runners, 5);

    return 0;
}

// Get data from the file 
void getData(ifstream& inf, Runner runners[], int count)
{
    while (!inf.eof())
    {
        for (int i = 0; i < count; i++)
        {
            inf >> runners[i].name;
            for (int j = 0; j < 7; j++)
            {
                inf >> runners[i].runningData[j];
            }
        }
    }
}

// Calculate the average and total number of miles run for each person. 
void calculateAverage(Runner runners[], int count)
{
    double total;
    for (int i = 0; i < count; i++)
    {
        total = 0;
        for (int j = 0; j < 7; j++)
        {
            total += runners[i].runningData[j];
        }
        runners[i].average = total / 7;
        runners[i].totalMiles = total;
    }
}

// Display the data 
void print(Runner runners[], int count)
{
    cout << setfill(' ') << setw(80) << " " << endl;
    cout << setfill(' ');
    cout << setw(10) << "Name";
    for (int i = 0; i < 7; i++)
        cout << setw(9) << "Day " << (i + 1);
    cout << setw(22) << "Average" << setw(18) << "Total Miles" << endl;
    cout << setfill(' ') << setw(80) << " " << endl;
    cout << setfill(' ');
    for (int i = 0; i < count; i++)
    {
        cout << setw(10) << runners[i].name;
        for (int j = 0; j < 7; j++)
        {
            cout << setw(10) << setprecision(2) << fixed << runners[i].runningData[j];
        }
        cout << setw(22) << runners[i].average << setw(14) << runners[i].totalMiles << endl;
    }
}