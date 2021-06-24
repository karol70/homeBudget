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
    int date;
    string item;
    double amount;


public:

    void setloggedUserId(int newLoggedUserId);
    void setTransactionId(int newTransactionId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getLoggedUserId();
    int getTransactionId();
    int getDate();
    string getItem();
    double getAmount();

};

#endif
