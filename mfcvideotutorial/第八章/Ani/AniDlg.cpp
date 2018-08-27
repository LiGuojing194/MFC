// AniDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ani.h"
#include "AniDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAniDlg dialog

CAniDlg::CAniDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAniDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAniDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAniDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAniDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAniDlg, CDialog)
	//{{AFX_MSG_MAP(CAniDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAniDlg message handlers

BOOL CAniDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetTimer(1,64,NULL);

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

void CAniDlg::OnPaint() 
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
HCURSOR CAniDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAniDlg::OnTimer(UINT nIDEvent) 
{
  CClientDC dc(this);
  if(!m_dc[0])
  {//第一次进入函数时加载所有图片
	  int i=0;
	  CString str;
	  while(i<12)
	  {
	    str.Format("./dogs/%03d.bmp",i+1);
		m_dc[i].LoadBitmap(str,&dc);
		++i;
	  }
  }
  static int i=0;
  //每次播放一帧图片
  dc.BitBlt(10,10,m_dc[i].Width(),m_dc[i].Height(),&m_dc[i],0,0,SRCCOPY);
  if(++i>=12)
	  i=0;
	CDialog::OnTimer(nIDEvent);
}
