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
    int amount;

    AuxiliaryMethods auxiliaryMethods;
    int loadLastTransactionId();
    bool isDateCorrect(string enteredDate);
    int getNumberOfDaysOfMonth(int year, int month);


public:
    void setloggedUserId(int newloggedUserId);
    void setTransactionId(int newTransactionId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(int newAmount);

    int getLoggeduserId();
    int getTransactionId();
    string getDate();
    string getItem();
    int getAmount();

    Transactions giveDataOfNewTransaction();

};

#endif
