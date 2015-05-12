/*
#include "createGui.h"

createGui::createGui()
{

}

createGui::createGui(HINSTANCE* hInst, HWND* hWnd)
{

	HWND hwndButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"OK",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		*hWnd,     // Parent window
		NULL,       // No menu.
		(HINSTANCE)GetWindowLong(*hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.

	int xpos = 100;            // Horizontal position of the window.
	int ypos = 100;            // Vertical position of the window.
	int nwidth = 200;          // Width of the window
	int nheight = 200;         // Height of the window
	HWND hwndParent = *hWnd; // Handle to the parent window

	HWND hWndComboBox = CreateWindow(WC_COMBOBOX, TEXT(""),
		CBS_DROPDOWN | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		xpos, ypos, nwidth, nheight, hwndParent, NULL, *hInst,
		NULL);

	const int numOfPlanets = 10;
	TCHAR Planets[numOfPlanets][numOfPlanets] =
	{
		TEXT("Mercury"), TEXT("Venus"), TEXT("Terra"), TEXT("Mars"),
		TEXT("Jupiter"), TEXT("Saturn"), TEXT("Uranus"), TEXT("Neptune"),
		TEXT("Pluto??"), TEXT("chrisland")
	};

	TCHAR A[16];
	int  k = 0;
	std::string hello = "hello";
	memset(&A, 0, sizeof(A));
	for (k = 0; k < numOfPlanets; k++)
	{
		wcscpy_s(A, sizeof(A) / sizeof(TCHAR), (TCHAR*)Planets[k]);

		// Add string to combobox.
		SendMessage(hWndComboBox, (UINT)CB_ADDSTRING, (WPARAM)0, (LPARAM)A);
	}

	// Send the CB_SETCURSEL message to display an initial item 
	//  in the selection field  
	SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);
}*///
#include "stdafx.h"