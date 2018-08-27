// Chat.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatApp

BEGIN_MESSAGE_MAP(CChatApp, CWinApp)
	//{{AFX_MSG_MAP(CChatApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatApp construction

CChatApp::CChatApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CChatApp object

CChatApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CChatApp initialization

BOOL CChatApp::InitInstance()
{
//	AfxEnableControlContainer();
	AfxInitRichEdit();
    CChatDlg dlg;
	dlg.DoModal ();


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	return FALSE;
}
