// calDlg.cpp : implementation file
//

#include "stdafx.h"
#include "cal.h"
#include "calDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalDlg dialog

CCalDlg::CCalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCalDlg)
	m_nResult = 0;
	m_nLeft = 0;
	m_nRight = 0;
	m_nOper = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalDlg)
	DDX_Text(pDX, IDC_RESULT, m_nResult);
	DDX_Text(pDX, IDC_LEFT, m_nLeft);
	DDX_Text(pDX, IDC_RIGHT, m_nRight);
	DDX_CBIndex(pDX, IDC_OPER, m_nOper);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalDlg, CDialog)
	//{{AFX_MSG_MAP(CCalDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalDlg message handlers

BOOL CCalDlg::OnInitDialog()
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

void CCalDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCalDlg::OnOK() 
{
UpdateData();
switch(m_nOper)
{
case 0:
	m_nResult=m_nLeft+m_nRight;
	break;
case 1:
	m_nResult=m_nLeft-m_nRight;
	break;
case 2:
	m_nResult=m_nLeft*m_nRight;
    break;
case 3:
	m_nResult=m_nLeft/m_nRight;
    break;
case 4:
	m_nResult=m_nLeft%m_nRight;
	break;
}
UpdateData(FALSE);
	//CDialog::OnOK();
}
