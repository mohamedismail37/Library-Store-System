#pragma once
#include <iostream>
#include <vector>
#include "Screen.h"
#include "Accessories.h"
#include "InputAndOutput.h"
#include "GlobalVariables.h"
using namespace std;

class clsListAccessoiresScreen : public clsScreen
{
private:

	static void _BuyAccessory(clsAccessories Accessories)
	{
		CurrentCart.BoughtAccessories.push_back(Accessories);
		cout << "\nAccessory Added to Cart Successfully\n";
		cout << "Press any key to go back to main menu...";
		system("pause>0");
	}

public:
	static void PrintAccessoryCard(clsAccessories Accessory)
	{
		clsScreen::Header(Accessory.GetName(), 0, 0);
		clsAccessories::PrintAccessoryInfo(Accessory);
		int Number = clsInputOutput::ReadNumberInRange(1, 2, "\n\t\t{1} Buy the Accessory\t\t\t{2} Back to main menu\n");
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
				_BuyAccessory(Accessory);
		}

	}

	static void ShowAccessorriesList(vector <clsAccessories> vAccessories = clsAccessories::GetAccessoriesList())
	{
		clsScreen::Header("Accessories List", false, false);

		if (vAccessories.size() == 0)
		{
			cout << "\t\t\t(Number Of Accessories = 0)";
			cout << "\nPress any key to continue...";
			system("pause>0");
		}

		else
		{
			cout << "\n|  Name  -  Quantity  -  ID  -  Price  |\n";
			cout << "------------------------------------------\n";
			for (int i = 0; i < vAccessories.size(); i++)
			{
				cout << "[" << i + 1 << "] " << vAccessories[i].GetName() << " - " << vAccessories[i].GetQuantity() << " - " << vAccessories[i].GetID() <<
					" - " << vAccessories[i].GetPrice()  << endl << endl;
			}
			cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
			int Number = clsInputOutput::ReadNumberInRange(1, vAccessories.size(), "Choose an Accessory : ");
			PrintAccessoryCard(vAccessories[Number - 1]);
		}

	}
};