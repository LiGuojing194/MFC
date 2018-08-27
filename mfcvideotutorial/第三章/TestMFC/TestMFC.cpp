// TestMFC.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"
#include"LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp

BEGIN_MESSAGE_MAP(CTestMFCApp, CWinApp)
	//{{AFX_MSG_MAP(CTestMFCApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp construction

CTestMFCApp::CTestMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestMFCApp object

CTestMFCApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTestMFCApp initialization

BOOL CTestMFCApp::InitInstance()
{
	CLoginDlg lDlg;
	if(IDCANCEL==lDlg.DoModal ())
		return FALSE;
	CTestMFCDlg dlg;     //定义CDialog派生类的对象
	int nResponse=dlg.DoModal ();
	return FALSE;
}
