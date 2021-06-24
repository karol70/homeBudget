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

 bool AuxiliaryMethods::isDateCorrect(string Date)
    {

        if(Date.length()==10)
        {

        int mininumDate = 20000101;


        string year = Date.substr(0,Date.find("-"));
        int intConvertedYear = atoi(year.c_str());
        Date.erase(0,4+1);

         string month = Date.substr(0,Date.find("-"));
         int intConvertedMonth = atoi(month.c_str());
        Date.erase(0,2+1);

         string day = Date.substr(0,Date.find("-"));
         int intConvertedDay = atoi(day.c_str());
        Date.erase(0,2+1);

        string convertedDate = year+month+day;
        int intConvertedDate = atoi(convertedDate.c_str());

        string currentYear = loadCurrentYear();
        int intCurrentYear = atoi(currentYear.c_str());

        string currentMonth = loadCurrentMonth();
        int intCurrentMonth = atoi(currentMonth.c_str());

        string currentDay = loadCurrentDay();
        int intCurrentDay = atoi(currentDay.c_str());

        int numberOfDaysOfCurrentMonth = getNumberOfDaysOfMonth(intCurrentYear, intCurrentMonth);
        int numberOfDaysOdChoosenDate = getNumberOfDaysOfMonth(intConvertedYear, intConvertedMonth);

        if(intConvertedYear == intCurrentYear)
           {
             if( intConvertedMonth <= intCurrentMonth && intConvertedDay <= numberOfDaysOfCurrentMonth)
                return true;
           }
          if(intConvertedDate >= mininumDate && intConvertedYear < intCurrentYear)
        {
            if (intConvertedMonth <= 12 && intConvertedDay <= numberOfDaysOdChoosenDate)
            return true;
        }

        }
        cout << "Entered date is incorrect, try again"<<endl;
            return false;


    }

int AuxiliaryMethods::getNumberOfDaysOfMonth(int year, int month)
{

    int days;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;

    else if (month == 2)
    {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
                days = 28;
        else
                days = 29;
    }

    else
    days = 31;

    return days;
}
