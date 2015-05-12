#include "UIFactory.h"

vector<Controls*> UIFactory::createPageControls(char* initial_page, HWND* parentWindow, HINSTANCE* currentInstance)
{
	vector<Controls*> UIElements;
	if (initial_page == "Landing Page")
	{
		Controls* first_button = new Button("Book Comedians", IDC_COMEDIAN_BOOK, parentWindow);
		first_button->createControl(250, 150, 150, 100);
		UIElements.push_back(first_button);

		Controls* second_button = new Button("Book Customers", IDC_CUSTOMER_BOOK, parentWindow);
		second_button->createControl(750, 150, 150, 100);
		UIElements.push_back(second_button);

		Controls* third_button = new Button("View Events", IDC_EVENT_VIEW, parentWindow);
		third_button->createControl(500, 150, 150, 100);
		UIElements.push_back(third_button);

		Controls* title_menu = new Title("Comedy Club Booking System", IDC_TITLE_MENU, parentWindow,32);
		title_menu->createControl(400, 6, 370, 30);
		UIElements.push_back(title_menu);
	}

	return UIElements;
}