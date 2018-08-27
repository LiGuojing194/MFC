// Page3.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "Page3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3 dialog


CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CDialog(CPage3::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage3)
	m_szAdd = _T("");
	m_szEmail = _T("");
	m_szTel = _T("");
	//}}AFX_DATA_INIT
}


void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3)
	DDX_Text(pDX, IDC_ADDR, m_szAdd);
	DDX_Text(pDX, IDC_EMAIL, m_szEmail);
	DDX_Text(pDX, IDC_TEL, m_szTel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3, CDialog)
	//{{AFX_MSG_MAP(CPage3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3 message handlers
