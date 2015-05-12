/*
Author: Christopher Humm

Class: DefaultWindowClass
Class Description: Child class of WindowDisplayClass. This class displays the default main window for the rest of the program.
It could be used as a base class for further child classes. WnDProc still needs to be implemented a member method.

Date Created: 22/02/2015
Date Last Modified: 22/02/2015
Last Modified By: Christopher Humm
*/
#pragma once
#include "WindowDisplayClass.h"

class DefaultWindowClass : public WindowDisplayClass
{
	public:
		DefaultWindowClass(HINSTANCE* currentInstance, const char* name, WNDPROC window);
		ATOM registerClass();
		ATOM registerClass(WNDCLASSEXA*);
		void createDefaultClass(char* class_name);
		void createDefaultWindow(void* windowToCreate);
		virtual LRESULT CALLBACK WndProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	protected:
		WNDCLASSEXA m_currentClass;
		HWND m_currentWindow;
		static LRESULT CALLBACK createChildWndProcedure(HWND, UINT, WPARAM, LPARAM);
};