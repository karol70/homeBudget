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
        int enteredDataInt;

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
           enteredData = auxiliaryMethods.loadCurrentYear()+"-"+auxiliaryMethods.loadCurrentMonth()+"-"+auxiliaryMethods.loadCurrentDay();
       }
       else if(yOrN == 'N')
       {
         cout << "Enter transaction date in format yyyy-mm-dd: ";
        enteredData= auxiliaryMethods.getLine();
        while (auxiliaryMethods.isDateCorrect(enteredData)==false)
        {
        cout << "Enter transaction date in format yyyy-mm-dd: ";
        enteredData= auxiliaryMethods.getLine();
        enteredDataInt = auxiliaryMethods.convertDateToInt(enteredData);
       }
       }
         transaction.setDate(enteredDataInt);

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

void TransactionManager::showAllTransactions(vector<Transactions> transaction)
{

    if (!transaction.empty())
    {
        cout << "-----------------------------------------------" << endl;
        for (vector <Transactions> :: iterator itr = transaction.begin(); itr != transaction.end(); itr++)
        {
            showTransactions(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Transaction history is empty" << endl << endl;

    }

}
void TransactionManager::showTransactions(Transactions transaction)
{
    int date = transaction.getDate();
    cout << endl << "Transaction Id:      " << transaction.getTransactionId() << endl;
    cout << "User Id:                     " << transaction.getLoggedUserId() << endl;
    cout << "Date:                        " << auxiliaryMethods.convertDateToString(date)<< endl;
    cout << "Item:                        " << transaction.getItem() << endl;
    cout << "Amount:                      " << transaction.getAmount ()<< endl;

}
/*    bool TransactionManager::sortByDate(  Transactions  lhs,  Transactions  rhs)
{
    return lhs.getDate() < rhs.getDate();
}
*/
    void TransactionManager::showBalance(int dateFrom, int dateTo)
    {
        vector <Transactions> balanceIncomes;
        vector <Transactions> balanceExpenses;
        string dateFromStr = auxiliaryMethods.convertDateToString(dateFrom);
        string dateToStr = auxiliaryMethods.convertDateToString(dateTo);
        double incomesAmount = 0;
        double expensesAmount = 0;

        for (int i =0;i<incomes.size();i++)
        {
            if (incomes[i].getDate() >= dateFrom  && incomes[i].getDate() <= dateTo)
            {
                balanceIncomes.push_back(incomes[i]);
                incomesAmount += incomes[i].getAmount();
            }
        }

        for (int i =0;i<expenses.size();i++)
        {
            if (expenses[i].getDate() >= dateFrom  && expenses[i].getDate() <= dateTo)
            {
                balanceExpenses.push_back(expenses[i]);
                expensesAmount += expenses[i].getAmount();
            }
        }

    //    sort(balanceIncomes.begin(),balanceIncomes.end(),sortByDate);
    //    sort(balanceExpenses.begin(),balanceExpenses.end(),sortByDate);
        system("cls");
        cout << "<<<<< INCOMES FROM " << dateFromStr << " TO " <<dateToStr <<" >>>>>" <<endl;
        showAllTransactions(balanceIncomes);

        cout << "<<<<< EXPENSES FROM " << dateFromStr << " TO " <<dateToStr <<" >>>>>" <<endl;
        showAllTransactions(balanceExpenses);

        cout << "Sum of incomes: " << incomesAmount<<endl;
        cout << "Sum of expenses: " << expensesAmount<<endl<<endl;
        cout << "Balance: "<<  incomesAmount - expensesAmount  <<endl;
    }

    void TransactionManager::showBalanceOfCurrentMonth()
    {
        cout << "<<<<< BALANCE OF CURRENT MONTH >>>>>" <<endl<<endl<<endl;

        string yearStr = auxiliaryMethods.loadCurrentYear();
        int year = atoi(yearStr.c_str());
        string monthStr = auxiliaryMethods.loadCurrentMonth();
        int month = atoi(monthStr.c_str());
        int days = auxiliaryMethods.getNumberOfDaysOfMonth(year,month);

        string daysStr = to_string(days);

        string dateFromStr = yearStr + monthStr + "01";
        int dateFrom = atoi(dateFromStr.c_str());

        string dateToStr = yearStr + monthStr + daysStr;
        int dateTo = atoi(dateToStr.c_str());


        showBalance(dateFrom,dateTo);


    }
    void TransactionManager::showBalanceOfPreviousMonth()
    {
        cout << "<<<<< BALANCE OF PREVIOUS MONTH >>>>>" <<endl<<endl<<endl;

        int year=0;
        string yearStr="";
        int previousMonth=0;
        string previousMonthStr="";

    string monthStr = auxiliaryMethods.loadCurrentMonth();
    int month = atoi(monthStr.c_str());
        if (month == 1)
        {
            previousMonth = 12;
            previousMonthStr = to_string(previousMonth);
            yearStr = auxiliaryMethods.loadCurrentYear();
            year = atoi(yearStr.c_str()) -1;
            yearStr = to_string(year);

        }
       else if (month > 1)
        {
          previousMonth = month - 1;
          if (month <=10)
          {
              previousMonthStr = "0"+to_string(previousMonth);
          }
          else
          {
            previousMonthStr = to_string(previousMonth);
          }

          yearStr = auxiliaryMethods.loadCurrentYear();
          year = atoi(yearStr.c_str());

        }
      //  cout << month<< endl;
      //  system("pause");
        int days = auxiliaryMethods.getNumberOfDaysOfMonth(year,previousMonth);
        string daysStr = to_string(days);

        string dateFromStr = yearStr + previousMonthStr + "01";
        int dateFrom = atoi(dateFromStr.c_str());

        string dateToStr = yearStr + previousMonthStr + daysStr;
        int dateTo = atoi(dateToStr.c_str());


        showBalance(dateFrom,dateTo);
    }
    void TransactionManager::showBalanceOfChoosenPeriod()
    {
        cout << "<<<<< BALANCE OF CHOOSEN PERIOD >>>>>" <<endl<<endl<<endl;


        int firstEnteredDataInt;
        int secondEnteredDataInt;

        cout << "Enter first date of choosen period in format yyyy-mm-dd: ";
        string firstEnteredData= auxiliaryMethods.getLine();
        while (auxiliaryMethods.isDateCorrect(firstEnteredData)==false)
        {
        cout << "Enter first date of choosen period in format yyyy-mm-dd: ";
        firstEnteredData= auxiliaryMethods.getLine();
        }
        firstEnteredDataInt = auxiliaryMethods.convertDateToInt(firstEnteredData);

        cout << "Enter second date of choosen period in format yyyy-mm-dd: ";
        string secondEnteredData= auxiliaryMethods.getLine();
        while (auxiliaryMethods.isDateCorrect(secondEnteredData)==false)
        {
        cout << "Enter second date of choosen period in format yyyy-mm-dd: ";
        secondEnteredData= auxiliaryMethods.getLine();
        }
        secondEnteredDataInt = auxiliaryMethods.convertDateToInt(secondEnteredData);


        showBalance(firstEnteredDataInt,secondEnteredDataInt);

    }
