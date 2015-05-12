#include "Win32Startup.h"


Win32Startup::Win32Startup()
{

}
/*
~Win32Startup::Win32Startup()
{

}*/

Win32Startup::Win32Startup(HINSTANCE* current, HINSTANCE* previous, LPTSTR* parameters, int* commandLine)
{
	m_currentWindow = current;
	m_previousWindow = previous;
	m_passedParameters = parameters;
	m_showCmd = commandLine;
}

bool Win32Startup::createWindowInstance(TCHAR* title)
{
	LoadString(*m_currentWindow, IDS_APP_TITLE, title, s_titleSize);
	//createWindowClass(*m_currentWindow,title);
	/*// Initialize global strings
	LoadString(*m_currentWindow, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(*m_currentWindow, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(*m_currentWindow);

	// Perform application initialization:
	if (!InitInstance(*m_currentWindow, *m_showCmd))
	{
		return FALSE;
	}*/

	return true;
}

ATOM Win32Startup::createWindowClass(HINSTANCE* m_currentWindow, TCHAR* windowTitle)
{
	/*
	LoadString(*m_currentWindow, IDC_WIN32PROJECT1, windowTitle, s_titleSize);

	WNDCLASSEXA wcex;

	wcex.cbSize = sizeof(WNDCLASSEXA);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = *m_currentWindow;
	wcex.hIcon = LoadIcon(*m_currentWindow, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
	*/

	return NULL;
}