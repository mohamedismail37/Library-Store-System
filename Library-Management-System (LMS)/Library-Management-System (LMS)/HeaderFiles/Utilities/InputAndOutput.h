#pragma once
#include <iostream>
#include <string>
#include "MyString.h"
#include "Book.h"
using namespace std;

class clsInputOutput
{
public:
	static int ReadNumberInRange(int From, int To, string Text = "")
	{
		cout << Text;
		int Number = 0;
		while (!(cin >> Number))
		{
			cout << "Invalid Input!, Please enter a number : ";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		while (Number < From || Number > To)
		{
			cout << "Value must be between " << From << " and " << To;
			cout << "\nEnter the number : ";
			cin >> Number;
		}
		return Number;
	}

	static string ReadString(string Message = "")
	{
		string Text;
		cout << Message << endl;
		getline(cin >> ws, Text);
		return Text;
	}

	static int ReadInt(string Message = "")
	{
		int Number = 0;
		cout << Message << endl;
		cin >> Number;
		return Number;
	}

	static bool ReadGender(string Message)
	{
		cout << Message << endl;
		char Gender;
		do
		{
			cin >> Gender;
			if (Gender == 'm' || Gender == 'M')
				return 1;
			if (Gender == 'f' || Gender == 'F')
				return 0;
		} while (Gender != 'm' || Gender != 'M' || Gender != 'f' || Gender != 'F');

	}

	static bool IsValidEmail(string Text)
	{

		if (Text[Text.size() - 1] == 'm' && Text[Text.size() - 2] == 'o' &&
			Text[Text.size() - 3] == 'c' && Text[Text.size() - 4] == '.')
		{
			return true;
		}
		else
			return false;
	}

	static string ReadEmail(string Message)
	{
		cout << Message << endl;
		string Email;
		cin >> Email;
		while (!clsMyString::IsCharFound(Email, '@') || !IsValidEmail(Email))
		{
			cout << "Wrong Email!, Please enter it again : ";
			cin >> Email;
		}
		return Email;
	}

	static string ReadBookID()
	{
		string ID;
		cout << "\nPlease enter book ID : ";
		cin >> ID;

		while (!clsBooks::IsBookFound(ID))
		{
			cout << "\nInvalid Book ID! Please enter it again: ";
			cin >> ID;
		}
		return ID;
	}

};