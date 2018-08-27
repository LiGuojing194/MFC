// FlyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Fly.h"
#include "FlyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlyDlg dialog

CFlyDlg::CFlyDlg(CWnd* pParent /*=NULL*/)//在构造函数中初始化变量
	: CDialog(CFlyDlg::IDD, pParent)
{
	m_nIndex=0;
	m_pos=CPoint(0,0);
	//{{AFX_DATA_INIT(CFlyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlyDlg, CDialog)
	//{{AFX_MSG_MAP(CFlyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlyDlg message handlers

BOOL CFlyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	LoadPicture();//加载图片
	//去掉标题和边框
	ModifyStyleEx(GetExStyle(),0);
	ModifyStyle(GetStyle(),0);
	//使窗口全屏显示
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(0,0,cx,cy);
	SetTimer(1,64,NULL);//设置动画定时器

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

void CFlyDlg::OnPaint() 
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
HCURSOR CFlyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFlyDlg::LoadPicture()
{
	m_dcBack.LoadBitmap("./img/backgnd.bmp");
	int i=0;
	CString str;
	while(i<FLY_CNT)
	{
        str.Format("./img/%03d.bmp",i+1);
		m_dcFly[i].LoadBitmap(str);
		++i;
	}

}

void CFlyDlg::OnDraw(CDC *pDC)
{
	CRect rect;
	GetClientRect(rect);
	//拉伸一张全屏的背景图
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&m_dcBack,
		0,0,m_dcBack.Width(),m_dcBack.Height(),SRCCOPY);
	//绘制当前帧透明蝴蝶图片
	CMemDC &dc=m_dcFly[m_nIndex];
	dc.BitTrans(m_pos.x,m_pos.y,dc.Width(),dc.Height(),pDC,0,0,RGB(0,0,255));
	static int cx=3,cy=3;
	//计算绘制下一帧蝴蝶图片的坐标
	m_pos.Offset(cx,cy);
	if(m_pos.x+dc.Width()>rect.Width()||m_pos.x<0)
		cx*=-1;
	if(m_pos.y+dc.Height()>rect.Height()||m_pos.y<0)
		cy*=-1;

}

void CFlyDlg::OnTimer(UINT nIDEvent) 
{
    CClientDC dc(this);	
	OnDraw(&dc);
	CDialog::OnTimer(nIDEvent);
}
