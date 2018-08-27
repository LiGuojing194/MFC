// toumingseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "toumingse.h"
#include "toumingseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToumingseDlg dialog

CToumingseDlg::CToumingseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CToumingseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CToumingseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CToumingseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CToumingseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CToumingseDlg, CDialog)
	//{{AFX_MSG_MAP(CToumingseDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToumingseDlg message handlers

BOOL CToumingseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_dc.LoadBitmap(IDB_BITMAP1);
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

void CToumingseDlg::OnPaint() 
{
	CPaintDC dc(this);
//	dc.BitBlt (0,0,m_dc.Width(),m_dc.Height(),&m_dc,0,0,SRCCOPY);	
	m_dc.BitTrans (0,0,m_dc.Width(),m_dc.Height(),&dc,0,0,RGB(225,0,225));

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CToumingseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
