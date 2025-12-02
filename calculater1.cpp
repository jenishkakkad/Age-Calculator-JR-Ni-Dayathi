#include <iostream>
#include <stdexcept>
using namespace std;

bool isLeapYear(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int daysInMonth(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        throw invalid_argument("Invalid month value.");
    }
}

bool isValidDate(int day, int month, int year)
{
    if (year < 1)
        return false; 
    if (month < 1 || month > 12)
        return false;
    int maxDay = daysInMonth(month, year);
    if (day < 1 || day > maxDay)
        return false;
    return true;
}

struct Age
{
    int years;
    int months;
    int days;
};

Age calculateAge(int birthDay, int birthMonth, int birthYear,
                 int currentDay, int currentMonth, int currentYear)
{
    if (!isValidDate(birthDay, birthMonth, birthYear))
        throw invalid_argument("Invalid birth date provided.");
    if (!isValidDate(currentDay, currentMonth, currentYear))
        throw invalid_argument("Invalid current date provided.");

    if (currentYear < birthYear ||
        (currentYear == birthYear && currentMonth < birthMonth) ||
        (currentYear == birthYear && currentMonth == birthMonth && currentDay < birthDay))
        throw invalid_argument("Birth date cannot be after the current date.");

    Age age{0, 0, 0};

    if (currentDay < birthDay)
    {
        currentMonth--; 
        if (currentMonth < 1)
        { 
            currentMonth = 12;
            currentYear--;
        }
        currentDay += daysInMonth(currentMonth, currentYear);
    }
    age.days = currentDay - birthDay;

    if (currentMonth < birthMonth)
    {
        currentYear--;
        currentMonth += 12;
    }
    age.months = currentMonth - birthMonth;

    age.years = currentYear - birthYear;

    return age;
}

int main()
{
    int bDay, bMonth, bYear;
    int cDay, cMonth, cYear;

    cout << "Enter your birth date (DD MM YYYY): ";
    cin >> bDay >> bMonth >> bYear;

    cout << "Enter current date (DD MM YYYY): ";
    cin >> cDay >> cMonth >> cYear;

    try
    {
        Age age = calculateAge(bDay, bMonth, bYear, cDay, cMonth, cYear);
        cout << "Your age is: "
             << age.years << "  years, "
             << age.months << " months, and "
             << age.days << " days." << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}