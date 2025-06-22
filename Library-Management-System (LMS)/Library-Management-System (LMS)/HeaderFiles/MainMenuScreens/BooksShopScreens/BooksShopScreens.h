#pragma once
#include <iostream>
#include "ListBooksScreen.h"
#include "Screen.h"
#include "InputAndOutput.h"
#include "SearchBookScreen.h"
using namespace std;

class clsBooksShopScreens : public clsScreen
{
private:
	enum _enScreenForward { List = 1, Search = 2 };

	static void _BooksShopChoiceForward(_enScreenForward Choice)
	{
		switch (Choice)
		{
		case clsBooksShopScreens::List:
			clsListBooksScreen::ShowBooksList();
			break;
		case clsBooksShopScreens::Search:
			clsSearchBookScreen::SearchForBookScreen();
			break;
		}
	}

public:
	static void ShowBooksShopScreens()
	{
		Header("Books Shop",0,0);
		cout << "\n[1] List all Books\t\t\t\t[2] Search for a specific book\n";
		_BooksShopChoiceForward(_enScreenForward(clsInputOutput::ReadNumberInRange(1, 2,"\nChoose Operation: ")));
	}
};