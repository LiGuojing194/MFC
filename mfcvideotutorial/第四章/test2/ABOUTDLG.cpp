// ABOUTDLG.cpp : implementation file
//

#include "stdafx.h"
#include "test2.h"
#include "ABOUTDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ABOUTDLG dialog


ABOUTDLG::ABOUTDLG(CWnd* pParent /*=NULL*/)
	: CDialog(ABOUTDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(ABOUTDLG)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ABOUTDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ABOUTDLG)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ABOUTDLG, CDialog)
	//{{AFX_MSG_MAP(ABOUTDLG)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ABOUTDLG message handlers
