// xdcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "xdc.h"
#include "xdcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXdcDlg dialog

CXdcDlg::CXdcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXdcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXdcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXdcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXdcDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXdcDlg, CDialog)
	//{{AFX_MSG_MAP(CXdcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCPAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXdcDlg message handlers

BOOL CXdcDlg::OnInitDialog()
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

void CXdcDlg::OnPaint() 
{//构造dc对象时自动调用BeginPaint()函数
	CPaintDC dc(this);
	//画两个矩形
	dc.Rectangle (0,0,40,40);
	dc.Rectangle (80,80,120,120);
	//画一条线
	dc.MoveTo (20,20);
	dc.LineTo (100,100);
    dc.Ellipse (150,150,300,300);

}//析构dc对象时自动调用EndPaint函数（标准客户端绘画）

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CXdcDlg::OnQueryDragIcon()
{

	return (HCURSOR) m_hIcon;
}

void CXdcDlg::OnNcPaint() 
{//构造dc对象时自动调用GetWindowDC函数
	CWindowDC dc(this);
	CRect rect;
	GetWindowRect(rect);
	dc.Rectangle (0,0,rect.Width (),rect.Height ());
	char str[200];
	sprintf(str,"非客户区空间（%d,%d,%d,%d）",rect.left ,rect.top ,rect.bottom );
	dc.SetTextColor(RGB(255,0,0));//设置文字为红色
	dc.TextOut (5,5,str,strlen(str));//输出文字

	// Do not call CDialog::OnNcPaint() for painting messages
}//析构dc对象时自动调用ReleaseDC函数

void CXdcDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{//构造dc对象时自动调用GetDC函数
	CClientDC dc(this);
	//画一个圆形
    dc.Ellipse(point.x-10,point.y-10,point.x+10,point.y+10);
    //释放绘画句柄，必须与GetDC成对使用
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}//析构dc对象时自动调用ReleaseDC函数；

void CXdcDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}
