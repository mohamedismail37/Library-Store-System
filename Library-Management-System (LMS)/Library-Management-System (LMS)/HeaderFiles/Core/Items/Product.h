#pragma once
#include <iostream>
using namespace std;

class clsProduct
{
private:
	string _Name;
	int _Quantity;
	string _ID;
	double _Price;

public:
	clsProduct(string Name, int Quantity, string ID, double Price)
	{
		_Name = Name;
		_Quantity = Quantity;
		_ID = ID;
		_Price = Price;
	}

	void SetName(string Name)
	{
		_Name = Name;
	}
	string GetName()
	{
		return _Name;
	}

	void SetQuantity(int Quantity)
	{
		_Quantity = Quantity;
	}
	int GetQuantity()
	{
		return _Quantity;
	}

	void SetID(string ID)
	{
		_ID = ID;
	}
	string GetID()
	{
		return _ID;
	}

	void SetPrice(double Price)
	{
		_Price = Price;
	}
	double GetPrice()
	{
		return _Price;
	}

};