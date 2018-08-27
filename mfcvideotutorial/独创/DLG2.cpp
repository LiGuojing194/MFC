// DLG2.cpp : implementation file
//

#include "stdafx.h"
#include "¶À´´.h"
#include "DLG2.h"
#include"DLG3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG2 dialog


DLG2::DLG2(CWnd* pParent /*=NULL*/)
	: CDialog(DLG2::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLG2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLG2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG2, CDialog)
	//{{AFX_MSG_MAP(DLG2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG2 message handlers

BOOL DLG2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	SetTimer(2,5000,NULL);
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DLG2::OnTimer(UINT nIDEvent) 
{
	KillTimer(2);
	DLG3 dlg2;
	dlg2.DoModal();
	CDialog::OnOK();
	
	CDialog::OnTimer(nIDEvent);
}
