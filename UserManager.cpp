#include "UserManager.h"

using namespace std;

void UserManager::userRegistration()
{
    User user = enterDataOfNewUser();

    users.push_back(user);

 //   fileWithUsers.addUsersToFile(user);

    cout << endl << "Account created succesfully" << endl << endl;
    system("pause");
}

User UserManager::enterDataOfNewUser()
{
    User user;

    user.setId(loadIdOfNewUser());

    string name;
    cout << "Enter name: ";
    cin>>name;
    user.setName(name);

    string surname;
    cout << "Enter surname: ";
    cin>>surname;
    user.setSurname(surname);

    string login;
    do
    {
        cout << "Enter login: ";
        cin >>login;
        user.setLogin(login);

    }
    while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin>>password;
    user.setPassword(password);

    return user;
}

int UserManager::loadIdOfNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
        for (int i = 0; i<users.size();i++)
        {
            if (users[i].getLogin() == login)
            {
             cout << endl << "Login already exists." << endl;
            return true;
            }

        }
        return false;
}

int UserManager::userLogIn()
{
    User user;
    string login = "", password = "";

    cout << "Enter login: ";
    login = auxiliaryMethods.getLine();

  for (int i = 0; i<users.size();i++)

    {
        if (users[i].getLogin() == login)
        {
            for (int Trials = 3; Trials > 0; Trials--)
            {
                cout << "Enter password. Trials left: " << Trials << ": ";
                password = auxiliaryMethods.getLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Logged in." <<endl << endl;
                    system("pause");

                    loggedUserId = users[i].getId();
                    return loggedUserId;

                }
            }
            cout << "Incorrect password entered three times" << endl;
            system("pause");
            return 0;
        }

    }
    cout << "There's no user with entered login" << endl << endl;
    system("pause");
    return 0;
}

int UserManager::userLogOut()
   {
    loggedUserId = 0;
    cout << "Logged Out";
   }

