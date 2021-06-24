#include "fileWithTransactions.h"

bool FileWithTransactions::isFileEmpty(string fileName)
{


    bool isEmpty = true;
    CMarkup xml;
    xml.Load(fileName);
    if (xml.FindElem() == true)
    {
        isEmpty = false;
    }
    else isEmpty = true;

    return isEmpty;

}

void FileWithTransactions::addTransactionToFile(Transactions transaction,string transactionFileName,string IncomeOrExpense)
{
    if(isFileEmpty(transactionFileName)==true)
    {
        CMarkup xml;
        xml.AddElem("TRANSACTIONS");
        xml.Save(transactionFileName);
    }

    CMarkup xml;
    xml.Load(transactionFileName);
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( IncomeOrExpense);
    xml.IntoElem();
    xml.AddElem( "USER_ID",transaction.getLoggedUserId());
    xml.AddElem( "TRANSACTION_ID",transaction.getTransactionId());
    xml.AddElem( "DATE",transaction.getDate());
    xml.AddElem( "ITEM",transaction.getItem());
    string amount = to_string(transaction.getAmount());
    amount = amount.erase(amount.find(".")+3);
    xml.AddElem( "AMOUNT",amount);
    xml.OutOfElem();
    xml.Save(transactionFileName);

}
vector<Transactions> FileWithTransactions::loadTransactionsFromFile(int LOGGED_USER_ID, string transactionFileName,string IncomeOrExpense)
{
    if(isFileEmpty(transactionFileName)==true)
    {
        cout << "File: " << transactionFileName << " is empty" << endl;
    }
    else
    {

    Transactions transaction;
    vector<Transactions> transactions;
    CMarkup xml;
    xml.Load(transactionFileName);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem(IncomeOrExpense))
    {
        xml.IntoElem();
        xml.FindElem("USER_ID");
        int loadedUserId = atoi(MCD_2PCSZ(xml.GetData()));

        if (loadedUserId == LOGGED_USER_ID)
        {
            xml.FindElem(IncomeOrExpense + "_ID");
            int loadedTransactionId = atoi(MCD_2PCSZ(xml.GetData()));

            xml.FindElem("DATE");
            string loadedDate = xml.GetData();

            xml.FindElem("ITEM");
            string loadedItem = xml.GetData();

            xml.FindElem("AMOUNT");

            double loadedAmount = atof(xml.GetData().c_str());
            xml.OutOfElem();

            transaction.setloggedUserId(loadedUserId);
            transaction.setTransactionId(loadedTransactionId);
            transaction.setDate(loadedDate);
            transaction.setItem(loadedItem);
            transaction.setAmount(loadedAmount);

            transactions.push_back(transaction);
        }
        else
        xml.OutOfElem();
    }

    return transactions;
}
}
