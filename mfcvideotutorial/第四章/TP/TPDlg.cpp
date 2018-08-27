// TPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TP.h"
#include "TPDlg.h"
//#include"WINDOWS.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef IDC_HAND
#define  IDC_HAND     MAKEINTRESOURCE(32649)
#endif


/////////////////////////////////////////////////////////////////////////////
// CTPDlg dialog

CTPDlg::CTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTPDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTPDlg, CDialog)
	//{{AFX_MSG_MAP(CTPDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SETCURSOR()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTPDlg message handlers
CTPApp theApp;
BOOL CTPDlg::OnInitDialog()
{//在主对话框初始化时，从配置文件中读取上次退出时保存的矩形区域
	CDialog::OnInitDialog();//加载图标
	HICON hIcon=AfxGetApp()->LoadStandardIcon(IDI_APPLICATION);
	SetIcon(hIcon,FALSE);
	//HICON hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDI_ICON1));
//	SetIcon(hIcon,FALSE);
	//HICON hIcon=theApp.LoadIcon (IDI_ICON1);
//	SetIcon(hIcon,FALSE);
 // HICON hIcon=LoadIcon(NULL,IDI_EXCLAMATION);
  //SetIcon(hIcon,FALSE);
	CRect rect;
	rect.left =theApp.GetProfileInt("PLACE","LEFT",0);
	rect.top =theApp.GetProfileInt("PLACE","TOP",0);
	rect.right =theApp.GetProfileInt("PLACE","RIGHT",0);
	rect.bottom=theApp.GetProfileInt("PLACE","BOTTOM",0);
    if(rect.Width ()>0)
		MoveWindow(rect);
	CString szTitle=theApp.GetProfileString("face","title","");
	if(szTitle.GetLength ())
		SetWindowText(szTitle);
    //SetWindowText(theApp.m_lpCmdLine );
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	//SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTPDlg::OnPaint() 
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
HCURSOR CTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CTPDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	switch(pWnd->GetDlgCtrlID ())
	{
	case IDOK:
		SetCursor(AfxGetApp()->LoadStandardCursor (IDC_HELP));
		return TRUE;
	case IDCANCEL:
		SetCursor(AfxGetApp()->LoadStandardCursor (IDC_HAND));
		return TRUE;
	}
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CTPDlg::OnDestroy() 
{//当主对话框关闭时，把对话框的矩形区域保存到配置文件
	CDialog::OnDestroy();
	CRect rect;
	GetWindowRect(rect);
	CWinApp*pApp=AfxGetApp();
	pApp->WriteProfileInt ("Place","Left",rect.left );
	pApp->WriteProfileInt ("Place","Top",rect.top);
	pApp->WriteProfileInt ("Place","Right",rect.right );
    pApp->WriteProfileInt ("Place","Bottom",rect.bottom );
    CString str;
	GetWindowText(str);
    pApp->WriteProfileString("Face","Title",str);




}
