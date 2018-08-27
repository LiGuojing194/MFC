// test2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "test2.h"
#include "test2Dlg.h"
#include "ABOUTDLG.h"
#include"ChatDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2Dlg dialog

CTest2Dlg::CTest2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest2Dlg, CDialog)
	//{{AFX_MSG_MAP(CTest2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2Dlg message handlers

BOOL CTest2Dlg::OnInitDialog()
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

void CTest2Dlg::OnPaint() 
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
HCURSOR CTest2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest2Dlg::OnOK() 
{

	
	CDialog::OnOK();
}

void CTest2Dlg::OnButton1() 
{//模式对话框，不可以操作背景窗口，副窗口
	ABOUTDLG dlg;
	dlg.DoModal ();

	
}
//必须在堆内申请对象，或在成员变量内申请对象。
void CTest2Dlg::OnButton2() 
{
	CChatDlg*pDlg=new CChatDlg;
	pDlg->Create (IDD_CHAT_DLG);
	pDlg->ShowWindow (SW_SHOW);

	
}

int CTest2Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}

void CTest2Dlg::OnButton3() 
{
	DestroyWindow();//摧毁对话框

 /*CWnd*pWnd=GetDlgItem(IDOK);
	if(pWnd)
		pWnd->DestroyWindow();*///摧毁控件
}
CWnd m_wnd;
enum{IDC_NAME};
void CTest2Dlg::OnButton4() 
{
   m_wnd.Create("Edit","",WS_CHILD|WS_VISIBLE,CRect(370,150,470,180),this,IDC_NAME);	
}
