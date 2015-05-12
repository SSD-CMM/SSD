#include "LandingMenu.h"

LandingMenu::LandingMenu(HINSTANCE* currentInstance, const char* name, WNDPROC window) : DefaultWindowClass(currentInstance, name, window)
{
	m_currentClass.lpfnWndProc = window;
	m_currentInstance = currentInstance;
	m_name = name;
	first_run = false;
}


static bool newWindow = false;
LRESULT CALLBACK LandingMenu::WndProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (first_run == false)
		createInitialWindow(hWnd);

	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		if (HIWORD(wParam) == CBN_SELCHANGE)
		{
			int ItemIndex = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
				(WPARAM)0, (LPARAM)0);
			TCHAR  ListItem[256];
			(TCHAR)SendMessage((HWND)lParam, (UINT)CB_GETLBTEXT,
				(WPARAM)ItemIndex, (LPARAM)ListItem);
			MessageBox(hWnd, (LPCWSTR)ListItem, TEXT("Item Selected"), MB_OK);
		}
		else if (HIWORD(wParam) == BN_CLICKED) //responds to button clicks
		{
			switch (LOWORD(wParam))
			{
			case IDC_COMEDIAN_BOOK:
			{
				std::cout << "t";
				createComedianBooking(hWnd);
			}
				break;
			case IDC_COMEDIAN_SAVE:
			{
				GetWindowText(comedianNameField, comedianNameTCHAR, INT_MAX);

				TCHAR space[3] = TEXT(",");
				_tcscat_s(comedianNameTCHAR, space);

				GetWindowText(contactField, contactTCHAR, INT_MAX);

				_tcscat_s(comedianNameTCHAR, contactTCHAR);

				GetWindowText(dateField, dateTCHAR, INT_MAX);

				_tcscat_s(comedianNameTCHAR, space);

				_tcscat_s(comedianNameTCHAR, dateTCHAR);

				TCHAR newLine[10] = TEXT("\r\n");
				_tcscat_s(comedianNameTCHAR, newLine);

				saveBookedComedian(comedianNameTCHAR, sizeof(comedianNameTCHAR));


				std::cout << "saved";
				MessageBox(NULL, TEXT("Comedian Booked"), TEXT("Chris Humm"), MB_OK);
			}
				break;
			case IDC_CUSTOMER_BOOK:
			{
				MessageBox(NULL, TEXT("Show Customer Bookings"), TEXT("Chris Humm"), MB_OK);
				std::cout << "s";
			}
				break;
			case IDC_EVENT_VIEW:
			{
				MessageBox(NULL, TEXT("Show Event Info"), TEXT("Chris Humm"), MB_OK);
				std::cout << "f";

				newWindow = true;
			}
				break;
			case IDC_COMEDIAN_BOOK_NOW:
			{
				MessageBox(NULL, TEXT("Comedian Booked"), TEXT("Chris Humm"), MB_OK);
			}
				break;
			}
		}
		switch (wmId)
		{
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

BOOL LandingMenu::createComedianBooking(HWND hWnd)
{
	name = CreateWindow(
		TEXT("static"),
		TEXT("Name"),
		WS_VISIBLE | WS_CHILD,
		300,
		470,
		370,
		30,
		hWnd,
		(HMENU)3,
		NULL,
		NULL);
	HFONT hFont = CreateFont(12, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
	SendMessage(name, WM_SETFONT, WPARAM(hFont), TRUE);

	comedianNameField = CreateWindow(L"EDIT",
		L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN,
		350,
		470,
		300,
		25,
		hWnd,
		(HMENU)IDC_COMEDIAN_BOOK_TEXT_1,
		*m_currentInstance,
		0);

	//	GetWindowText(MyTextField2, comedianNameTCHAR, 500);

	contact = CreateWindow(
		TEXT("static"),
		TEXT("Contact Details"),
		WS_VISIBLE | WS_CHILD,
		250,
		500,
		420,
		30,
		hWnd,
		(HMENU)3,
		NULL,
		NULL);
	HFONT hFont2 = CreateFont(12, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
	SendMessage(contact, WM_SETFONT, WPARAM(hFont), TRUE);

	contactField = CreateWindow(L"EDIT",
		L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN,
		350,
		500,
		300,
		25,
		hWnd,
		(HMENU)IDC_COMEDIAN_BOOK_TEXT_1,
		*m_currentInstance,
		0);

	date = CreateWindow(
		TEXT("static"),
		TEXT("Date"),
		WS_VISIBLE | WS_CHILD,
		300,
		530,
		370,
		30,
		hWnd,
		(HMENU)3,
		NULL,
		NULL);
	HFONT hFont3 = CreateFont(12, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
	SendMessage(date, WM_SETFONT, WPARAM(hFont), TRUE);

	dateField = CreateWindow(L"EDIT",
		L"",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN,
		350,
		530,
		300,
		25,
		hWnd,
		(HMENU)IDC_COMEDIAN_BOOK_TEXT_1,
		*m_currentInstance,
		0);

	date = CreateWindow(
		TEXT("static"),
		TEXT("Event"),
		WS_VISIBLE | WS_CHILD,
		325,
		425,
		370,
		30,
		hWnd,
		(HMENU)3,
		NULL,
		NULL);
	HFONT hFont4 = CreateFont(12, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
	SendMessage(date, WM_SETFONT, WPARAM(hFont), TRUE);

	hWndComboBox = CreateWindow(WC_COMBOBOX,
		TEXT(""),
		CBS_DROPDOWNLIST | CBS_HASSTRINGS | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE,
		350,
		425,
		300,
		300,
		hWnd,
		NULL,
		*m_currentInstance,
		NULL);
	const int numOfEvents = 4;
	const int eventNameLimit = 25;

	std::string filename1 = "mylogfile.txt";
	std::ifstream fileee(filename1.c_str(), std::ios::binary);
	std::stringstream sss;
	sss << fileee.rdbuf() << "\0";
	std::wstring test = std::wstring((wchar_t*)sss.str().c_str());
	TCHAR* testStringTCHAR = TEXT("");

	std::wstring bufferString[100];
	std::wstring temp;
	wchar_t wch = ',';
	wchar_t newline = '\r';
	int data_collected = 0;
	int last_index = 0;
	for (int i = 0; i < test.size(); i++)
	{
		if (test[i] == wch)
		{
			for (int z = last_index; z < i; z++)
			{
				temp = test[z];
				bufferString[data_collected].append(temp);
			}
			last_index = i + 1;
			data_collected++;
		}
		if (test[i] == newline)
		{
			for (int z = last_index; z < i; z++)
			{
				temp = test[z];
				bufferString[data_collected].append(temp);
			}
			data_collected++;
			last_index = i + 2;
		}

	}

	//testStringTCHAR = W2T((LPWSTR)bufferString[0].c_str());
	TCHAR* testStringTCHAR2 = W2T((LPWSTR)bufferString[1].c_str());

	/*for (int i = 0; i < test.size(); i++)
	{
	if (test[i] == ',')
	{
	int index = i;
	for (int v = 0; v < index; v++)
	{
	testString = W2T((LPWSTR)test.c_str());
	}
	}
	}*/
	for (int i = 0; i < data_collected; i += 3)
	{
		testStringTCHAR = W2T((LPWSTR)bufferString[i].c_str());
		SendMessage(hWndComboBox, CB_ADDSTRING, NULL, (LPARAM)testStringTCHAR);
	}

	//SendMessage(hWndComboBox, CB_ADDSTRING, NULL, (LPARAM)testStringTCHAR2);

	// Send the CB_SETCURSEL message to display an initial item 
	//  in the selection field  
	SendMessage(hWndComboBox, CB_SETCURSEL, (WPARAM)2, (LPARAM)0);

	confirmCustomer = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Confirm Booking Comedian",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		670,         // x position 
		530,         // y position 
		250,        // Button width
		25,        // Button height
		hWnd,     // Parent window
		(HMENU)IDC_COMEDIAN_SAVE,       // No menu.
		(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	return 1;
}
void LandingMenu::saveBookedComedian(TCHAR* eventDetails, int size)
{
	first_run = true;
	const TCHAR*  file = __TEXT("mylogfile.txt");
	HANDLE        h = ::CreateFile(file, GENERIC_WRITE, 0, 0, OPEN_ALWAYS, 0, 0);
	if (INVALID_HANDLE_VALUE != h)
	{
		unsigned long    w = 0;
		va_list          val;
		TCHAR            f[0x1000];
		int              l;

		va_start(val, eventDetails);
		l = _vsntprintf_s(f, sizeof(f) / sizeof(f[0]), _TRUNCATE, eventDetails, val);
		va_end(val);
		if (0 == SetFilePointer(h, 0, 0, FILE_END))
		{
			if (sizeof(short) == sizeof(TCHAR))
			{
				unsigned short  unicode = 0xFeFF;
				WriteFile(h, (void*)&unicode, 2, &w, 0);
			}
		}
		WriteFile(h, (void*)f, l*sizeof(TCHAR), &w, 0);
		CloseHandle(h);
	}
}

void LandingMenu::createInitialWindow(HWND hWnd)
{
	first_run = true;
	active_ui_elements = UIFactory::createPageControls("Landing Page", &hWnd, m_currentInstance);

	///////////////////////////////////////////
	lblObj = CreateWindow(
		TEXT("static"),
		TEXT("Comedy Club Booking System"),
		WS_VISIBLE | WS_CHILD,
		400,
		6,
		370,
		30,
		hWnd,
		(HMENU)3,
		NULL,
		NULL);
	HFONT hFont = CreateFont(32, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, L"Arial");
	SendMessage(lblObj, WM_SETFONT, WPARAM(hFont), TRUE);

	////////////////////////////////////////////////////////////////////
	if (newWindow == true)
	{
		hWnd = CreateWindow(
			szWindowClass,
			szTitle,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			500, 100,
			NULL,
			NULL,
			(HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE),
			NULL
			);
		newWindow = false;
	}
	/////////////////////////////////////////////////////////////////////////
	int xpos = 100;            // Horizontal position of the window.
	int ypos = 100;            // Vertical position of the window.
	int nwidth = 200;          // Width of the window
	int nheight = 200;         // Height of the window
	HWND hwndParent = hWnd; // Handle to the parent window

}