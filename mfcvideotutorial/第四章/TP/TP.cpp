// TP.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TP.h"
#include "TPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTPApp

BEGIN_MESSAGE_MAP(CTPApp, CWinApp)
	//{{AFX_MSG_MAP(CTPApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTPApp construction

CTPApp::CTPApp():CWinApp("aaaa")
{
	AfxMessageBox("m_pszAppName±»¸ü¸Ä");
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTPApp object

//CTPApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTPApp initialization

BOOL CTPApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.
	SetRegistryKey("250É±¶¾");
    SetDialogBkColor(RGB(255,255,255),RGB(255,0,0));
	CTPDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
