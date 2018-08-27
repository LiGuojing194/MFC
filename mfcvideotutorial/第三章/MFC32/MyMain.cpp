// MyMain.cpp : implementation file
//

#include "stdafx.h"
#include "MyMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyMain dialog


CMyMain::CMyMain(CWnd* pParent /*=NULL*/)
	: CDialog(CMyMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyMain)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyMain)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyMain, CDialog)
	//{{AFX_MSG_MAP(CMyMain)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyMain message handlers

void CMyMain::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CString str;
	str.Format("x=%d,y=%d",point.x,point.y);
	if(nFlags&MK_LBUTTON)
		str+="左键按下";
	if(nFlags&MK_RBUTTON)
		str+="右键按下";
    if(nFlags&MK_CONTROL)
		str+="CTRL按下";
	if(nFlags&MK_SHIFT)
		str+="SHIFT按下";
	SetWindowText(str);
	CDialog::OnMouseMove(nFlags, point);
}

void CMyMain::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CMyMain::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetWindowText("InitDialog");
	HICON hIcon=LoadIcon(AfxGetInstanceHandle(),(LPCSTR)IDI_ICON1);
    SetIcon(hIcon,FALSE);
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyMain::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
   dc.Ellipse (5,0,250,150);
	// Do not call CDialog::OnPaint() for painting messages
}
