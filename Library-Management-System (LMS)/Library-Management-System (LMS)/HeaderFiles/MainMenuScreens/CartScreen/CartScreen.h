#pragma once
#include <iostream>
#include "Screen.h"
#include "GlobalVariables.h"
#include "ListBooksScreen.h"
#include "ListAccessoriesScreen.h"
#include "InputAndOutput.h"

using namespace std;

class clsCartScreen : public clsScreen
{
private:
	static void _CartList()
	{
		cout << "\n>>>>>>>>>>>>>Books Cart<<<<<<<<<<<<<<<<<<<\n";
		for (short i = 0; i < CurrentCart.BoughtBooks.size(); i++)
		{
			cout << "(" << i+1 << ") " << CurrentCart.BoughtBooks[i].GetName() << endl;
		}

		cout << "\n\n>>>>>>>>>>Accessories Cart<<<<<<<<<<<<<<<\n";
		for (short i = 0; i < CurrentCart.BoughtAccessories.size(); i++)
		{
			cout << "(" << i + 1 << ") " << CurrentCart.BoughtAccessories[i].GetName() << endl;
		}
	}

	static void _RemoveBookFromTheCart(int Index)
	{
		Index--;
		vector <clsBooks> BooksNewV;
		for (short i = 0; i < CurrentCart.BoughtBooks.size(); i++)
		{
			if (i == Index)
				break;
			BooksNewV.push_back(CurrentCart.BoughtBooks[i]);
		}
		CurrentCart.BoughtBooks = BooksNewV;
	}

	static void _RemoveAccessoryFromTheCart(int Index)
	{
		Index--;
		vector <clsAccessories> AccessoriesNewV;
		for (short i = 0; i < CurrentCart.BoughtAccessories.size(); i++)
		{
			if (i == Index)
				break;
			AccessoriesNewV.push_back(CurrentCart.BoughtAccessories[i]);
		}
		CurrentCart.BoughtAccessories = AccessoriesNewV;
	}

	static void _DeleteItem()
	{
		int Number = clsInputOutput::ReadNumberInRange(1, 2, "\n[1] Delete Book\n[2] Delete Accessory\n");
		switch (Number)
		{
		case 1:
			_RemoveBookFromTheCart(clsInputOutput::ReadNumberInRange(1, CurrentCart.BoughtBooks.size(), "\nEnter book Index: "));
			break;
		case 2:
			_RemoveAccessoryFromTheCart(clsInputOutput::ReadNumberInRange(1, CurrentCart.BoughtAccessories.size(), "\nEnter Accessory Index: "));
			break;
		}

	}

	static void _Checkout()
	{
		Header("Checkout");
		double Balance = 0;
		for (short i = 0; i < CurrentCart.BoughtBooks.size(); i++)
		{
			Balance += CurrentCart.BoughtBooks[i].GetPrice();
		}
		for (short i = 0; i < CurrentCart.BoughtAccessories.size(); i++)
		{
			Balance += CurrentCart.BoughtAccessories[i].GetPrice();
		}
		cout << "\nTotal Balances = " << Balance << " USD";
		char InEGP;
		cout << "\nDo you Convert Price to EGP? (Y/N)\n";
		cin >> InEGP;
		if (InEGP == 'y' || InEGP == 'Y')
		{
			cout << "\nTotal Balances = " << Balance * 50 << " EGP";
		}

		char Pay;
		cout << "\nDo you to Checkout? (Y/N)\n";
		cin >> Pay;
		if (Pay == 'y' || Pay == 'Y')
		{
			for (short i = 0; i < CurrentCart.BoughtBooks.size(); i++)
			{
				clsBooks DecreaseQuantityOfBook = clsBooks::FindBookByID(CurrentCart.BoughtBooks[i].GetID());
				DecreaseQuantityOfBook.SetQuantity(DecreaseQuantityOfBook.GetQuantity() - 1);
			}
			for (short i = 0; i < CurrentCart.BoughtAccessories.size(); i++)
			{
				clsAccessories DecreaseQuantityOfAccessory = clsAccessories::FindAccessoryByID(CurrentCart.BoughtAccessories[i].GetID());
				DecreaseQuantityOfAccessory.SetQuantity(DecreaseQuantityOfAccessory.GetQuantity() - 1);
			}

			CurrentCart.BoughtBooks.clear();
			CurrentCart.BoughtBooks.clear();

			TotalBalance += Balance;

			cout << "\nPayment Done Successfully\n";
			cout << "\nPress any key to go back to main menu...\n";
			system("pause>0");
		}
	}

public:
	static void ShowCartScreen()
	{
		if (CurrentUser == eUnsigned)
		{
			Header("Cart Screen");
			cout << "\nPlease Login/Sign up to access to this page\n";
			cout << "\nPress any key to back to the Main Menu...";
			system("pause>0");
		}
		else if (CurrentUser == eClient)
		{
			Header("Cart Screen");
			if (CurrentCart.BoughtBooks.size() == 0 && CurrentCart.BoughtBooks.size() == 0)
			{
				cout << "\nCart is Empty\n";
				cout << "\nPress any key to go back to main menu...\n";
				system("pause>0");
			}
			else
			{
				_CartList();
				cout << "\n-------------------------\n";
				switch (clsInputOutput::ReadNumberInRange(1, 2, "\n(1) Delete Item\t\t(2) Checkout\n"))
				{
				case 1:
					_DeleteItem();
					ShowCartScreen();
					break;
				case 2:
					_Checkout();
					break;

				}
			}
		}
	}
};