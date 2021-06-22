#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H
#include "UserManager.h"
#include <iostream>
#include "AuxiliaryMethods.h"
#include <string>
#include "fileWithTransactions.h"
#include "transactions.h"

using namespace std;
class Transactions;
class TransactionManager
{
    vector <Transactions> incomes;
    vector <Transactions> expenses;

    const int LOGGED_USER_ID;
    string INCOMES_FILE_NAME;
    string EXPENSES_FILE_NAME;


    AuxiliaryMethods auxiliaryMethods;
    int loadLastTransactionId();
    bool isDateCorrect(string enteredDate);
    int getNumberOfDaysOfMonth(int year, int month);

public:
    TransactionManager (string incomesFileName, string expensesFileName, int loggedUserId):
        INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName),LOGGED_USER_ID(loggedUserId)
        {};

    void addIncome();
    void addExpense();
    Transactions giveDataOfNewTransaction();
};

#endif
