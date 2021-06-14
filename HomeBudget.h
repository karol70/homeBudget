#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H
#include "UserManager.h"
#include <iostream>

using namespace std;

class HomeBudget
{
    UserManager userManager;


public:
    void userRegister();
    void userLogIn();
    void userLogOut();
};










#endif
