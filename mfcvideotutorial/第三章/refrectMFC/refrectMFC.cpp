// refrectMFC.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "refrectMFC.h"
#include "refrectMFCDlg.h"
#include"login.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCApp

BEGIN_MESSAGE_MAP(CRefrectMFCApp, CWinApp)
	//{{AFX_MSG_MAP(CRefrectMFCApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCApp construction

CRefrectMFCApp::CRefrectMFCApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CRefrectMFCApp object

CRefrectMFCApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCApp initialization

BOOL CRefrectMFCApp::InitInstance()
{

    login  ldlg;
	if(IDCANCEL==ldlg.DoModal ())
		return FALSE;
	CRefrectMFCDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	
	}

	return FALSE;
}
