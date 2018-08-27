// First232.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include"resource.h"
//Windows 消息回调函数
BOOL CALLBACK dlgFunc(HWND hwndDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_COMMAND:
		switch(wParam)
		{
	case IDCANCEL:
		EndDialog(hwndDlg,IDCANCEL);
		break;
	case IDOK:
		{
			int nLeft=GetDlgItemInt(hwndDlg,IDC_LEFT,NULL,TRUE);
			int nRight=GetDlgItemInt(hwndDlg,IDC_RIGHT,NULL,TRUE);
			SetDlgItemInt(hwndDlg,IDC_RESULT,nLeft+nRight,TRUE);
		}
		break;
	}
	break;
	}
	return FALSE;
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
//MessageBox(NULL,"This is my first windows program!","wenxintishi",MB_OK|MB_ICONINFORMATION);
	DialogBox(hInstance,(LPCTSTR)IDD_FIRSTDLG,NULL,dlgFunc);
	return 0;
}



