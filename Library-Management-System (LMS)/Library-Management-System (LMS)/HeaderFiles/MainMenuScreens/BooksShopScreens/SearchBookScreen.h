#pragma once
#include <iostream>
#include "Screen.h"
#include "InputAndOutput.h"
#include "GlobalVariables.h"
#include "ListBooksScreen.h"
using namespace std;

class clsSearchBookScreen : public clsScreen
{
private:
	static void _OpenBookByID()
	{
		string ID = clsInputOutput::ReadBookID();
		clsListBooksScreen::PrintBookCard(clsBooks::FindBookByID(ID));
	}

	static void _PrintBooksUnderPrice(double Price)
	{
		vector <clsBooks> vSelectedBooks = clsBooks::BooksUnderPrice(30);
		clsListBooksScreen::ShowBooksList(vSelectedBooks);
	}

	static void _PrintBooksUpPrice(double Price)
	{
		vector <clsBooks> vSelectedBooks = clsBooks::BooksUpPrice(30);
		clsListBooksScreen::ShowBooksList(vSelectedBooks);
	}

	static void _SearchByFiltersScreen()
	{
		Header("Search (Filters)", 0, 0);
		cout << "\nSearch by Cost:\n";
		cout << "[1] Price < 30\t\t\t\t[2] Price > 30\n";
		int Choice = clsInputOutput::ReadNumberInRange(1, 2, "\nChoice: ");
		(Choice == 1) ? _PrintBooksUnderPrice(30) : _PrintBooksUpPrice(30);

	}

	static void _PrintBooksByCategory()
	{
		vector <clsBooks> vSameBooksCategory = clsBooks::SameBookCategory(LastBookOpenedCategory);
		clsListBooksScreen::ShowBooksList(vSameBooksCategory);
	}

public:
	static void SearchForBookScreen()
	{
		Header("Search for a Book", 0, 0);
		cout << "\n\t\t\t\tSearch by:\n";
		cout << "[1]ID\t\t\t[2]Suggested Books\t\t\t[3] By Filters\n";
		int Number = clsInputOutput::ReadNumberInRange(1, 3, "\nChoose Operation: ");

		switch (Number)
		{
		case 1:
			_OpenBookByID();
			break;
		case 2:
			_PrintBooksByCategory();
			break;
		case 3:
			_SearchByFiltersScreen();
			break;
		}
	}

};