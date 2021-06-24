#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Markup.h"
#include "transactions.h"
#include <sys/stat.h>
#include <unistd.h>
#include "UserManager.h"
#include "AuxiliaryMethods.h"



using namespace std;
class Transactions;
class FileWithTransactions
{
    Transactions transaction;
    string fileName;
    bool isFileEmpty(string fileName);


public:
    FileWithTransactions(){}
    void addTransactionToFile(Transactions transaction,string transactionFileName,string IncomeOrExpense);
    vector<Transactions> loadTransactionsFromFile(int LOGGED_USER_ID,string transactionFileName,string IncomeOrExpense);
};



#endif
