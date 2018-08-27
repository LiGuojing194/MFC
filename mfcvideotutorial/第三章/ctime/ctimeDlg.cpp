// ctimeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ctime.h"
#include "ctimeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCtimeDlg dialog

CCtimeDlg::CCtimeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCtimeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCtimeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCtimeDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCtimeDlg, CDialog)
	//{{AFX_MSG_MAP(CCtimeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtimeDlg message handlers

BOOL CCtimeDlg::OnInitDialog()
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

void CCtimeDlg::OnPaint() 
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
HCURSOR CCtimeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCtimeDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CTime t=CTime::GetCurrentTime();
	int nYear=t.GetYear();
	int nMonth=t.GetMonth();
    int nDay=t.GetDay();
	int nHour=t.GetHour();
	int nMin=t.GetMinute();
	int nSec=t.GetSecond();
	int nWeek=t.GetDayOfWeek();//1代表周日
	CString Str;
	Str.Format("当前时间：%d年%02d月%02d日  %02d:%02d:%02d",nYear,nMonth,nDay,nHour,nMin,nSec);
	//AfxMessageBox(Str);
	SetWindowText(Str);
}

void CCtimeDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	time_t tt=time(NULL);
	tm * pt=localtime(&tt);
	int nYear=pt->tm_year +1900;
	int nMonth=pt->tm_mon +1;
	int nDay=pt->tm_mday ;
	int nHour=pt->tm_hour ;
	int nMinute=pt->tm_min ;
	int nSecond=pt->tm_sec ;
	char szTime[64];
	sprintf(szTime,"%d-%d-%d-%02d:%02d:%02d",nYear,nMonth,nDay,nHour,nMinute,nSecond);
	::MessageBox(NULL,szTime,"测试time",MB_OK);
}
