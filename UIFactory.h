#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Controls.h"
#include "Button.h"
using namespace std;

class UIFactory
{
public:
	static vector<Controls*> createPageControls(char* initial_page, HWND* parentWindow, HINSTANCE* currentInstance);
};