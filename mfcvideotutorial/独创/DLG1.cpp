// DLG1.cpp : implementation file
//

#include "stdafx.h"
#include "¶À´´.h"
#include "DLG1.h"
#include"DLG2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG1 dialog


DLG1::DLG1(CWnd* pParent /*=NULL*/)
	: CDialog(DLG1::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLG1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLG1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG1, CDialog)
	//{{AFX_MSG_MAP(DLG1)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG1 message handlers

void DLG1::OnOK() 
{
	KillTimer(1);
	DLG2 dlg2;
	dlg2.DoModal ();
	//DestroyWindow();
	CDialog::OnOK();
}

BOOL DLG1::OnInitDialog() 
{
	SetTimer(1,250,NULL);
    CDialog::OnInitDialog();
	HWND hWnd1=::GetDlgItem(m_hWnd,IDC_BUTTON1);
	HWND hWnd2=::GetDlgItem(m_hWnd,IDC_BUTTON2);
	HWND hWnd3=::GetDlgItem(m_hWnd,IDC_BUTTON3);
	m_edit1.Attach(hWnd1);
	m_edit2.Attach(hWnd2);
	m_edit3.Attach (hWnd3);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HBRUSH DLG1::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}


void DLG1::OnTimer(UINT nIDEvent) 
{
    CRect Rect1,Rect2,Rect3;
	m_edit1.GetWindowRect(Rect1);
	ScreenToClient(Rect1);
	Rect1.OffsetRect (9,11);
    m_edit2.GetWindowRect(Rect2);
	ScreenToClient(Rect2);
	Rect2.OffsetRect (9,11);
	m_edit3.GetWindowRect(Rect3);
	ScreenToClient(Rect3);
	Rect3.OffsetRect (-5,0);
	CRect rRect1,rRect2,rRect3;
	GetClientRect(rRect1);
	if(Rect1.right>rRect1.right)
		Rect1.OffsetRect(-Rect1.left ,0);
    GetClientRect(rRect2);
	if(Rect2.right>rRect2.right)
		Rect2.OffsetRect(-Rect2.left,0);
	if(Rect2.bottom>rRect2.bottom-80)
		Rect2.OffsetRect(0,-Rect2.bottom );
	if(Rect1.bottom>rRect1.bottom-80)
		Rect1.OffsetRect(0,-rRect1.bottom );
	GetClientRect(rRect3);
	if(Rect3.left<rRect3.left)
		Rect3.OffsetRect(Rect3.right-30,0);
	m_edit1.MoveWindow (Rect1);
	m_edit2.MoveWindow(Rect2);
	m_edit3.MoveWindow (Rect3);
	CDialog::OnTimer(nIDEvent);
}

void DLG1::OnDestroy() 
{
	CDialog::OnDestroy();
	
    m_edit1.Detach ();
	m_edit2.Detach ();
	m_edit3.Detach ();
}
