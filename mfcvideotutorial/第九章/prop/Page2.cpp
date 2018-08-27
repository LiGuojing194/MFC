// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "prop.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 property page

IMPLEMENT_DYNCREATE(CPage2, CPropertyPage)

CPage2::CPage2() : CPropertyPage(CPage2::IDD)
{
	//{{AFX_DATA_INIT(CPage2)
	m_nBlood = -1;
	m_szHome = _T("");
	m_nbirth = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
	DDX_CBIndex(pDX, IDC_BLOOD, m_nBlood);
	DDX_Text(pDX, IDC_HOME, m_szHome);
	DDX_DateTimeCtrl(pDX, IDC_BIRTH, m_nbirth);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CPropertyPage)
	//{{AFX_MSG_MAP(CPage2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

BOOL CPage2::OnSetActive() 
{//在切换到第2个页时，激活“上一页”和“下一页”按钮
    CPropertySheet*pSh=(CPropertySheet*)GetParent();
	pSh->SetWizardButtons (PSWIZB_BACK|PSWIZB_NEXT); 
	
	
	return CPropertyPage::OnSetActive();
}
