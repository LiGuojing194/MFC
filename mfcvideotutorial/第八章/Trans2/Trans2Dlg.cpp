// Trans2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Trans2.h"
#include "Trans2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrans2Dlg dialog

CTrans2Dlg::CTrans2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrans2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrans2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrans2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrans2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrans2Dlg, CDialog)
	//{{AFX_MSG_MAP(CTrans2Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrans2Dlg message handlers

BOOL CTrans2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    //m_dc.LoadBitmap(IDB_BITMAP6);
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

void CTrans2Dlg::OnPaint() 
{

  CPaintDC dc(this);
  if(!m_dc)   //第一次执行时加载
	  m_dc.LoadBitmap(IDB_BITMAP6);
 //原图输出
  dc.BitBlt (0,0,m_dc.Width(),m_dc.Height(),&m_dc,0,0,SRCCOPY);
  //透明输出
  m_dc.BitTrans (m_dc.Width(),0,m_dc.Width(),m_dc.Height(),&dc,0,0,RGB(0,0,255));
  dc.SetStretchBltMode (HALFTONE);//拉伸并透明
  m_dc.StretchTrans(0,90,200,200,&dc,0,0,m_dc.Width(),m_dc.Height(),RGB(0,0,255));

  }

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrans2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
