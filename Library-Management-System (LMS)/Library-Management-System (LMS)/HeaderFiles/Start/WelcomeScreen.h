#pragma once
#include "Screen.h"

class clsWelcomeScreen : public clsScreen
{
public:
	static void WelcomeScreen()
	{
		Header("Welcome to Library Management System (LMS)", false, false);
		cout << "\nPress any key to continue...\n";
		system("pause>0");
	}
};