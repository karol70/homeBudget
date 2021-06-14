#include "UserManager.h"

using namespace std;

void UserManager::userRegistration()
{
    User user = enterDataOfNewUser();

    users.push_back(user);

 //   plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

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
