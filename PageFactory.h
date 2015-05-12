#pragma once
#include <iostream>
#include "LandingMenu.h"

class PageFactory
{
	public: 
		static DefaultWindowClass* createPage(char* page_name, HINSTANCE* projectInstance);
};