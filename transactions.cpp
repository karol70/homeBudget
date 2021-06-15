   #include "Transactions.h"


   void Transactions::setTransactionId(int newTransactionId)
    {
        transactionId = newTransactionId;
    }
    void Transactions::setDate(string newDate)
    {
        date = newDate;
    }
    void Transactions::setItem(string newItem)
    {
        item = newItem;
    }
    void Transactions::setAmount(int newAmount)
    {
        amount = newAmount;
    }

    int Transactions::getTransactionId()
    {
        return transactionId;
    }
    string Transactions::getDate()
    {
        return date;
    }
    string Transactions::getItem()
    {
        return item;
    }
    int Transactions::getAmount()
    {
        return amount;
    }

    void Transactions::addTransaction()
    {

    }
