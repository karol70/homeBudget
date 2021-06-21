#include "Incomes.h"

void Incomes::addIncome()
{
    cout << "<<<<< ADDING INCOME >>>>>" <<endl<<endl<<endl;
    vector<Transactions> incomes;
     Transactions transaction;
    transaction = transaction.giveDataOfNewTransaction();
    incomes.push_back(transaction);
}

