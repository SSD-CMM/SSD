#include "Controls.h"

HWND* Controls::getAssignedWindow()
{
	return &assignedWindow;
}

HINSTANCE* Controls::getAssignedHinstance()
{
	return currentProgramInstance;
}

char* Controls::getControlName()
{
	return m_control_name;
}
int Controls::getControlNumber()
{
	return assigned_control_number;
}

void Controls::setActive(bool active_state)
{
	active_control = active_state;
}
bool Controls::getActive()
{
	return active_control;
}