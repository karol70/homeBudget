#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H
#include "UserManager.h"
#include "Incomes.h"
#include "Expenses.h"
#include <iostream>

using namespace std;

class HomeBudget
{
    UserManager userManager;
    Incomes incomes;
    Expenses expenses;


public:
    void userRegister();
    void userLogIn();
    void userLogOut();
    void showAllusers();
    void addIncome();
    void addExpense();
};










#endif
