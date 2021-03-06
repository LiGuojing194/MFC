// RgnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Rgn.h"
#include "RgnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRgnDlg dialog

CRgnDlg::CRgnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRgnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRgnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRgnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRgnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRgnDlg, CDialog)
	//{{AFX_MSG_MAP(CRgnDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRgnDlg message handlers
#define TRANSCOLOR RGB(1,1,1)
BOOL CRgnDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    int i=0;
	CString str;
	while(i<FLY_CNT)
    {
	  str.Format("./img/%03d.bmp",i+1);
	  m_dc[i].LoadBitmap(str);
	  m_dc[i].BitRgn(m_rgn[i],TRANSCOLOR);
      i++;
	}
	ModifyStyle(GetStyle(),0);
	ModifyStyleEx(GetExStyle(),WS_EX_TOOLWINDOW);
	int cx=GetSystemMetrics(SM_CXSCREEN);
	int cy=GetSystemMetrics(SM_CYSCREEN);
    srand(time(NULL));
	m_pos.x=rand()%(cx-m_dc[0].Width());
	m_pos.y=rand()%(cy-m_dc[0].Height());

	m_nIndex=0;
	CMemDC &mdc=m_dc[m_nIndex];        //���ô���λ�ò��ö�
	SetWindowPos(&wndTopMost,m_pos.x,m_pos.y,mdc.Width(),mdc.Height(),0);
	CRgn rgn;
	rgn.CreateRectRgn(0,0,0,0);
	rgn.CopyRgn(&m_rgn[m_nIndex]);
	SetWindowRgn(rgn,TRUE);
	SetTimer(1,64,NULL);
	return TRUE;

}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRgnDlg::OnPaint() 
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
HCURSOR CRgnDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRgnDlg::OnTimer(UINT nIDEvent) 
{
    CMemDC &mdc=m_dc[m_nIndex];
	MoveWindow(m_pos.x,m_pos.y,mdc.Width(),mdc.Height());
	CRgn rgn;
	rgn.CreateRectRgn(0,0,0,0);
	rgn.CopyRgn(&m_rgn[m_nIndex]);
	SetWindowRgn(rgn,TRUE);
	CClientDC dc(this);
	mdc.BitTrans (0,0,mdc.Width (),mdc.Height (),&dc,0,0,SRCCOPY);
	static int cx=5,cy=5;
	m_pos.Offset (cx,cy);
	if(m_pos.x+mdc.Width ()>GetSystemMetrics(SM_CXSCREEN)||m_pos.x <0)
		cx*=-1;
	if(m_pos.x+mdc.Width ()>GetSystemMetrics(SM_CXSCREEN)||m_pos.x <0)
        cy*=-1;
	if(++m_nIndex>=FLY_CNT)
		m_nIndex=0;
	CDialog::OnTimer(nIDEvent);
}
