#pragma once
#include "WelcomeScreen.h"
#include "MainMenuScreen.h"

class clsStart
{
public:
	static void Start()
	{
		clsWelcomeScreen::WelcomeScreen();
		clsMainMenuScreen::MainMenuScreen();
	}
};