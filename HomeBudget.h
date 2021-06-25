#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H
#include "UserManager.h"
#include "transactionsManager.h"
#include "transactions.h"
#include <iostream>

using namespace std;

class HomeBudget
{
    UserManager userManager;
    TransactionManager *transactionManager;

public:
    HomeBudget()
    {
        transactionManager = NULL;
    }
    void userRegister();
    void userLogIn();
    void userLogOut();
    void showAllusers();
    void addIncome();
    void addExpense();
    void showAllIncomes();
    void changePassword();

};










#endif
