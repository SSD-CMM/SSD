#include "WindowDisplayClass.h"
WindowDisplayClass::WindowDisplayClass(HINSTANCE* currentInstance, const char* name) : m_currentInstance(currentInstance), m_name(name)
{
	//Default Created Constructor for all child classes to inherit from
}
HWND WindowDisplayClass::getCurrentWindow()
{
	try
	{
		HWND hWnd = ::GetActiveWindow();
		hWnd = FindWindowA(0, getName());
		hWnd = FindWindowA(getName(),0);
		if (IsWindow(hWnd) == true)
		{
			return hWnd;
		}
		else
		{
			throw hWnd;
		}
	}
	catch (HWND hWnd)
	{
		//Create Default window and return;
	}
	catch (...)
	{
		//Log Error;
	}
}

const char* WindowDisplayClass::getName()
{
	return m_name;
}