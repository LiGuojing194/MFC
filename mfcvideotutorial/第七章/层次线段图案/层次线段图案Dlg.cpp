// 层次线段图案Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "层次线段图案.h"
#include "层次线段图案Dlg.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
	DDX_Control(pDX, IDOK, m_ok);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_ok.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON1));
	SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	//	CMyDlg::OnLineTo ();
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

void CMyDlg::OnPaint() 
{
	 double i,j;
  int x1,x2,x3,y1,y2,y3,x4,y4;
  CClientDC pdc(this);
  CPen pen(PS_SOLID,1,RGB(255,0,0));
  pdc.SelectObject (&pen);
  for(i=0;i<6.28;i+=6.28/8.0){
	  x1=(int)(45*cos(i));y1=(int)(45*sin(i));
	  x2=(int)(30*cos(i));y2=(int)(30*sin(i));
	  for(j=0;j<=6.3;j+=0.1){
		  x3=(int)(45*cos(j));y3=(int)(45*sin(j));
		  x4=(int)(30*cos(j));y4=(int)(30*sin(j));
		  x3=130+x1+x3;y3=90+y1+y3;
		  x4=130+x2+x4;y4=90+y2+y4;
		  pdc.MoveTo(x3+52,y3+80);
		  pdc.LineTo(x4+52,y4+80);}
  }
  for(i=0;i<6.283;i+=6.283/200.0){
	  x1=(int)(50*(2*cos(i)-cos(2*i)))+200;
	  y1=(int)(50*(2*sin(i)-sin(2*i)))+170;
	  x2=(int)(50*(2*cos(i+1)-cos(2*(i+1))))+200;
	  y2=(int)(50*(2*sin(i+1)-sin(2*(i+1))))+170;
	  pdc.MoveTo (x1,y1);
	  pdc.LineTo (x2,y2);
  }
	
	CDialog::OnPaint();
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyDlg::OnLineTo()
{
  double i,j;
  int x1,x2,x3,y1,y2,y3,x4,y4;
  CClientDC pdc(this);
  CPen pen(PS_SOLID,1,RGB(255,0,0));
  pdc.SelectObject (&pen);
  for(i=0;i<6.28;i+=6.28/8.0){
	  x1=(int)(45*cos(i));y1=(int)(45*sin(i));
	  x2=(int)(30*cos(i));y2=(int)(30*sin(i));
	  for(j=0;j<=6.3;j+=0.1){
		  x3=(int)(45*cos(j));y3=(int)(45*sin(j));
		  x4=(int)(30*cos(j));y4=(int)(30*sin(j));
		  x3=130+x1+x3;y3=90+y1+y3;
		  x4=130+x2+x4;y4=90+y2+y4;
		  pdc.MoveTo(x3,y3);
		  pdc.LineTo(x4,y4);}
  }
}

BOOL CMyDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}
