#pragma once
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

class clsDateAndTime
{
private:
	time_t t = time(0);

	tm* now = localtime(&t);

	string _DateLine = to_string(now->tm_year + 1900) + "/" + to_string(now->tm_mon + 1) +
		"/" + to_string(now->tm_mday);

	string _TimeLine;

public:

	string Date()
	{
		return _DateLine;
	}

	string Time()
	{
		string Hours, Minutes;
		if (now->tm_hour - 12 < 10)
		{
			if (now->tm_hour - 12 > 0)
				Hours = "(0" + to_string(now->tm_hour - 12) + ":";
			else
				Hours = "(0" + to_string(now->tm_hour) + ":";
		}
		else
			Hours = "(" + to_string(now->tm_hour - 12) + ":";

		if (now->tm_min < 10)
			Minutes = "0" + to_string(now->tm_min) + ")";
		else
			Minutes = to_string(now->tm_min) + ")";

		_TimeLine = Hours + Minutes;

		return _TimeLine;
	}

};