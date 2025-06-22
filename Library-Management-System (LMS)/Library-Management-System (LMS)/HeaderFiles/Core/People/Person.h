#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsPerson
{

protected:
	enum _enPermission {_UnSigned = 0, _Admin = 1, _Staff = 2, _Client = 3 };

	string _Name;
	string _Password;
	_enPermission _Permission;
	bool _Gender;

public:

	clsPerson(string Name, string Password, _enPermission Permission, bool Gender)
	{
		_Name = Name;
		_Password = Password;
		_Permission = Permission;
		_Gender = Gender;
	}

	void SetName(string Name)
	{
		_Name = Name;
	}
	string GetName()
	{
		return _Name;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}

	void SetPermission(int Permission)
	{
		_Permission = _enPermission(Permission);
	}
	int GetPermission()
	{
		return _Permission;
	}

	void SetGender(bool Gender)
	{
		_Gender = Gender;
	}
	bool GetGender()
	{
		return _Gender;
	}

};