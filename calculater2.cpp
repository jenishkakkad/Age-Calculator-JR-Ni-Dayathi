#include <iostream>
using namespace std;

int main() 
{
    int birthYear, birthMonth, birthDay;
    int currentYear, currentMonth, currentDay;

    cout << "Enter your birth year: ";
    cin >> birthYear;
    cout << "Enter your birth month (1-12): ";
    cin >> birthMonth;
    cout << "Enter your birth day (1-31): ";
    cin >> birthDay;

    cout << "Enter current year: ";
    cin >> currentYear;
    cout << "Enter current month (1-12): ";
    cin >> currentMonth;
    cout << "Enter current day (1-31): ";
    cin >> currentDay;

    int ageYears = currentYear - birthYear;
    int ageMonths = currentMonth - birthMonth;
    int ageDays = currentDay - birthDay;

    if(ageDays < 0) 
    {
        ageMonths--;
        ageDays += 30;
    }

    if(ageMonths < 0) 
    {
        ageYears--;
        ageMonths += 12;
    }

    cout << "Your age is: " << ageYears << " years, " 
         << ageMonths << " months, " 
         << ageDays << " days." << endl;
}