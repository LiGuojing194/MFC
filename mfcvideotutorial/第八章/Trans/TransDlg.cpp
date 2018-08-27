// TransDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Trans.h"
#include "TransDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransDlg dialog

CTransDlg::CTransDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTransDlg, CDialog)
	//{{AFX_MSG_MAP(CTransDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransDlg message handlers

BOOL CTransDlg::OnInitDialog()
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

void CTransDlg::OnPaint() 
{
  CPaintDC dc(this);
  if(!m_dc)   //第一次执行时加载
	  m_dc.LoadBitmap(IDB_BITMAP2);
 //原图输出
  dc.BitBlt (0,0,m_dc.Width(),m_dc.Height(),&m_dc,0,0,SRCCOPY);
  //透明输出
  m_dc.BitTrans (m_dc.Width(),0,m_dc.Width(),m_dc.Height(),&dc,0,0,RGB(255,0,0));
  dc.SetStretchBltMode (HALFTONE);//拉伸并透明
  m_dc.StretchTrans(0,30,200,200,&dc,0,0,m_dc.Width(),m_dc.Height(),RGB(255,0,0));
  //

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTransDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
