#pragma once
#include <iostream>
#include <Windows.h>

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

class Controls
{
public:
	virtual bool createControl(int x, int y, int height, int width) = 0;
	char* getControlName();
	int getControlNumber();
	HWND* getAssignedWindow();
	HINSTANCE* getAssignedHinstance();

	void setActive(bool active_state);
	bool getActive();
private:
protected:
	char* m_control_name;
	int  assigned_control_number;
	HWND parentWindow;
	HWND assignedWindow;
	HINSTANCE* currentProgramInstance;
	bool created_control;
	bool active_control;
	wchar_t* control_name; //friendly for unicode
};