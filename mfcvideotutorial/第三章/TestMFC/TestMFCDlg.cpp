// TestMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "TestMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg dialog

CTestMFCDlg::CTestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CTestMFCDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestMFCDlg message handlers

BOOL CTestMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestMFCDlg::OnPaint() 
{
	CPaintDC dc(this);
	dc.Ellipse (5,5,200,150);

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
