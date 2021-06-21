#include "HomeBudget.h"
using namespace std;

  void HomeBudget::userRegister()
  {
      userManager.userRegistration();
  }

  void HomeBudget::userLogIn()
  {
      userManager.userLogIn();
  }
  void HomeBudget::userLogOut()
  {
      userManager.userLogOut();
  }
void HomeBudget::showAllusers()
{
    userManager.showAllUsers();
}
void HomeBudget::addIncome()
{
    incomes.addIncome();
}
void HomeBudget::addExpense()
{
    expenses.addExpense();
}
