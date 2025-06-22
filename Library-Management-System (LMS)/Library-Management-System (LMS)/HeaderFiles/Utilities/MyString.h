#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsMyString
{
public:
	static vector <string> Split(string S1, string Delim = "#//#")
	{
		vector <string> vString;
		short Pos = 0;
		string Word;

		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Word = S1.substr(0, Pos);

			if (Word != "")
				vString.push_back(Word);

			S1.erase(0, Pos + Delim.length());
		}

		if (S1 != "")
			vString.push_back(S1);

		return vString;
	}

	static bool IsCharFound(string Text,char SearchFor)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] == SearchFor)
				return true;
		}
		return false;
	}

};