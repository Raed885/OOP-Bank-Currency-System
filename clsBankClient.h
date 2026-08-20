#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
using namespace std;

class clsBankClient : public	 clsPerson {

private:

	enum enMode { EmptyMode = 0, UpdatedMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;

	static string _PrepareTransferLogIn(clsBankClient From,clsBankClient To,float Amount, string Seperator = "#//#")
	{

		string stDataLine = clsDate::GetSystemDateTimeString() + Seperator;
		stDataLine += From.GetAccountNumber() + Seperator;
		stDataLine += To.GetAccountNumber() + Seperator;
		stDataLine += to_string(Amount) + Seperator;
		stDataLine += to_string(From.GetAccountBalance()) + Seperator;
		stDataLine +=to_string(To.GetAccountBalance()) + Seperator;
		stDataLine+=CurrentUser.UserName;

		return stDataLine;
	}

	static clsBankClient _ConvertLinetoClientObject(string Line, string Separtor = "#//#") {

		vector<string > vClientData;
		vClientData = clsString::Split(Line, Separtor);

		return clsBankClient(enMode::UpdatedMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.GetAccountNumber() + Seperator;
		stClientRecord += Client.GetPinCode() + Seperator;
		stClientRecord += to_string(Client.GetAccountBalance());

		return stClientRecord;

	}

static	vector<clsBankClient> _LoadClientsDataFromFile() {

		vector<clsBankClient> vClients;
		fstream MyFile("Clients.txt", ios::in);

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				if (!Line.empty()) {
					clsBankClient Client = _ConvertLinetoClientObject(Line);
					vClients.push_back(Client);
				}
			}
			MyFile.close();
		}
		return vClients;
	}

	void _SaveClientDataToFile(vector<clsBankClient>& vClients) {

		fstream MyFile("Clients.txt", ios::out);
		string DataLine;
		if (MyFile.is_open()) {
			for (clsBankClient C : vClients) {
				if (C._MarkForDelete == false) {
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}

		}

		_SaveClientDataToFile(_vClients);

	}

	void _AddNew() {

		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBankClient _GetEmptyClientObject() {

		return clsBankClient(enMode::EmptyMode, "", "", "", "","","", 0);
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += GetAccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.GetAccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
	struct stTransferRegisterRecord;

	static stTransferRegisterRecord _ConvertTransferRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stTransferRegisterRecord TransferRegisterRecord;


		vector <string> TransferRegisterDataLine = clsString::Split(Line, Seperator);
		TransferRegisterRecord.DateTime = TransferRegisterDataLine[0];
		TransferRegisterRecord.SouAccountNumber = TransferRegisterDataLine[1];
		TransferRegisterRecord.DesAccountNumber = TransferRegisterDataLine[2];
		TransferRegisterRecord.Amount = stoi(TransferRegisterDataLine[3]);
		TransferRegisterRecord.SouAccountBalance = stoi(TransferRegisterDataLine[4]);
		TransferRegisterRecord.DesAccountBalance = stoi(TransferRegisterDataLine[5]);
			TransferRegisterRecord.UserName = TransferRegisterDataLine[6];

		return TransferRegisterRecord;

	}

public:


	struct stTransferRegisterRecord
	{
		string DateTime;
		string SouAccountNumber;
		string DesAccountNumber;
		float Amount;
		float SouAccountBalance;
		float DesAccountBalance;
		string UserName;

	};

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, 
		string AccountNumber, string PinCode, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
			_AccountNumber = AccountNumber;
			_PinCode = PinCode;
			_AccountBalance = AccountBalance;
		}

	bool isEmpty() {
		return (_Mode == EmptyMode);
	}

	string GetAccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {

		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;  //Property System: The __declspec(property) creates properties that can be accessed like this:

	                                                                          //client.PinCode = "1234";  // Sets pin code
	                                                                          //string pin = client.PinCode;  // Gets pin code
	                                                                         //It's a shorthand for GetPinCode() and SetPinCode().
	void SetAccountBalance(float AccountBalance) {

		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	/*
	No UI Related code iside object.
  void Print()
  {
	  cout << "\nClient Card:";
	  cout << "\n___________________";
	  cout << "\nFirstName   : " << FirstName;
	  cout << "\nLastName    : " << LastName;
	  cout << "\nFull Name   : " << FullName();
	  cout << "\nEmail       : " << Email;
	  cout << "\nPhone       : " << Phone;
	  cout << "\nAcc. Number : " << _AccountNumber;
	  cout << "\nPassword    : " << _PinCode;
	  cout << "\nBalance     : " << _AccountBalance;
	  cout << "\n___________________\n";

  }*/

		static clsBankClient Find(string AccountNumber) {

			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open()) {

				string Line;

				while (getline(MyFile, Line)) {

					clsBankClient Client = _ConvertLinetoClientObject(Line);
					if (Client.GetAccountNumber() == AccountNumber) {
						MyFile.close();
						return Client;
					}
				}
				MyFile.close();
			}
			return _GetEmptyClientObject();
		}

		static clsBankClient Find(string AccountNumber,string PinCode) {

			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open()) {

				string Line;

				while (getline(MyFile, Line)) {

					clsBankClient Client = _ConvertLinetoClientObject(Line);
					if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode) {
						MyFile.close();
						return Client;
					}
				}
				MyFile.close();
			}
			return _GetEmptyClientObject();
		}

