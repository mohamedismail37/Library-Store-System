#pragma once
#include "Screen.h"
#include "LoginAndSignUpScreen.h"
#include "InputAndOutput.h"
#include "GlobalVariables.h"

class clsAdminDashBoard : public clsScreen
{
private:
	static void _ShowBalance()
	{
		Header("Balance Screen");
		cout << "Total Balance = " << TotalBalance << " USD";
		char InEGP;
		cout << "\nDo you Convert Price to EGP? (Y/N)\n";
		cin >> InEGP;
		if (InEGP == 'y' || InEGP == 'Y')
		{
			cout << "\nTotal Balances = " << TotalBalance * 50 << " EGP";
		}
		cout << "\nPress any key to go back\n";
		system("pause>0");
	}

public:
	static void DashBoardScreen()
	{
		Header("Dashboard Screen");
		cout << "\n{1} Total Balances\n{2} Logout\n";
		int Number = clsInputOutput::ReadNumberInRange(1, 2, "Choice : ");
		switch (Number)
		{
		case 1:
			_ShowBalance();
			DashBoardScreen();
			break;
		case 2:
			break;
		}
	}
};