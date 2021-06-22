#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "UserManager.h"
#include <iostream>
#include "AuxiliaryMethods.h"
#include <string>
#include "fileWithTransactions.h"

using namespace std;

class Transactions
{
    int loggedUserId;
    int transactionId;
    string date;
    string item;
    int amount;


public:

    void setloggedUserId(int newLoggedUserId);
    void setTransactionId(int newTransactionId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(int newAmount);

    int getLoggedUserId();
    int getTransactionId();
    string getDate();
    string getItem();
    float getAmount();

};

#endif
