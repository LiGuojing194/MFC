// Page3.cpp : implementation file
//

#include "stdafx.h"
#include "prop.h"
#include "Page3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3 property page

IMPLEMENT_DYNCREATE(CPage3, CPropertyPage)

CPage3::CPage3() : CPropertyPage(CPage3::IDD)
{
	//{{AFX_DATA_INIT(CPage3)
	m_szEmail = _T("");
	m_szTel = _T("");
	m_szAdd = _T("");
	//}}AFX_DATA_INIT
}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3)
	DDX_Text(pDX, IDC_EMAIL, m_szEmail);
	DDX_Text(pDX, IDC_TEL, m_szTel);
	DDX_Text(pDX, IDC_ADDR, m_szAdd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3, CPropertyPage)
	//{{AFX_MSG_MAP(CPage3)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3 message handlers

BOOL CPage3::OnSetActive() 
{
    CPropertySheet*pSh=(CPropertySheet*)GetParent();
	pSh->SetWizardButtons (PSWIZB_BACK|PSWIZB_FINISH); 
		
	return CPropertyPage::OnSetActive();
}
