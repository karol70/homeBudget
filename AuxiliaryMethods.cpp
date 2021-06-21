#include "AuxiliaryMethods.h"

string AuxiliaryMethods::getLine()
{
    string entry = "";
    getline(cin, entry);
    return entry;
}
char AuxiliaryMethods::loadCharacter()
{
    string entry = "";
    char character  = {0};

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            character = entry[0];
            break;
        }
        cout << "It's not a single sign. Enter character again: " << endl;
    }
    return character;
}

string AuxiliaryMethods::loadCurrentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int currentYear =st.wYear;
    string currentYearStr = to_string(currentYear);
    return currentYearStr;
}


string AuxiliaryMethods::loadCurrentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int currentMonth =st.wMonth;
    string currentMonthStr = to_string(currentMonth);
    if (currentMonth<10)
    {
        currentMonthStr = "0" + currentMonthStr;
    }
    return currentMonthStr;
}


string AuxiliaryMethods::loadCurrentDay()
{
    SYSTEMTIME st;
    GetSystemTime(&st);
    int currentDay =st.wDay;
    string currentDayStr = to_string(currentDay);
    if (currentDay<10)
    {
        currentDayStr = "0" + currentDayStr;
    }
    return currentDayStr;
}
