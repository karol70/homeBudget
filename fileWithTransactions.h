#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "Markup.h"
#include "transactionsManager.h"
#include "transactions.h"
#include <sys/stat.h>
#include <unistd.h>
#include "UserManager.h"


using namespace std;

class FileWithTransactions
{

    string fileName;
    bool isFileEmpty(string fileName);


public:
    FileWithTransactions(){}
    void addTransactionToFile(Transactions transaction,string transactionFileName,string IncomeOrExpense);
    vector<Transactions> loadIncomesFromFile();
};



#endif
