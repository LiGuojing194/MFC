// FlysDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Flys.h"
#include "FlysDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlysDlg dialog

CFlysDlg::CFlysDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlysDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFlysDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlysDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFlysDlg, CDialog)
	//{{AFX_MSG_MAP(CFlysDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlysDlg message handlers

BOOL CFlysDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	LoadPicture();
	ModifyStyleEx(GetExStyle(),0);
	ModifyStyle(GetStyle(),0);
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
	MoveWindow(0,0,cx,cy);
	SetTimer(1,64,NULL);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFlysDlg::OnPaint() 
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
HCURSOR CFlysDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFlysDlg::LoadPicture()
{
	m_dcBack.LoadBitmap("./img/Backgnd.bmp");
	int i=0;
	CString str;
	while(i<FLY_CNT)
	{
	  str.Format("./img/%03d.bmp",i+1);
	  m_dcFly[i].LoadBitmap(str);
	  ++i;
	}
}

void CFlysDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int cx=point.x%2?5:-5;
	int cy=point.y%2?5:-5;
	int nIndex=(point.x+point.y)%FLY_CNT;
	SFly fly={nIndex,point.x,point.y,cx,cy};
	m_list.AddTail(fly);
	CDialog::OnLButtonDown(nFlags, point);
}

void CFlysDlg::OnDraw(CDC *pDC)
{
	CRect rect;
	GetClientRect(rect);
    pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&m_dcBack,0,0,m_dcBack.Width(),m_dcBack.Height(),SRCCOPY);
	POSITION pos=m_list.GetHeadPosition();
	while(pos)
	{
	  SFly&fly=m_list.GetNext(pos);
	  CMemDC &mdc=m_dcFly[fly.nIndex];
	  mdc.BitTrans(fly.x,fly.y,mdc.Width(),mdc.Height(),pDC,0,0,RGB(0,0,255));
	  fly.x+=fly.cx;
	  fly.y+=fly.cy;
	  if(fly.x+mdc.Width()>rect.Width()||fly.x<0)
		  fly.cx*=-1;
	  if(fly.y+mdc.Height()>rect.Height()||fly.y<0)
		  fly.cy*=-1;
	  if(++fly.nIndex>=FLY_CNT)
		  fly.nIndex=0;


	}
}

void CFlysDlg::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this);
	CRect rect;
	GetClientRect(rect);
	CMemDC bdc(rect.Width(),rect.Height(),&dc);
	OnDraw(&bdc);
	dc.BitBlt(0,0,rect.Width(),rect.Height(),&bdc,0,0,SRCCOPY);
	CDialog::OnTimer(nIDEvent);
}
