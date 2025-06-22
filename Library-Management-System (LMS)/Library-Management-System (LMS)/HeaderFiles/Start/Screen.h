#pragma once
#include <iostream>
#include <iomanip>
#include "DateAndTime.h"
#include "GlobalVariables.h"
using namespace std;

class clsScreen
{
protected:
	static void Header(string Title, bool Date = true, bool Time = true, bool ShowTheme = false)
	{
		clsDateAndTime DateAndTime;

		if (Theme == Black)
			system("color 07");
		else
			system("color 87");

		system("cls");
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
		cout << "|" << setw(45) << right << Title << setw(36) << "|\n";
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";

		if (Date || Time || ShowTheme)
		{
			string Line = "";
			cout << "|";
			if (Date)
				Line += "       " + DateAndTime.Date();
			if (Time)
				Line += "       " + DateAndTime.Time();
			if (ShowTheme)
			{
				Line += "       Theme : ";
				Line += (Theme == Black) ? "Black" : "Grey";
			}
			cout << Line;
			cout << setw(80 - Line.length()) << "|";

			cout << "\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
		}
	}
};