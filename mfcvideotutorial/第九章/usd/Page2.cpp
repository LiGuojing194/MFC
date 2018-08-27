// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog


CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialog(CPage2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage2)
	m_birth = COleDateTime::GetCurrentTime();
	m_nBlood = -1;
	m_szHome = _T("");
	//}}AFX_DATA_INIT
}


void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
	DDX_DateTimeCtrl(pDX, IDC_BIRTH, m_birth);
	DDX_CBIndex(pDX, IDC_BLOOD, m_nBlood);
	DDX_Text(pDX, IDC_HOME, m_szHome);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CDialog)
	//{{AFX_MSG_MAP(CPage2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

void CPage2::OnOK() 
{
	GetParent()->PostMessage (WM_COMMAND,IDOK);

}

void CPage2::OnCancel() 
{
		GetParent()->PostMessage (WM_COMMAND,IDCANCEL);

}
