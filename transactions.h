#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <iostream>
using namespace std;

class Transactions
{
    int transactionId;
    string date;
    string item;
    int amount;

public:
    void setTransactionId(int newTransactionId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(int newAmount);

    int getTransactionId();
    string getDate();
    string getItem();
    int getAmount();

    void addTransaction();
};

#endif
