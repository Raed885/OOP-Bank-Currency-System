#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferLoginScreen :protected clsScreen
{

private:

	static void _PrintClient(clsBankClient::stTransferRegisterRecord TransferRegisterRecord) {

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferRegisterRecord.DateTime;
		cout << "| " << setw(8) << left << TransferRegisterRecord.SouAccountNumber;
		cout << "| " << setw(8) << left << TransferRegisterRecord.DesAccountNumber;
		cout << "| " << setw(8) << left << TransferRegisterRecord.Amount;
		cout << "| " << setw(10) << left << TransferRegisterRecord.SouAccountBalance;
		cout << "| " << setw(10) << left << TransferRegisterRecord.DesAccountBalance;
        cout << "| " << setw(8) << left << TransferRegisterRecord.UserName << endl;
	}

public:

    static void ShowTransferLoginScreen() {


        vector <clsBankClient::stTransferRegisterRecord> vTransferRecord = clsBankClient::GetTransferRegisterList();

        string Title = "\tTransfer login List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(8) << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << "" << left << "" <<
            "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransferRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferRegisterRecord Record : vTransferRecord)
            {
                _PrintClient(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
    }
};
