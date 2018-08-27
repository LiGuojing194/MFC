// DLG5.cpp : implementation file
//

#include "stdafx.h"
#include "¶À´´.h"
#include "DLG5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DLG5 dialog


DLG5::DLG5(CWnd* pParent /*=NULL*/)
	: CDialog(DLG5::IDD, pParent)
{
	//{{AFX_DATA_INIT(DLG5)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DLG5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DLG5)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DLG5, CDialog)
	//{{AFX_MSG_MAP(DLG5)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DLG5 message handlers
