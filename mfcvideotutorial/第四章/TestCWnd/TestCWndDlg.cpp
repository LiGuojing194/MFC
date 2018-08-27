// TestCWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestCWnd.h"
#include "TestCWndDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCWndDlg dialog

CTestCWndDlg::CTestCWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestCWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestCWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestCWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestCWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestCWndDlg, CDialog)
	//{{AFX_MSG_MAP(CTestCWndDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	ON_BN_CLICKED(IDC_BUTTON13, OnButton13)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestCWndDlg message handlers

BOOL CTestCWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    HWND hWnd=::GetDlgItem(m_hWnd,IDC_EDIT1);
	m_edit.Attach(hWnd);
//	hWnd=::GetDlgItem(m_hWnd,IDC_BUTTON1);
//	m_dest.SubClassWindow(hWnd);
	//m_creat.SubClassDlgItem(IDC_BUTTON2,this);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestCWndDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestCWndDlg::OnPaint() 
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
HCURSOR CTestCWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestCWndDlg::OnButton4() 
{
DestroyWindow();	
}

void CTestCWndDlg::OnButton5() 
{
	if(!m_list)//长期有效
	m_list.CreateEx(WS_EX_CLIENTEDGE,"Static",NULL,WS_CHILD|WS_VISIBLE|LVS_REPORT,CRect(20,50,300,300), this,8921);
	
}

void CTestCWndDlg::OnButton1() 
{
CWnd* pWnd=GetDlgItem(IDOK);
HWND hWnd=pWnd->GetSafeHwnd();
if(hWnd)
pWnd->DestroyWindow();	
}

void CTestCWndDlg::OnButton2() 
{
	HWND hWnd=::GetDlgItem(m_hWnd,IDOK);
	CWnd*p=CWnd::FromHandle(hWnd);//只限于本成员函数内使用
	p->SetWindowText("临时对象");
	
}

void CTestCWndDlg::OnButton3() 
{
m_edit.SetWindowText("长期有效");
	
}

void CTestCWndDlg::OnDestroy() 
{
	CDialog::OnDestroy();
//	m_dest.UnSubClassWindow();
    m_edit.Detach();	
}

void CTestCWndDlg::OnButton6() 
{
DWORD dwExStyle=m_edit.GetExStyle ();
m_edit.ModifyStyleEx (0,WS_EX_DLGMODALFRAME|WS_EX_CLIENTEDGE);
CRect rect;
m_edit.GetWindowRect(rect);
ScreenToClient(rect);//将屏幕坐标系转为客服区坐标系
rect.InflateRect (3,3);
m_edit.MoveWindow (rect);
Invalidate();	
}

void CTestCWndDlg::OnButton7() 
{
SetTimer(123,500,NULL);//编号123，间隔五百毫秒
SetTimer(1,500,NULL);	
}

void CTestCWndDlg::OnTimer(UINT nID) 
{
	if(nID==1)
	{
		CString Str;
		GetWindowText(Str);
		if(Str=="time...")
			Str="Set...";
		else
			Str="time...";
		SetWindowText(Str);
	}
	if(nID==123)
	{
	CRect Rect;
	m_edit.GetWindowRect (Rect);
	ScreenToClient(Rect);
//	Rect.InflateRect (3,3);
	Rect.OffsetRect (10,2);
	CRect rRec;
    GetClientRect(rRec);
	if(Rect.right>rRec.right)
		KillTimer(123);
		//Rect.OffsetRect (-Rect.left,0);
	m_edit.MoveWindow (Rect);
	}
	CDialog::OnTimer(nID);
}

void CTestCWndDlg::OnButton8() 
{
//ShowWindow(SW_MAXIMIZE);
//	ShowWindow(SW_MINIMIZE);
	CWnd*pCan=GetDlgItem(IDCANCEL);
	if(pCan->IsWindowVisible())//判断窗口是否可见或被隐藏
	pCan->ShowWindow(SW_HIDE);
	else   pCan->ShowWindow (SW_SHOW);
}

void CTestCWndDlg::OnButton9() 
{
	CWnd*pCan=GetDlgItem(IDCANCEL);
//	if(pCan->IsWindowEnabled())//判断是否被激活
  //  pCan->EnableWindow (FALSE);//对窗口或控件禁用
	//else  pCan->EnableWindow (TRUE);
	pCan->EnableWindow(!pCan->IsWindowEnabled ());
	
}

void CTestCWndDlg::OnButton10() 
{
	CWnd*pWnd=FindWindow ("RenderWindow",NULL);
	if(pWnd&&pWnd->IsIconic())
		pWnd->ShowWindow(SW_MAXIMIZE);
	
}

void CTestCWndDlg::OnButton11() 
{
if(IsZoomed())	
this->SetWindowText ("是最大化的");
else   this->SetWindowText ("是最小化的");
}

void CTestCWndDlg::OnButton12() 
{
CenterWindow();	
}

void CTestCWndDlg::OnButton13() 
{
	CRect rect;
m_edit.GetWindowRect(rect);
ScreenToClient(rect);
rect.OffsetRect(5,0);
//m_edit.SetWindowPos(&wndTop,rect.left,rect.top,rect.Width(),rect.Height (),0);
//m_edit.SetWindowPos(&wndTop,rect.left,rect.top,0,0,SWP_NOSIZE);
//m_edit.SetWindowPos(&wndTop,rect.left,rect.top,0,0,SWP_NOSIZE|SWP_NOMOVE);//不能去改变位置，只能改变z轴
//Invalidate();	
SetWindowPos(&wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);//前端显示
}
