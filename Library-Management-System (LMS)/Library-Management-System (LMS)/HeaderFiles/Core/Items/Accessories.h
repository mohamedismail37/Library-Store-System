#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "Product.h"
#include "MyString.h"
using namespace std;

class clsAccessories : public clsProduct
{
private:

	static clsAccessories _ConvertLineToAccessoriesObject(string Line, string Separtor = "#//#")
	{
		vector <string> vAccessoriesData;
		vAccessoriesData = clsMyString::Split(Line);

		enum _enNames
		{
			eName = 0, eQuantity = 1, eID = 2, ePrice = 3,
		};

		return clsAccessories(vAccessoriesData[eName], stoi(vAccessoriesData[eQuantity]), vAccessoriesData[eID], stod(vAccessoriesData[ePrice]));
	}

	static vector <clsAccessories> _LoadAccessoriesDataFromFile()
	{
		vector <clsAccessories> vAccessories;

		fstream MyFile;
		MyFile.open("Accessories.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsAccessories Accessory = _ConvertLineToAccessoriesObject(Line);

				vAccessories.push_back(Accessory);
			}
			MyFile.close();
		}
		return vAccessories;
	}

	static string _ConvertAccessoriesObjectToLine(clsAccessories Accessory, string Separator = "#//#")
	{
		string AccessoriesRecordLine = "";
		AccessoriesRecordLine += Accessory.GetName() + Separator;
		AccessoriesRecordLine += to_string(Accessory.GetQuantity()) + Separator;
		AccessoriesRecordLine += Accessory.GetID() + Separator;
		AccessoriesRecordLine += to_string(Accessory.GetPrice()) + Separator;

		return AccessoriesRecordLine;
	}

	static void _SaveAccessoreisDataToFile(vector <clsAccessories> vAccessories)
	{
		fstream MyFile;
		MyFile.open("Accessories.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsAccessories A : vAccessories)
			{
				DataLine = _ConvertAccessoriesObjectToLine(A);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

public:
	clsAccessories(string Name, int Quantity, string ID, double Price) : clsProduct(Name, Quantity, ID, Price)
	{	}

	static vector <clsAccessories> GetAccessoriesList()
	{
		return _LoadAccessoriesDataFromFile();
	}

	static void PrintAccessoryInfo(clsAccessories Accessory)
	{
		cout << "Quantity = " << Accessory.GetQuantity() << "\t\t\t";
		cout << "ID = " << Accessory.GetID() << "\t\t\t";
		cout << "Price = " << Accessory.GetPrice() << endl << endl;
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
	}

	static clsAccessories FindAccessoryByID(string ID)
	{
		vector <clsAccessories> vAccessories;

		fstream MyFile;
		MyFile.open("Accessories.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsAccessories Accessory = _ConvertLineToAccessoriesObject(Line);
				if (Accessory.GetID() == ID)
				{
					MyFile.close();
					return Accessory;
				}
				vAccessories.push_back(Accessory);
			}
			MyFile.close();

		}
	}


};