#pragma once
#include <iostream>
#include <vector>
#include "Screen.h"
#include "Book.h"
#include "InputAndOutput.h"
#include "GlobalVariables.h"
using namespace std;

class clsListBooksScreen : public clsScreen
{
private:

	static void _BuyBook(clsBooks Book)
	{
		CurrentCart.BoughtBooks.push_back(Book);
		cout << "\nBook Added to Cart Successfully\n";
		cout << "Press any key to go back to main menu...";
		system("pause>0");
	}

public:
	static void PrintBookCard(clsBooks Book)
	{
		clsScreen::Header(Book.GetName(), 0, 0);
		clsBooks::PrintBookInfo(Book);
		LastBookOpenedCategory = Book.GetCategory();
		int Number = clsInputOutput::ReadNumberInRange(1, 2, "\n{1} Buy the book\t\t\t{2} Back to main menu\n");
		if (CurrentUser == enCurrentUser::eUnsigned && Number == 1)
		{
			cout << "\nSorry, you should Login or Sign up\n";
			cout << "\nPress any key to go back to main menu...";
			system("pause>0");
			return;
		}
		else if (CurrentUser == enCurrentUser::eClient)
		{
			if (Number == 1)
				_BuyBook(Book);
		}

	}

	static void ShowBooksList(vector <clsBooks> vBooks = clsBooks::GetBooksList())
	{
		clsScreen::Header("Books List", false, false);

		if (vBooks.size() == 0)
		{
			cout << "\t\t\t(Number Of Books = 0)";
			cout << "\nPress any key to continue...";
			system("pause>0");
		}

		else
		{
			cout << "\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~The Books~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n\n";
			cout << "|Name - Quantity - ID - Price - Author - Category - Version - Publish Date - Pages Number  |\n";
			cout << "--------------------------------------------------------------------------------------------\n";
			for (int i = 0; i < vBooks.size(); i++)
			{
				cout << "[" << i + 1 << "] " << vBooks[i].GetName() << " - " << vBooks[i].GetQuantity() << " - " << vBooks[i].GetID() <<
					" - " << vBooks[i].GetPrice() << " - " << vBooks[i].GetAuthor() << " - " << vBooks[i].GetCategory() << " - " << vBooks[i].GetVersion()
					<< " - " << vBooks[i].GetPublishDate() << " - " << vBooks[i].GetPagesNumber() << endl << endl;
			}
			cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
			int Number = clsInputOutput::ReadNumberInRange(1, vBooks.size(), "Choose a Book : ");
			PrintBookCard(vBooks[Number-1]);
		}

	}
};