#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include "UserManager.h"
#include <iostream>
#include "AuxiliaryMethods.h"
#include <string>


using namespace std;

class Transactions
{
    int loggedUserId;
    int transactionId;
    string date;
    string item;
    double amount;


public:

    void setloggedUserId(int newLoggedUserId);
    void setTransactionId(int newTransactionId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getLoggedUserId();
    int getTransactionId();
    string getDate();
    string getItem();
    double getAmount();

};

#endif
