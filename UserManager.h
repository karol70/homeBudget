#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include <iostream>
#include "User.h"
#include "AuxiliaryMethods.h"


using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    AuxiliaryMethods auxiliaryMethods;

    User enterDataOfNewUser();
    int loadIdOfNewUser();
    bool isLoginExist(string login);


public:
    void userRegistration();
    int userLogIn();
    int userLogOut();


};


#endif
