// login.cpp : implementation file
//��֪��Ϊʲô�����û���������ʱ����Ҳ��֪��ΪʲôȨ����û������ѡ�������



#include "stdafx.h"
#include "QQ.h"
#include "login.h"
#include"QQDlg.h"

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

BOOL login::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void login::OnOK() 
{
	//	CQQDlg dlg;
	CString szName,szPass;
	GetDlgItemText(IDC_NAME,szName);
	GetDlgItemText(IDC_PASS,szPass);	
	szName.MakeLower ();//�û��������ִ�Сд
	//	CDialog::OnOK();
	//	return;
	if(CheckUser(szName,szPass))
	{//���������ͨ����رյ�¼�Ի���
		CDialog::OnOK();
		//	dlg.DoModal ();
		return;
	}
	AfxMessageBox("�˺Ż�����������������룡");
	SetDlgItemText(IDC_NAME,"");
	SetDlgItemText(IDC_PASS,"");
	GetDlgItem(IDC_NAME)->SetFocus();
	
}
extern CQQApp  theApp;
BOOL login::CheckUser(CString szName, CString szPass)
{
	CFile file;
	if(!file.Open ("./Users.dat",CFile::modeRead))
	{
		CreateUser();//����û��ļ��������򴴽��ļ��������´�
		if(!file.Open ("./Users.dat",CFile::modeRead))
			return FALSE;
	}
	//�ѵ�¼�û���¼��theApp.m_user��
	SUser &u=theApp.m_user ;
	while(file.Read (&u,sizeof(u))>0)
	{
		if(szName==u.sName )
			return  szPass==u.sPass ;
	 }
	file.Close ();
	return  FALSE;
}




void login::CreateUser()
{
	CFile file;
	if(!file.Open ("./User.dat",CFile::modeCreate|CFile::modeWrite))
		return;
	SUser u={"admin","admin","�߼�"};
	file.Write(&u,sizeof(u));
	file.Close ();
}
