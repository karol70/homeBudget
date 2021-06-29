#include <iostream>
#include "HomeBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;


char chooseFromMenuLogin();
char chooseFromMainMenu();

int main()
{
    HomeBudget homeBudget;

    int loggedUserId = 0;

    char choice;

    while (true)
    {
        cin.sync();
        if (loggedUserId == 0)
        {
            choice = chooseFromMenuLogin();

            switch (choice)
            {
            case '1':
                homeBudget.userRegister();
                break;
            case '2':
                loggedUserId = homeBudget.userLogIn();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Wrong number choosed" << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {

            choice = chooseFromMainMenu();

            switch (choice)
            {
            case '1':
                homeBudget.addIncome();
                break;
            case '2':
                homeBudget.addExpense();
                break;
            case '3':
                homeBudget.showBalanceOfCurrentMonth();
                break;
            case '4':
                homeBudget.showBalanceOfPreviousMonth();
                break;
            case '5':
                homeBudget.showBalanceOfChoosenPeriod();
                break;
            case '6':
                homeBudget.changePassword();
                break;
            case '7':
                homeBudget.userLogOut();
                loggedUserId =0;
                break;

            }
        }
    }
    return 0;
}

char chooseFromMenuLogin()
{

    char choice;
    AuxiliaryMethods auxiliaryMethods;

    system ("cls");
    cout<< "<<<<< HOME BUDGET >>>>>"<<endl<<endl;
    cout<<"1. Registration."<<endl;
    cout<<"2. Log in."<<endl;
    cout<<"3. Exit."<<endl;

    choice = auxiliaryMethods.loadCharacter();
    return choice;
}

char chooseFromMainMenu()
{

    char choice;
    AuxiliaryMethods auxiliaryMethods;

    system("cls");
    cout<< "<<<<< HOME BUDGET >>>>>"<<endl<<endl;
    cout<<"1. Add income."<<endl;
    cout<<"2. Add expense."<<endl;
    cout<<"3. Balance of current month."<<endl;
    cout<<"4. Balance of previous month."<<endl;
    cout<<"5. Balance of choosen period."<<endl;
    cout<<"6. Change password."<<endl;
    cout<<"7. Log Out."<<endl;

    choice = auxiliaryMethods.loadCharacter();
    return choice;


}


