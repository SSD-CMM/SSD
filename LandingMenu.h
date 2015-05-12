/*
Author: Christopher Humm

Class: Comedian Booking Menu
Class Description: Child class of Default. This class displays the default main window for the rest of the program.
It could be used as a base class for further child classes. WnDProc still needs to be implemented a member method.

Date Created: 22/02/2015
Date Last Modified: 22/02/2015
Last Modified By: Christopher Humm
*/
#pragma once
#include "DefaultWindowClass.h"
#include <iostream>

#define IDD_CONTROLSDLG 101
#define IDD_SIZE_CBO    102
#define MAX_LOADSTRING 100

#define IDC_COMEDIAN_BOOK 201 
#define IDC_CUSTOMER_BOOK 202 
#define IDC_EVENT_VIEW 203 
#define IDC_COMEDIAN_BOOK_TEXT_1 204
#define IDC_COMEDIAN_BOOK_TEXT_2 205 
#define IDC_COMEDIAN_BOOK_TEXT_3 206
#define IDC_COMEDIAN_BOOK_NOW    207
#define IDC_COMEDIAN_SAVE 208

class LandingMenu : public DefaultWindowClass
{
public:
	LandingMenu(HINSTANCE* currentInstance, const char* name, WNDPROC window);
	LRESULT CALLBACK WndProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	HWND hwndButton;
	HWND hwndButton2;
	HWND hwndButton3;

	HWND comedianNameField;
	HWND contactField;
	HWND dateField;

	HWND name;
	HWND contact;
	HWND date;
	HWND eventdetail;

	HWND   lblObj;
	HWND hWndComboBox;
	HWND hWnd, hWnd2;
	HWND confirmComedian, confirmCustomer;

	LPWSTR comedianName = NULL;

	TCHAR comedianNameTCHAR[2000];
	TCHAR contactTCHAR[30];
	TCHAR dateTCHAR[30];
	TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

	BOOL createComedianBooking(HWND hWnd);
	void saveBookedComedian(TCHAR* eventDetails, int size);
	void createInitialWindow(HWND hWnd);
	bool first_run;
protected:
};