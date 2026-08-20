#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.GetFullName();
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

	static string _ReadSourceAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{ 
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static string _ReadDestinationAccountNumber(string SourceAccountNumber)
	{
		string AccountNumber;
		cout << "\nPlease Enter Account Number to Transfer To: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber) || AccountNumber== SourceAccountNumber)
		{
			if (AccountNumber == SourceAccountNumber)
			{
				cout << "\nYou can not transfer to the same account!\n";
			}
			else {
					cout << "\nAccount number is not found, choose another one: ";
				}
			
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;

		cout << "\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadNumber<double>();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen() {

		_DrawScreenHeader("\tTransfer Screen");

		string SourceAccountNumber = _ReadSourceAccountNumber();
		clsBankClient SourceClient = clsBankClient::Find(SourceAccountNumber);

		_PrintClient(SourceClient);

		string DestinationAccountNumber = _ReadDestinationAccountNumber(SourceAccountNumber);
		clsBankClient DestinationClient = clsBankClient::Find(DestinationAccountNumber);

		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);

		char Ans = 'y';
		cout << "\nAre you sure you want to perform this operation? y/n?:";
		cin >> Ans;

		if (Ans == 'Y' || Ans == 'y') {

			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName)) {
				cout << "\n\nTransfer completed successfully!";
			}
			else {

				cout << "\nTransfer Faild \n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

		system("pause>0");
	}
	};
