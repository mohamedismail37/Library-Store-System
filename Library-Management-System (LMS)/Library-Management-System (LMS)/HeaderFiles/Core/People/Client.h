#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include <vector>
#include <fstream>
#include "MyString.h"

using namespace std;

class clsClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _Email;
	short _Age;

	static clsClient _ConvertLineToClientObject(string Line, string Separtor = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsMyString::Split(Line);

		enum _enNames
		{
			Name = 0, Password = 1, Permission = 2, Gender = 3, Email = 4, Age = 5
		};

		return clsClient(UpdateMode, vClientData[Name], vClientData[Password], _enPermission(stoi(vClientData[Permission])),
			stoi(vClientData[Gender]), vClientData[Email], stoi(vClientData[Age]));
	}

	static clsClient _GetEmptyClientObject()
	{
		return clsClient(EmptyMode, "", "",_Client , 0, "", 0);
	}

	static vector <clsClient> _LoadClientsDataFromFile()
	{
		vector <clsClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);

				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static string _ConverClientObjectToLine(clsClient Client, string Separator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.GetName() + Separator;
		stClientRecord += Client.GetPassword() + Separator;
		stClientRecord += to_string(Client.GetPermission()) + Separator;
		stClientRecord += to_string(Client.GetGender()) + Separator;
		stClientRecord += Client.GetEmail() + Separator;
		stClientRecord += to_string(Client.GetAge()) + Separator;

		return stClientRecord;
	}

	static void _SaveClientDataToFile(vector <clsClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsClient C : vClients)
			{
				DataLine = _ConverClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsClient& C : _vClients)
		{
			if (C.GetName() == GetName())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddDataLineToFile(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}


public:
	clsClient(int Mode, string Name, string Password, int Permission, bool Gender, string Email, short Age) 
		: clsPerson(Name,Password, _enPermission(Permission),Gender)
	{
		_Mode = enMode(Mode);
		_Email = Email;
		_Age = Age;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}

	void SetAge(short Age)
	{
		_Age = Age;
	}
	short GetAge()
	{
		return _Age;
	}

	void PrintClientCard()
	{
		cout << "\nClient Card: ";
		cout << "\n--------------------------";
		cout << "\nName : " << GetName();
		cout << "\nPassword : " << GetPassword();
		cout << "\nPermission : " << GetPermission();
		cout << "\nGender : " << GetGender();
		cout << "\nEmail : " << GetEmail();
		cout << "\nAge : " << GetAge();
		cout << "\n--------------------------";
	}

	static clsClient Find(string Name)
	{
		vector <clsClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetName() == Name)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsClient Find(string Name, string Password)
	{
		vector <clsClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetName() == Name && Client.GetPassword() == Password)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string Name)
	{
		clsClient Client1 = clsClient::Find(Name);

		return (!Client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded =1 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case EmptyMode:
			return svFaildEmptyObject;
			break;
		case UpdateMode:
			_Update();
			return svSucceeded;
			break;
		case AddNewMode:
			_AddNew();
			break;
		}
	}

	static clsClient GetAddNewClientObject(string Name)
	{
		return clsClient(AddNewMode, Name, "", 3, 0, "", 0);
	}
};