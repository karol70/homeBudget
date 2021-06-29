#include "HomeBudget.h"
using namespace std;

  void HomeBudget::userRegister()
  {
      userManager.userRegistration();
  }

  void HomeBudget::userLogIn()
  {
      userManager.userLogIn();
      if (userManager.isUserLoggedIn())
      {
          transactionManager = new TransactionManager ("incomes.xml","expenses.xml",userManager.getLoggedUserId());
      }
  }
  void HomeBudget::userLogOut()
  {
      userManager.userLogOut();
      delete transactionManager;
      transactionManager = NULL;
  }
void HomeBudget::showAllusers()
{
    userManager.showAllUsers();
}
void HomeBudget::addIncome()
{
    transactionManager -> addIncome();
}
void HomeBudget::addExpense()
{
    transactionManager -> addExpense();
}

void HomeBudget::changePassword()
{
 userManager.changePassword();
}

void HomeBudget::showBalanceOfCurrentMonth()
{
    transactionManager -> showBalanceOfCurrentMonth();
}
void HomeBudget::showBalanceOfPreviousMonth()
{
    transactionManager -> showBalanceOfPreviousMonth();
}
void HomeBudget::showBalanceOfChoosenPeriod()
{
    transactionManager -> showBalanceOfChoosenPeriod();
}
