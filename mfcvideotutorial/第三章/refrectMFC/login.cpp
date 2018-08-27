// login.cpp : implementation file
//

#include "stdafx.h"
#include "refrectMFC.h"
#include "login.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// login dialog


login::login(CWnd* pParent /*=NULL*/)
	: CDialog(login::IDD, pParent)
{
	//{{AFX_DATA_INIT(login)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(login)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(login, CDialog)
	//{{AFX_MSG_MAP(login)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// login message handlers

void login::OnOK() 
{
    CString szHappy;
	GetDlgItemText(IDC_LOGIN,szHappy);
	if(szHappy=="jiaoyuhebeiyou")
	CDialog::OnOK();
	else
	{
	MessageBox("答案错误！请重新输入！","温馨提示",MB_OK|MB_ICONWARNING);
	SetDlgItemText(IDC_LOGIN,"");
	GetDlgItem(IDC_LOGIN)->SetFocus();
	}
}
