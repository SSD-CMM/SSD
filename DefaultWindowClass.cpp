#include "DefaultWindowClass.h"
LPCSTR convertChartoLPC(LPCSTR test);

DefaultWindowClass::DefaultWindowClass(HINSTANCE* currentInstance, const char* name, WNDPROC window) : WindowDisplayClass(currentInstance, name)
{
	m_currentClass.lpfnWndProc = window;
	m_currentInstance = currentInstance;
	m_name = name;
}

//Registering Class to instance.
ATOM DefaultWindowClass::registerClass()
{
	return RegisterClassExA(&m_currentClass);
}

ATOM DefaultWindowClass::registerClass(WNDCLASSEXA* passedClass)
{
	return RegisterClassExA(passedClass);
}
//As a future base class, defaults are loaded in a prerequisites to other windows.
void DefaultWindowClass::createDefaultClass()
{
	m_currentClass.cbSize = sizeof(WNDCLASSEXA);

	m_currentClass.style = CS_HREDRAW | CS_VREDRAW;
	m_currentClass.cbClsExtra = 0;
	m_currentClass.cbWndExtra = 0;
	m_currentClass.hInstance = *m_currentInstance;
	m_currentClass.hIcon = 0;
	m_currentClass.hCursor = 0;
	m_currentClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	m_currentClass.lpszMenuName = "Default";
	m_currentClass.lpszClassName = "Default";
	m_currentClass.hIconSm = 0;
	m_currentClass.lpfnWndProc = DefaultWindowClass::createChildWndProcedure;

}
//Window to create passes to child wndproc!
void DefaultWindowClass::createDefaultWindow(void* windowToCreate)
{
	CreateWindowA((LPCSTR)getName(), (LPCSTR)"Default", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, *m_currentInstance, windowToCreate);
}
//Unused for now.
LPCSTR convertChartoLPC(LPCSTR test)
{
	return test;
}

LRESULT CALLBACK DefaultWindowClass::WndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_CREATE:
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	return 0;
}

LRESULT CALLBACK DefaultWindowClass::createChildWndProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	HRESULT hr = S_OK;
	DefaultWindowClass* ParentMenu;
	ParentMenu = (DefaultWindowClass*)GetWindowLongPtr(hWnd, GWL_USERDATA);
	if (Msg == WM_CREATE)
	{
		ParentMenu = (DefaultWindowClass*)((LPCREATESTRUCT)lParam)->lpCreateParams;
		hr = SetWindowLongPtr(hWnd, GWL_USERDATA, (LONG_PTR)ParentMenu);
	}
	else
	{
		ParentMenu = (DefaultWindowClass*)GetWindowLongPtr(hWnd, GWL_USERDATA);
		if (!ParentMenu) return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	if (ParentMenu)
	{
		//Now we can pipe it to the Window's local wnd proc function
		return ParentMenu->WndProcedure(hWnd,Msg, wParam, lParam);
	}

	return DefWindowProc(hWnd, Msg, wParam, lParam);
}