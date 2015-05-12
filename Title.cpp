#include "Title.h"

Title::Title()
{
	font_size = 32;
	m_control_name = "Default Button";
	assigned_control_number = 0;
	assignedWindow = NULL;
	currentProgramInstance = NULL;
	created_control = false;
	active_control = false;
}
Title::Title(char* title_name, int control_msg, HWND* pageParentWindow, int f_size)
{
	parentWindow = *pageParentWindow;
	m_control_name = title_name;
	assigned_control_number = control_msg;
	assignedWindow = NULL;
	currentProgramInstance = NULL;
	created_control = false;
	active_control = false;

	font_size = f_size;
}
Title::~Title()
{
	delete control_name;
	control_name = NULL;
}

bool Title::createControl(int x, int y, int width, int height)
{
	//convert to wchar from char* 
	control_name = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, m_control_name, -1, control_name, 4096);

	try
	{
		assignedWindow = CreateWindow(
			TEXT("static"),
			control_name,
			WS_VISIBLE | WS_CHILD,
			400,
			6,
			370,
			30,
			parentWindow,
			(HMENU)3,
			NULL,
			NULL);
		HFONT hFont = CreateFont(font_size, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
		SendMessage(assignedWindow, WM_SETFONT, WPARAM(hFont), TRUE);
	}
	catch (...)
	{
		return false;
	}
	created_control = true;
	active_control = true;

	return true;
}