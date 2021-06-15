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

