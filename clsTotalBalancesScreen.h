#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTotalBalancesScreen :protected clsScreen
{
private:
   static void _PrintClientRecordBalanceLine(clsBankClient Client)
    {
        
        cout << "| " << setw(15) << left << Client.GetAccountNumber();
        cout << "| " << setw(40) << left << Client.GetFullName();
        cout << "| " << setw(12) << left << Client.GetAccountBalance();

    }

public:

    static void ShowTotalBalancesScreen() {

        _DrawScreenHeader("\tTotal Balance Screen");

        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        cout << "\n\t\t\t\t\tBalance List (" << vClients.size() << ") Client(s).";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalance = clsBankClient::GetTotalBalance();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients) {
                _PrintClientRecordBalanceLine(Client);
                cout << endl;
            }
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t\t\t\tTotal Balance= " << TotalBalance << endl;
        cout << "\t\t\t\t    (" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

        cout << "\n\nPress any key to return to Transactions Menu...\n";
        system("pause>0");
    }
};

