/*
Author: Christopher Humm

Class: WindowDisplayClass
Class Description: This class should complete all the Windows 32 API prerequesites for starting a software program.
This is a base class which all Window objects inherit from. This allows easy creation of windows.

Date Created: 22/02/2015
Date Last Modified: 22/02/2015
Last Modified By: Christopher Humm
*/
#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <wtypes.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdarg.h>
#include <tchar.h>
#include <atlconv.h>
class WindowDisplayClass
{
	public:
		WindowDisplayClass(HINSTANCE* currentInstance, const char* name);
		const char* getName();
		HINSTANCE* getCurrentInstance();
		HWND getCurrentWindow();
	protected:
		HINSTANCE* m_currentInstance;
		const char* m_name;
};