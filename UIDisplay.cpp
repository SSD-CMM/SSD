// comedy club prototype UI
//dev: Chris Humm, Matt Cull, Matt Slocombe

#include "stdafx.h"
#include "UIDisplay.h"
// Windows Header Files:
#include <windows.h>
#include <CommCtrl.h>
#include <iostream>
#include <string>
#include "DefaultWindowClass.h"
#include "LandingMenu.h"
// C RunTime Header Files
#include <math.h>
#include "PageFactory.h"
#include <objbase.h>

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
BOOL				InitInstance(WindowDisplayClass*, int nCmdShow);

INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
/////////////////////////////////////////////////////////


////////////////////////////////////////////////////
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);

	DefaultWindowClass* newClass = PageFactory::createPage("Landing Page", &hInstance);

	if (!InitInstance(newClass, nCmdShow))
	{
		return FALSE;
	}
	//Shortcuts such as CTRL + 
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}
BOOL InitInstance(WindowDisplayClass* newClass, int nCmdShow)
{
	HWND newWindow = newClass->getCurrentWindow();

	ShowWindow(newWindow, nCmdShow);
	UpdateWindow(newWindow);

   return TRUE;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}