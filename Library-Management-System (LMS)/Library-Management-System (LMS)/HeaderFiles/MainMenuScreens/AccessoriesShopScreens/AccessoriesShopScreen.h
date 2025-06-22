#pragma once
#include <iostream>
#include "Screen.h"
#include "InputAndOutput.h"
#include "ListAccessoriesScreen.h"
using namespace std;

class clsAccessoriesShopScreens : public clsScreen
{
private:
	enum _enScreenForward { List = 1, Back = 2 };

	static void _AccessoriesShopChoiceForward(_enScreenForward Choice)
	{
		switch (Choice)
		{
		case List:
			clsListAccessoiresScreen::ShowAccessorriesList();
			break;
		case Back:
			break;
		}
	}

public:
	static void ShowAccessoriesShopScreen()
	{
		Header("Accessories Shop", 0, 0);
		cout << "\n[1] List all Accessories\t\t\t\t[2] Back to Main Menu\n";
		_AccessoriesShopChoiceForward(_enScreenForward(clsInputOutput::ReadNumberInRange(1, 2, "\nChoose Operation: ")));
	}
};