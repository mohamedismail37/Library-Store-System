#pragma once
#include <iostream>
#include <vector>
#include "Book.h"
#include "Accessories.h"
using namespace std;

enum enThemeColor
{
	Black = 0, Grey = 1
};
static bool Theme = Black;

enum enCurrentUser
{
	eUnsigned = 0,
	eAdmin = 1,
	eClient = 2
};
enCurrentUser CurrentUser = eUnsigned;

class clsCartInfo
{
public:
	vector <clsBooks> BoughtBooks;
	vector <clsAccessories> BoughtAccessories;
};
clsCartInfo CurrentCart;

string LastBookOpenedCategory = "";

double TotalBalance = 0;