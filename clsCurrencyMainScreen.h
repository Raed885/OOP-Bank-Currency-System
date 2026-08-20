#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyMainScreen : protected clsScreen {

private:
    enum enManageCurrencyMenuOptions {
        eListCurrencies = 1,
        eFindCurrency = 2,
        eUpdateCurrency = 3,
        eCurrencyCalculator = 4,
        eMainMenu = 5
    };

    static short ReadManageCurrenciesMenuOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        return clsInputValidate::ReadNumberBetween<int>(1, 5, "Enter Number between 1 to 5? ");
    }

    static void _GoBackToManageCurrenciesMenu() {
        cout << "\n\nPress any key to go back to Manage Currencies Menu...";
        system("pause>0");
        ShowManageCurrenciesMenu();
    }

    static void _ShowCurrenciesListScreen() {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateCurrencyRateScreen() {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformManageCurrenciesMenuOption(enManageCurrencyMenuOptions option) {
        system("cls");

        switch (option) {
        case eListCurrencies:
            _ShowCurrenciesListScreen();
            break;
        case eFindCurrency:
            _ShowFindCurrencyScreen();
            break;
        case eUpdateCurrency:
            _ShowUpdateCurrencyRateScreen();
            break;
        case eCurrencyCalculator:
            _ShowCurrencyCalculatorScreen();
            break;
        case eMainMenu:
            return;
        }

        _GoBackToManageCurrenciesMenu();
    }

public:
    static void ShowManageCurrenciesMenu() {
        if (!CheckAccessRights(clsUser::enPermissions::PCurrencyScreen)) {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t Manage Currencies Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Currency Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformManageCurrenciesMenuOption((enManageCurrencyMenuOptions)ReadManageCurrenciesMenuOption());
    }
};
