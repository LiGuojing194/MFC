// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "prop.h"
#include "Page1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 property page

IMPLEMENT_DYNCREATE(CPage1, CPropertyPage)

CPage1::CPage1() : CPropertyPage(CPage1::IDD)
{
	//{{AFX_DATA_INIT(CPage1)
	m_szName = _T("");
	m_szNumb = _T("");
	m_nSex = -1;
	//}}AFX_DATA_INIT
}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
	DDX_Text(pDX, IDC_NAME, m_szName);
	DDX_Text(pDX, IDC_NUMB, m_szNumb);
	DDX_Radio(pDX, IDC_SEX, m_nSex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1, CPropertyPage)
	//{{AFX_MSG_MAP(CPage1)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

BOOL CPage1::OnSetActive() 
{//在切换到第一页时，禁用“上一步”按钮
	CPropertySheet*pSh=(CPropertySheet*)GetParent();
	pSh->SetWizardButtons (PSWIZB_NEXT); 
	
	return CPropertyPage::OnSetActive();
}
