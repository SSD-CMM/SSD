#include "Button.h"

Button::Button()
{
	button_pressed = false;
	m_control_name = "Default Button";
	assigned_control_number = 0;
	assignedWindow = NULL;
	currentProgramInstance = NULL;
	created_control = false;
	active_control = false;
}
Button::Button(char* button_name, int control_msg, HWND* pageParentWindow)
{
	parentWindow = *pageParentWindow;
	button_pressed = false;
	m_control_name = button_name;
	assigned_control_number = control_msg;
	assignedWindow = NULL;
	currentProgramInstance = NULL;
	created_control = false;
	active_control = false;
}
Button::~Button()
{
	delete control_name;
	control_name = NULL;
}

bool Button::onClickAction()
{
	if (active_control == false)
		return false;

	if (button_pressed == true)
	{
		button_pressed = false;
		ShowWindow(assignedWindow, SW_HIDE);
		return true;
	}
	else if (button_pressed == false)
	{
		button_pressed = true;
		ShowWindow(assignedWindow, SW_HIDE);
		return true;
	}
	else
	{}

	return false;
}

bool Button::createControl(int x, int y, int width, int height)
{
	//convert to wchar from char* 
	control_name = new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, m_control_name, -1, control_name, 4096);

	try
	{
		assignedWindow = CreateWindow(
			L"BUTTON",  // Predefined class; Unicode assumed 
			control_name,      // Button text 
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
			x,         // x position 
			y,         // y position 
			width,        // Button width
			height,        // Button height
			parentWindow,     // Parent window
			(HMENU)assigned_control_number,
			(HINSTANCE)GetWindowLong(parentWindow, GWL_HINSTANCE),
			NULL);      // Pointer not needed.
	}
	catch (...)
	{
		return false;
	}
	created_control = true;
	active_control = true;

	return true;
}