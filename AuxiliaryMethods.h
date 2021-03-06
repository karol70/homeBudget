#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <windows.h>
#include <winbase.h>

using namespace std;

class AuxiliaryMethods
{

public:
    string getLine();
    char loadCharacter();
    string loadCurrentYear();
    string loadCurrentMonth();
    string loadCurrentDay();
    bool isDateCorrect(string Date);
    int getNumberOfDaysOfMonth(int year, int month);
    string convertDateToString (int Date);
    int convertDateToInt(string Date);



};

#endif
