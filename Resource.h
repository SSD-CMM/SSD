//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by Win32Project1.rc
//

#define IDS_APP_TITLE			103

#define IDR_MAINFRAME			128
#define IDD_WIN32PROJECT1_DIALOG	102
#define IDD_ABOUTBOX			103
#define IDM_ABOUT				104
#define IDM_EXIT				105
#define IDI_WIN32PROJECT1			107
#define IDI_SMALL				108
#define IDC_WIN32PROJECT1			109
#define IDC_MYICON				2
#ifndef IDC_STATIC
#define IDC_STATIC				-1
#define IDD_CONTROLSDLG 101
#define IDD_SIZE_CBO    102
#endif
// Next default values for new objects
//
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC					130
#define _APS_NEXT_RESOURCE_VALUE	129
#define _APS_NEXT_COMMAND_VALUE		32771
#define _APS_NEXT_CONTROL_VALUE		1000
#define _APS_NEXT_SYMED_VALUE		110
#include "resource.h"

IDD_CONTROLSDLG DIALOG 260, 200, 180, 120
STYLE DS_MODALFRAME | WS_POPUP | WS_CAPTION | WS_SYSMENU
CAPTION "Windows Controls"
FONT 8, "MS Shell Dlg"
BEGIN
DEFPUSHBUTTON   "Close", IDCANCEL, 120, 100, 50, 14
COMBOBOX        IDD_SIZE_CBO, 40, 8, 90, 80
END
#endif
#endif


