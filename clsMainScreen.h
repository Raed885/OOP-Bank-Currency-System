#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyMainScreen.h"
#include "Global.h"
#include <iomanip>
using namespace std;


class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister=8,eCurrencyExchangeMainScreen=9, eExit = 10
    };

    static short _ReadMainMenueOption() {
        cout << "\t\t\tChoose what do you want to do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadNumberBetween<int>(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
		clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
		clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();

    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();

		ShowMainMenue(); // Go back to main menu after transactions //the most memory-efficient and cleanest, 
                                                                    //especially in big projects or when writing reusable UI components.
    }

    static void _ShowManageUsersMenue()
    {
		clsManageUsersScreen::ShowManageUsersMenue();
        ShowMainMenue();
    }

    static void _ShowLoginRegisterationScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
        ShowMainMenue();
    }

    static void _ShowManageCurrenciesMenue()
    {
        clsCurrencyMainScreen::ShowManageCurrenciesMenu();
        ShowMainMenue();
    }

  /*  static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/

    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");
        //then it will go back to main function.
    }


    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterationScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExchangeMainScreen:
            system("cls");
            _ShowManageCurrenciesMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }

public:

    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << "\t\t\t\t===========================================\n";
        cout << "\t\t\t\t\t\tMain Menu\n";
        cout << "\t\t\t\t===========================================\n";
        cout << "\t\t\t\t[1] Show Client List.\n";
        cout << "\t\t\t\t[2] Add New Client.\n";
        cout << "\t\t\t\t[3] Delete Client.\n";
        cout << "\t\t\t\t[4] Update Client Info.\n";
        cout << "\t\t\t\t[5] Find Client.\n";
        cout << "\t\t\t\t[6] Transactions.\n";
        cout << "\t\t\t\t[7] Manage Users.\n";
        cout << "\t\t\t\t[8] Login Register.\n";
        cout << "\t\t\t\t[9] Currency Exchange.\n";
        cout << "\t\t\t\t[10] Logout.\n";
        cout << "\t\t\t\t===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
};
