#pragma once
#include <iostream>
#include "Product.h"
#include <fstream>
#include <vector>
#include <string>
#include "Screen.h"
#include "MyString.h"
using namespace std;

class clsBooks : public clsProduct
{
private:
	string _Author;
	string _Category;
	int _Version;
	int _PublishDate;
	int _PagesNumber;

	static clsBooks _ConvertLineToBookObject(string Line, string Separtor = "#//#")
	{
		vector <string> vBooksData;
		vBooksData = clsMyString::Split(Line);

		enum _enNames
		{
			eName = 0, eQuantity = 1, eID = 2, ePrice = 3,
			eAuthor = 4, eCategory = 5, eVersion = 6, ePublishDate = 7
			, ePagesNumber = 8
		};

		return clsBooks(vBooksData[eName], stoi(vBooksData[eQuantity]), vBooksData[eID], stod(vBooksData[ePrice]),
			vBooksData[eAuthor], vBooksData[eCategory], stoi(vBooksData[eVersion]),stoi(vBooksData[ePublishDate]), stoi(vBooksData[ePagesNumber]));
	}

	static vector <clsBooks> _LoadBooksDataFromFile()
	{
		vector <clsBooks> vBooks;

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBooks Book = _ConvertLineToBookObject(Line);

				vBooks.push_back(Book);
			}
			MyFile.close();
		}
		return vBooks;
	}

	static string _ConvertBookObjectToLine(clsBooks Book, string Separator = "#//#")
	{
		string BookRecordLine = "";
		BookRecordLine += Book.GetName() + Separator;
		BookRecordLine += to_string(Book.GetQuantity()) + Separator;
		BookRecordLine += Book.GetID() + Separator;
		BookRecordLine += to_string(Book.GetPrice()) + Separator;
		BookRecordLine += Book._Author + Separator;
		BookRecordLine += Book._Category + Separator;
		BookRecordLine += to_string(Book._Version) + Separator;
		BookRecordLine += to_string(Book._PublishDate) + Separator;
		BookRecordLine += to_string(Book._PagesNumber) + Separator;

		return BookRecordLine;
	}

	static void _SaveBooksDataToFile(vector <clsBooks> vBooks)
	{
		fstream MyFile;
		MyFile.open("Books.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBooks B : vBooks)
			{
				DataLine = _ConvertBookObjectToLine(B);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

public:

	clsBooks(string Name, int Quantity, string ID, double Price, string Author, string Category, int Version,
		int PublishDate, int PagesNumber) : clsProduct(Name, Quantity, ID, Price)
	{
		_Author = Author;
		_Category = Category;
		_Version = Version;
		_PublishDate = PublishDate;
		_PagesNumber = PagesNumber;
	}

	string GetAuthor()
	{
		return _Author;
	}

	string GetCategory()
	{
		return _Category;
	}

	int GetVersion()
	{
		return _Version;
	}

	int GetPublishDate()
	{
		return _PublishDate;
	}

	int GetPagesNumber()
	{
		return _PagesNumber;
	}

	static vector <clsBooks> GetBooksList()
	{
		return _LoadBooksDataFromFile();
	}

	static void PrintBookInfo(clsBooks Book)
	{
		cout << "Quantity = " << Book.GetQuantity() << "\t\t\t";
		cout << "ID = " << Book.GetID() << "\t\t\t";
		cout << "Price = " << Book.GetPrice() << endl << endl;
		cout << "Author = " << Book.GetAuthor() << "\t\t\t";
		cout << "Category = " << Book.GetCategory() << endl << endl;
		cout << "Version = " << Book.GetVersion() << "\t\t";
		cout << "Publish Date = " << Book.GetPublishDate() << "\t\t";
		cout << "Pages Number = " << Book.GetPagesNumber() << endl << endl;
		cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
	}

	static void PrintBookInfo(string ID)
	{
		PrintBookInfo(FindBookByID(ID));
	}

	static bool IsBookFound(string ID)
	{
		vector <clsBooks> vBooks;

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBooks Book = _ConvertLineToBookObject(Line);
				if (Book.GetID() == ID)
				{
					MyFile.close();
					return true;
				}
				vBooks.push_back(Book);
			}
			MyFile.close();
			return false;
		}
	}

	static clsBooks FindBookByID(string ID)
	{
		vector <clsBooks> vBooks;

		fstream MyFile;
		MyFile.open("Books.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBooks Book = _ConvertLineToBookObject(Line);
				if (Book.GetID() == ID)
				{
					MyFile.close();
					return Book;
				}
				vBooks.push_back(Book);
			}
			MyFile.close();

		}
	}

	static vector <clsBooks> BooksUnderPrice(double Price)
	{
		vector <clsBooks> vBooks = _LoadBooksDataFromFile();
		vector <clsBooks> vSelectedBooks;
		for (short i = 0; i < vBooks.size(); i++)
		{
			if (vBooks[i].GetPrice() < Price)
				vSelectedBooks.push_back(vBooks[i]);
		}
		return vSelectedBooks;
	}

	static vector <clsBooks> BooksUpPrice(double Price)
	{
		vector <clsBooks> vBooks = _LoadBooksDataFromFile();
		vector <clsBooks> vSelectedBooks;
		for (short i = 0; i < vBooks.size(); i++)
		{
			if (vBooks[i].GetPrice() > Price)
				vSelectedBooks.push_back(vBooks[i]);
		}
		return vSelectedBooks;
	}

	static vector <clsBooks> SameBookCategory(string Category)
	{
		vector <clsBooks> vBooks = _LoadBooksDataFromFile();
		vector <clsBooks> vSelectedBooks;
		for (short i = 0; i < vBooks.size(); i++)
		{
			if (vBooks[i].GetCategory() == Category)
				vSelectedBooks.push_back(vBooks[i]);
		}
		return vSelectedBooks;
	}
};