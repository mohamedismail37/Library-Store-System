#pragma once
#include <iostream>
#include "Screen.h"
#include "GlobalVariables.h"
#include "InputAndOutput.h"
#include "Client.h"
#include "AdminDashboardScreen.h"
using namespace std;

class clsLoginScreen : public clsScreen
{
private:

	static void _StaffOnlyPage()
	{
		Header("Staff Only Page");
		string Name = clsInputOutput::ReadString("\nName : ");
		string Password = clsInputOutput::ReadString("\nPassword : ");
		if (Name == "Admin" && Password == "1234")
		{
			CurrentUser = eAdmin;
			clsAdminDashBoard::DashBoardScreen();
		}

	}

	static void _ReadClientInfo(clsClient &Client)
	{
		Client.SetName(clsInputOutput::ReadString("\nName : "));
		Client.SetPassword(clsInputOutput::ReadString("\Password : "));
		Client.SetPermission(3);
		Client.SetGender(clsInputOutput::ReadGender("\nGender (M/F)?"));
		Client.SetEmail(clsInputOutput::ReadEmail("\nEmail : "));
		Client.SetAge(clsInputOutput::ReadInt("\nAge : "));

		Client.Save();
	}

	static void _SignUpPage()
	{
		Header("Sign up Page");

		clsClient NewClient(2, "", "", 0, 0, "", 0);

		_ReadClientInfo(NewClient);

		CurrentUser = eClient;

	}

	static void _LoginPage()
	{
		Header("Login Page");
		string Name = clsInputOutput::ReadString("\nName : ");
		string Password = clsInputOutput::ReadString("\nPassword : ");
		clsClient Client = clsClient::Find(Name, Password);

		while (Client.IsEmpty())
		{
			cout << "\nInvalid Name or Password! Please enter them again\n";
			Name = clsInputOutput::ReadString("\nName : ");
			Password = clsInputOutput::ReadString("\nPassword : ");
			Client = clsClient::Find(Name, Password);
		}

		CurrentUser = eClient;

	}

	static void _FowardLoginScreen(int Number)
	{
		switch (Number)
		{
		case 1:
			_LoginPage();
			break;
		case 2:
			_SignUpPage();
			break;
		case 3:
			_StaffOnlyPage();
			LoginScreen();
			break;
		}
	}

public:
	static void LoginScreen()
	{
		Header("Login Page");

		if (CurrentUser == eUnsigned)
		{
			cout << "\n(1) Login\t\t\t(2) Sign up\t\t\t(3) etc\n";
			int Number = clsInputOutput::ReadNumberInRange(1, 3, "\nChoice : ");
			_FowardLoginScreen(Number);
		}
		else
		{
			char Logout;
			cout << "\nDo you want to Logout? (Y/N)?\n";
			cin >> Logout;
			if (Logout == 'y' || Logout == 'Y')
			{
				CurrentUser = eUnsigned;
			}
		}
	}
};
