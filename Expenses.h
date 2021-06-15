#ifndef EXPENSES_H
#define EXPENSES_H
#include "transactions.h"
#include <vector>

#include <iostream>

using namespace std;

class Expenses : public Transactions
{
    vector<Transactions> expenses;

public:
    void addExpense();
};


#endif
