#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"

#include "Global.h"


class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        int Trials = 3;
        do
        {

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

            if (LoginFaild) {

                Trials--;

                if (Trials == 0)
                {
                    cout << "\nYou have no trials left, please contact your admin.\n";
                    return false;
				
                }
                cout << "\nInvalid Username/Password!\n\n";

                cout << "\nYou have " << Trials << " trials left.\n";

            }
        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
		return true;
    }

public:

    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
