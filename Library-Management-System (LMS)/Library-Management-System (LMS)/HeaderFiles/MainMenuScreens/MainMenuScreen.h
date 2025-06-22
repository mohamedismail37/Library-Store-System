#pragma once
#include "Screen.h"
#include "InputAndOutput.h"
#include "BooksShopScreens.h"
#include "AccessoriesShopScreen.h"
#include "CartScreen.h"
#include "LoginAndSignUpScreen.h"

class clsMainMenuScreen : public clsScreen
{
private:
	enum _enMainMenuOperations
	{
		_BooksShop = 1, _AccessoriesShop = 2, _LoginAndSignUp = 3, _ChangeTheme = 4 , _Cart = 5
	};

	static void _ShowMainMenuScreens(int OperationNumber)
	{
		_enMainMenuOperations MainMenuOperation = _enMainMenuOperations(OperationNumber);

		switch (MainMenuOperation)
		{
		case _BooksShop:
			clsBooksShopScreens::ShowBooksShopScreens();
			MainMenuScreen();
			break;
		case _AccessoriesShop:
			clsAccessoriesShopScreens::ShowAccessoriesShopScreen();
			MainMenuScreen();
			break;
		case _LoginAndSignUp:
			clsLoginScreen::LoginScreen();
			MainMenuScreen();
			break;
		case _ChangeTheme:
			if (Theme == Black)
				Theme = Grey;
			else
				Theme = Black;
			MainMenuScreen();
			break;
		case _Cart:
			clsCartScreen::ShowCartScreen();
			MainMenuScreen();
			break;
		}
	}

public:
	static void MainMenuScreen()
	{
		Header("Main Menu", true, true, true);
		cout << "\n\nPlease choose any operation:\n\n";
		_ShowMainMenuScreens(clsInputOutput::ReadNumberInRange(1, 5, "[1]Books Shop  [2]Accessories Shop  [3]Login/Sign Up  [4]Change Theme  [5]Cart\n"));
	}
};