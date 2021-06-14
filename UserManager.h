#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include <iostream>
#include "User.h"


using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;

    User enterDataOfNewUser();
    int loadIdOfNewUser();
    bool isLoginExist(string login);


public:
    void userRegistration();
    int userLogin();
    int userLogOut();

};


#endif
