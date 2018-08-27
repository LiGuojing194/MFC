// refrectMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "refrectMFC.h"
#include "refrectMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCDlg dialog

CRefrectMFCDlg::CRefrectMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRefrectMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRefrectMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRefrectMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRefrectMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRefrectMFCDlg, CDialog)
	//{{AFX_MSG_MAP(CRefrectMFCDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRefrectMFCDlg message handlers

BOOL CRefrectMFCDlg::OnInitDialog()
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

void CRefrectMFCDlg::OnPaint() 
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
HCURSOR CRefrectMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRefrectMFCDlg::OnStart()                //怎样才可以，不点击开始键就显示出时间？
{ 
	CTime t=CTime::GetCurrentTime();
	int nYear=t.GetYear();
	int nMonth=t.GetMonth();
    int nDay=t.GetDay();
	int nHour=t.GetHour();
	int nMin=t.GetMinute();
	int nSec=t.GetSecond();
	//int nWeek=t.GetDayOfWeek();//1代表周日
	CString Str;
	Str.Format("%d年%02d月%02d日  %02d:%02d:%02d",nYear,nMonth,nDay,nHour,nMin,nSec);
	SetDlgItemText(IDC_DATE,Str);

	
}

void CRefrectMFCDlg::OnOK() 
{
	MessageBox("不要败给懒惰！","时刻警醒",MB_OK|MB_ICONWARNING);
	MessageBox("不要败给看剧！","时刻警醒",MB_OK|MB_ICONWARNING);
    MessageBox("不要败给自己!!!","时刻警醒",MB_OK|MB_ICONWARNING);
	MessageBox("加油向上吧!","时刻警醒",MB_OK|MB_ICONWARNING);
    CDialog::OnOK();
}
