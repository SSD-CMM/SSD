/*
Author: Christopher Humm

Class: Win32Startup
Class Description: This class should complete all the Windows 32 API prerequesites for starting a software program.
Once first inialisation is complete, the program can continue.

Date Created: 21/02/2015
Date Last Modified: 21/02/2015
Last Modified By: Christopher Humm
*/
#pragma once

#include <iostream>
#include <Windows.h>
#include "stdafx.h"
#include "Resource.h"

class Win32Startup
{
public:
	Win32Startup();
	//~Win32Startup();

	Win32Startup(HINSTANCE*, HINSTANCE*, LPTSTR*, int*);
	bool createWindowInstance(TCHAR* title);
	ATOM createWindowClass(HINSTANCE* hInstance, TCHAR* windowTitle);
private:
	HINSTANCE* m_currentWindow;
	HINSTANCE* m_previousWindow;
	LPTSTR*    m_passedParameters;
	int*	   m_showCmd;
	static const int s_titleSize = 25;
protected:
};