		enum enSaveResult{sFaildEmptyObject=0, sSucceeded=1, sFaildAccountNumberExists = 2};

		enSaveResult Save() {

			switch (_Mode) {

			case enMode::EmptyMode: {

				return enSaveResult::sFaildEmptyObject;
			}

			case enMode::UpdatedMode: {
				_Update();
				return enSaveResult::sSucceeded;
				break;
			}
              
			case enMode::AddNewMode: {

				if (IsClientExist(_AccountNumber)) {
					return enSaveResult::sFaildAccountNumberExists;
				}
				else{

					_AddNew();

					_Mode = enMode::UpdatedMode; // Change mode to UpdatedMode after adding new client.
					return enSaveResult::sSucceeded;
				}
				break;
			}
			}
		}

		static bool IsClientExist(string AccountNumber) {

			clsBankClient Client1 = clsBankClient::Find(AccountNumber);

			return (!Client1.isEmpty());
		}
		
		bool Delete()
		{
			vector <clsBankClient> _vClients;
			_vClients = _LoadClientsDataFromFile();

			for (clsBankClient& C : _vClients)
			{
				if (C.GetAccountNumber() == _AccountNumber)
				{
					C._MarkForDelete = true;
					_MarkForDelete = true;
					break;
				}
			}

			if (_MarkForDelete) {
				// proceed to file only if true
				_SaveClientDataToFile(_vClients);
				*this = _GetEmptyClientObject();

				return true;
			}
			*this = _GetEmptyClientObject();

			return false;
		}

		static clsBankClient GetAddNewClienToObject(string AccountNumber) {

			return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0); //This will create a new client object in AddNewMode with 
			                                                                               //the provided AccountNumber.
		}

		static vector<clsBankClient> GetClientsList() {

			return _LoadClientsDataFromFile();
		}

		static float GetTotalBalance() {

			vector<clsBankClient> vClients=clsBankClient::GetClientsList();

			int TotalBalance = 0;

			for (clsBankClient& C : vClients) {

				TotalBalance += C.AccountBalance;
			}
			return TotalBalance;
		}

		void Deposit(double Amount) {

			_AccountBalance += Amount;
			Save(); // Save the updated balance to the file
		}

		bool Withdraw(double Amount) {

			if (Amount > _AccountBalance)
			{
				return false; // Not enough balance to withdraw
			}
			else {
				_AccountBalance -= Amount;
				Save(); // Save the updated balance to the file
				return true;
			}
		}

	 double Transfer(float Amount, clsBankClient& DestinationClient, string UserName) {

		 if (Amount > _AccountBalance ) {
			 return false; // Not enough balance to transfer
			}
		 Withdraw(Amount); // Withdraw from the source client
		 DestinationClient.Deposit(Amount); // Deposit to the destination client
		 _RegisterTransferLog(Amount, DestinationClient, UserName);
		 return true; // Transfer successful
	}

	 static  vector <stTransferRegisterRecord> GetTransferRegisterList()
	 {
		 vector <stTransferRegisterRecord> vLoginRegisterRecord;

		 fstream MyFile;
		 MyFile.open("TransferLog.txt", ios::in);//read Mode

		 if (MyFile.is_open())
		 {

			 string Line;

			 stTransferRegisterRecord TransferRegisterRecord;

			 while (getline(MyFile, Line))
			 {

				 TransferRegisterRecord = _ConvertTransferRegisterLineToRecord(Line);

				 vLoginRegisterRecord.push_back(TransferRegisterRecord);

			 }

			 MyFile.close();

		 }

		 return vLoginRegisterRecord;

	 }


};

	

