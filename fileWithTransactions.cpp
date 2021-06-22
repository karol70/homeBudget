#include "fileWithTransactions.h"

 bool FileWithTransactions::isFileEmpty(string fileName)
{


     bool isEmpty = true;
    CMarkup xml;
    xml.Load("incomes.xml");
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
    xml.AddElem( "USER ID" ,transaction.getLoggedUserId());
    xml.AddElem( "TRANSACTION ID",transaction.getTransactionId());
    xml.AddElem( "DATE" ,transaction.getDate());
    xml.AddElem( "ITEM" ,transaction.getItem());
    xml.AddElem( "AMOUNT",transaction.getAmount());
    xml.OutOfElem();
    xml.Save(transactionFileName);

 }

