#ifndef USERMANAGER_H
#define USERMANAGER_H
#include <vector>
#include <iostream>
#include "User.h"
#include "AuxiliaryMethods.h"
#include "FileWithUsers.h"


using namespace std;

class UserManager
{
    int loggedUserId;
    vector <User> users;
    AuxiliaryMethods auxiliaryMethods;
    FileWithUsers fileWithUsers;


    User enterDataOfNewUser();
    int loadIdOfNewUser();
    bool isLoginExist(string login);


public:
    UserManager(){
    loggedUserId = 0;
    users = fileWithUsers.loadUsersFromFile();
    };

    void userRegistration();
    int userLogIn();
    int userLogOut();
    void showAllUsers();
    int getLoggedUserId();
    bool isUserLoggedIn();
    void changePassword();



};


#endif
