#include "Transactions.h"

void Transactions::setloggedUserId(int newLoggedUserId)
{
    loggedUserId = newLoggedUserId;
}
void Transactions::setTransactionId(int newTransactionId)
{
    transactionId = newTransactionId;
}
void Transactions::setDate(int newDate)
{
    date = newDate;
}
void Transactions::setItem(string newItem)
{
    item = newItem;
}
void Transactions::setAmount(double newAmount)
{
    amount = newAmount;
}
int Transactions::getLoggedUserId()
{
    return loggedUserId;
}

int Transactions::getTransactionId()
{
    return transactionId;
}
int Transactions::getDate()
{
    return date;
}
string Transactions::getItem()
{
    return item;
}
double Transactions::getAmount()
{
    return amount;
}

