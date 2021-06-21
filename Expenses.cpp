#include "Expenses.h"

void Expenses::addExpense()
{
    cout << "<<<<< ADDING EXPENSE >>>>>" <<endl<<endl<<endl;
    vector<Transactions> expenses;
     Transactions transaction;
    transaction = transaction.giveDataOfNewTransaction();
    expenses.push_back(transaction);
}
