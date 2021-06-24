#include "transactionsManager.h"

int TransactionManager::loadLastIncomeId()
{
    if (incomes.empty() == true)
        return 1;
else
{
    int lastIncomeId = incomes.back().getTransactionId();
    return lastIncomeId + 1;
}

}
int TransactionManager::loadLastExpenseId()
{
    if (expenses.empty() == true)
        return 1;
else
{
    int lastExpenseId = expenses.back().getTransactionId();
    return lastExpenseId + 1;
}

}


 Transactions TransactionManager::giveDataOfNewTransaction(int lastTransactionId)
    {
       Transactions transaction;


        transaction.setloggedUserId(LOGGED_USER_ID);

       transaction.setTransactionId(lastTransactionId);
        string enteredData;

       char yOrN = 'o';
       cout << "Does transaction concern today? (Y/N):  ";
       while (yOrN !='Y' && yOrN != 'N')
{
       yOrN = auxiliaryMethods.loadCharacter();
       yOrN = toupper(yOrN);
       if (yOrN !='Y' && yOrN != 'N')
        cout<< "Wrong command selected, try again (Y/N): ";

}
       if (yOrN == 'Y')
       {
           enteredData = auxiliaryMethods.loadCurrentYear()+auxiliaryMethods.loadCurrentMonth()+auxiliaryMethods.loadCurrentDay();
       }
       else if(yOrN == 'N')
       {
         cout << "Enter transaction date in format yyyy-mm-dd: ";
        enteredData= auxiliaryMethods.getLine();
        while (auxiliaryMethods.isDateCorrect(enteredData)==false)
        {
        cout << "Enter transaction date in format yyyy-mm-dd: ";
        enteredData= auxiliaryMethods.getLine();
       }
       }
         transaction.setDate(enteredData);

        cout << "Enter transaction item: ";
       transaction.setItem(auxiliaryMethods.getLine());

        cout << "Enter amount of transaction: ";
       string amount = auxiliaryMethods.getLine();
       int position = 0;
       position = amount.find(",");
       if (position >0)
       {
          amount.replace(position,1,".");
       }
       double amounT = atof(amount.c_str());
       transaction.setAmount(amounT);

        return transaction;

    }


 void TransactionManager::addIncome()
 {
     cout << "<<<<< ADDING INCOME >>>>>" <<endl<<endl<<endl;

    string income = "INCOME";
    Transactions transaction;
    transaction = giveDataOfNewTransaction(loadLastIncomeId());
    incomes.push_back(transaction);
    FileWithTransactions fileWithTransactions;
    fileWithTransactions.addTransactionToFile(transaction,INCOMES_FILE_NAME,income);
 }

 void TransactionManager::addExpense()
{
    cout << "<<<<< ADDING EXPENSE >>>>>" <<endl<<endl<<endl;
    string expense = "EXPENSE";
    Transactions transaction;
    transaction = giveDataOfNewTransaction(loadLastExpenseId());
    expenses.push_back(transaction);
    FileWithTransactions fileWithTransactions;
    fileWithTransactions.addTransactionToFile(transaction,EXPENSES_FILE_NAME,expense);
}

void TransactionManager::showAllIncomes()
{
    system("cls");
    if (!incomes.empty())
    {
        cout << "             >>> INCOMES <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Transactions> :: iterator itr = incomes.begin(); itr != incomes.end(); itr++)
        {
            showIncomes(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Incomes are empty" << endl << endl;

    }
    system("pause");
}
void TransactionManager::showIncomes(Transactions transaction)
{

    cout << endl << "Transaction Id:      " << transaction.getTransactionId() << endl;
    cout << "User Id:                     " << transaction.getLoggedUserId() << endl;
    cout << "Date:                        " << transaction.getDate()<< endl;
    cout << "Item:                        " << transaction.getItem() << endl;
    cout << "Amount:                      " << transaction.getAmount ()<< endl;

}


