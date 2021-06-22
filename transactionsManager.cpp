#include "transactionsManager.h"

 Transactions TransactionManager::giveDataOfNewTransaction()
    {
       Transactions transaction;


        transaction.setloggedUserId(LOGGED_USER_ID);

       transaction.setTransactionId(1);
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
        while (isDateCorrect(enteredData)==false)
        {
        cout << "Enter transaction date in format yyyy-mm-dd: ";
        enteredData= auxiliaryMethods.getLine();
       }
       }
         transaction.setDate(enteredData);

        cout << "Enter transaction item: ";
       transaction.setItem(auxiliaryMethods.getLine());
        cout << "Enter amount of transaction: ";
       transaction.setAmount(atoi(auxiliaryMethods.getLine().c_str()));

        return transaction;

    }

 bool TransactionManager::isDateCorrect(string Date)
    {

        if(Date.length()==10)
        {

        int mininumDate = 20000101;


        string year = Date.substr(0,Date.find("-"));
        int intConvertedYear = atoi(year.c_str());
        Date.erase(0,4+1);

         string month = Date.substr(0,Date.find("-"));
         int intConvertedMonth = atoi(month.c_str());
        Date.erase(0,2+1);

         string day = Date.substr(0,Date.find("-"));
         int intConvertedDay = atoi(day.c_str());
        Date.erase(0,2+1);

        string convertedDate = year+month+day;
        int intConvertedDate = atoi(convertedDate.c_str());

        string currentYear = auxiliaryMethods.loadCurrentYear();
        int intCurrentYear = atoi(currentYear.c_str());

        string currentMonth = auxiliaryMethods.loadCurrentMonth();
        int intCurrentMonth = atoi(currentMonth.c_str());

        string currentDay = auxiliaryMethods.loadCurrentDay();
        int intCurrentDay = atoi(currentDay.c_str());

        int numberOfDaysOfCurrentMonth = getNumberOfDaysOfMonth(intCurrentYear, intCurrentMonth);
        int numberOfDaysOdChoosenDate = getNumberOfDaysOfMonth(intConvertedYear, intConvertedMonth);

        if(intConvertedYear == intCurrentYear)
           {
             if( intConvertedMonth <= intCurrentMonth && intConvertedDay <= numberOfDaysOfCurrentMonth)
                return true;
           }
          if(intConvertedDate >= mininumDate && intConvertedYear < intCurrentYear)
        {
            if (intConvertedMonth <= 12 && intConvertedDay <= numberOfDaysOdChoosenDate)
            return true;
        }

        }
        cout << "Entered date is incorrect, try again"<<endl;
            return false;


    }

int TransactionManager::getNumberOfDaysOfMonth(int year, int month)
{

    int days;

    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;

    else if (month == 2)
    {
        bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        if (leapyear == 0)
                days = 28;
        else
                days = 29;
    }

    else
    days = 31;

    return days;
}

 void TransactionManager::addIncome()
 {
     cout << "<<<<< ADDING INCOME >>>>>" <<endl<<endl<<endl;

    string income = "INCOME";
    Transactions transaction;
    transaction = giveDataOfNewTransaction();
    incomes.push_back(transaction);
    FileWithTransactions fileWithTransactions;
    fileWithTransactions.addTransactionToFile(transaction,INCOMES_FILE_NAME,income);
 }

 void TransactionManager::addExpense()
{
    cout << "<<<<< ADDING EXPENSE >>>>>" <<endl<<endl<<endl;
    Transactions transaction;
    string expense = "EXPENSE";
    expenses.push_back(giveDataOfNewTransaction());
    FileWithTransactions fileWithTransactions;
    fileWithTransactions.addTransactionToFile(transaction,INCOMES_FILE_NAME,expense);
}
