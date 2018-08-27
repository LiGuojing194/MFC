// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "Page1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog


CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1)
	m_szName = _T("");
	m_szNumb = _T("");
	m_nSex = -1;
	//}}AFX_DATA_INIT
}


void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
	DDX_Text(pDX, IDC_NAME, m_szName);
	DDX_Text(pDX, IDC_NUMB, m_szNumb);
	DDX_Radio(pDX, IDC_SEX, m_nSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1, CDialog)
	//{{AFX_MSG_MAP(CPage1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

void CPage1::OnOK() 
{
	GetParent()->PostMessage (WM_COMMAND,IDOK);

}

void CPage1::OnCancel() 
{
			GetParent()->PostMessage (WM_COMMAND,IDCANCEL);

}
