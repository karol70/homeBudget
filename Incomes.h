#ifndef INCOMES_H
#define INCOMES_H
#include "transactions.h"
#include <vector>
#include <string>

#include <iostream>

using namespace std;

class Incomes:public Transactions
{
    vector<Transactions> incomes;


public:
    void addIncome();
};


#endif
