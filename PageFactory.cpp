#include "PageFactory.h"

DefaultWindowClass* PageFactory::createPage(char* page_name, HINSTANCE* projectInstance)
{
	DefaultWindowClass* page;
	try
	{
		if (page_name == "Landing Page")
		{
			page = new LandingMenu(projectInstance, "Landing Page", NULL);
		}
		else if (page_name == "Comedy Booking Menu")
		{
			page = new DefaultWindowClass(projectInstance, "Landing Page", NULL);
		}
		else if (page_name == "Event Booking Menu")
		{
			page = new DefaultWindowClass(projectInstance, "Landing Page", NULL);
		}
		else if (page_name == "Feedback Menu")
		{
			page = new DefaultWindowClass(projectInstance, "Landing Page", NULL);
		}
		else
		{
			// Return something useful here
			return NULL;
		}
	}
	catch (...)
	{
		std::cout << "Error, page init failed";
		return NULL;
	}

	page->createDefaultClass(page_name);
	page->registerClass();
	page->createDefaultWindow(page);

	return page;
}