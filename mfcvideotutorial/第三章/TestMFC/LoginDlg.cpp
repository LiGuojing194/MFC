// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestMFC.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
    CString szName,szPass;
	GetDlgItemText(IDC_NAME,szName);
	GetDlgItemText(IDC_PASS,szPass);
    if(szName=="favorite"&&szPass=="1014904827")
	CDialog::OnOK();
	else
	{
		AfxMessageBox("�û����������������");
		SetDlgItemText(IDC_NAME,"");
        SetDlgItemText(IDC_PASS,"");
	//	GetDlgItem(IDC_NAME);��ȡ�ؼ���ָ��
		GetDlgItem(IDC_NAME)->SetFocus();


	}
}
