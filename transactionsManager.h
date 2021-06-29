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
    FileWithTransactions fileWithTransactions;
    int loadLastIncomeId();
    int loadLastExpenseId();
    bool isDateCorrect(string enteredDate);
    int getNumberOfDaysOfMonth(int year, int month);
    void showTransactions(Transactions transaction);
    void showBalance(int firstDate, int secondDate);
//    bool sortByDate(  Transactions *t1,  Transactions  *t2);
    void showAllTransactions(vector<Transactions> transaction);

    bool isVectorSorted (vector<Transactions> transactions);
    struct sortByDate
{
    inline bool operator() (Transactions& firstDate, Transactions& secondDate)
    {
        return (firstDate.getDate() < secondDate.getDate());
    }
};

    Transactions giveDataOfNewTransaction(int lastTransactionId);

public:
    TransactionManager (string incomesFileName, string expensesFileName, int loggedUserId):
        INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName),LOGGED_USER_ID(loggedUserId)
        {
        incomes = fileWithTransactions.loadTransactionsFromFile(LOGGED_USER_ID,INCOMES_FILE_NAME,"INCOME");
   //     do
   //     incomes = sortTransactions(incomes,0,incomes.size()-1);
      sort(incomes.begin(),incomes.end(),sortByDate());
        expenses = fileWithTransactions.loadTransactionsFromFile(LOGGED_USER_ID,EXPENSES_FILE_NAME,"EXPENSE");

       sort(expenses.begin(),expenses.end(),sortByDate());

        showAllTransactions(incomes);
       showAllTransactions(expenses);
        system("pause");
        };

    void addIncome();
    void addExpense();

    void showBalanceOfCurrentMonth();
    void showBalanceOfPreviousMonth();
    void showBalanceOfChoosenPeriod();
};

#endif
