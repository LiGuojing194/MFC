// PriorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "QQ.h"
#include "PriorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg dialog


CPriorDlg::CPriorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPriorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPriorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPriorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPriorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPriorDlg, CDialog)
	//{{AFX_MSG_MAP(CPriorDlg)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPriorDlg message handlers

void CPriorDlg::ReadUsers(CListCtrl *pList)
{//从文件中读取用户列表
	CFile file;
	if(!file.Open("./Users.dat",CFile::modeRead))
		return;
	SUser u;
	int i=0;
	while(file.Read(&u,sizeof(u)>0))
	{
		pList->InsertItem (i,u.sName);
		pList->SetItemText (i,1,u.sPass);
		pList->SetItemText (i,2,u.sPrior);
        ++i;
	}
	file.Close ();
}

BOOL CPriorDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn (0,"账号",0,100);
	pList->InsertColumn (1,"密码",0,100);
	pList->InsertColumn (2,"权限",0,100);

	CComboBox*pComb=(CComboBox*)GetDlgItem(IDC_PRIOR);
	pComb->AddString ("普通");
	pComb->AddString ("高级");
    pComb->SetCurSel (0);
	ReadUsers(pList);

    	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPriorDlg::OnDestroy() 
{//在权限对话框关闭时自动保存用户列表
	CDialog::OnDestroy();
	CFile file;
	if(!file.Open("./Users.dat",CFile::modeCreate|CFile::modeRead))
		return;
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int i=0,nCount=pList->GetItemCount ();
	SUser u;
	while(i<nCount)
	{
	   pList->GetItemText (i,0,u.sName ,sizeof(u.sName ));
	   pList->GetItemText (i,1,u.sPass ,sizeof(u.sPass));
	   pList->GetItemText (i,2,u.sPrior ,sizeof(u.sPrior ));
	   file.Write (&u,sizeof(u));
       i++;
	}
file.Close ();
	
}

void CPriorDlg::OnAdd() 
{
SUser u;
GetDlgItemText(IDC_NAME,u.sName ,sizeof(u.sName ));
//账户登录时不区分大小写	
strlwr(u.sName );
CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
int i=0,nCount=pList->GetItemCount ();
while(i<nCount)
{
if(pList->GetItemText (i,0)==u.sName )
{
CString str;
str.Format("用户\"%s\"已经存在！",u.sName);
AfxMessageBox(str);
return;
}
i++;
}
GetDlgItemText(IDC_PASS,u.sPass ,sizeof(u.sPass ));
GetDlgItemText(IDC_PRIOR,u.sPrior ,sizeof(u.sPrior));
pList->InsertItem (nCount,u.sName );
pList->SetItemText (nCount,1,u.sPass );
pList->SetItemText (nCount,2,u.sPrior );

}

void CPriorDlg::OnDel() 
{
CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
POSITION pos=pList->GetFirstSelectedItemPosition ();
int nSel=pList->GetNextSelectedItem (pos);
if(nSel<0)
{
AfxMessageBox("请选择一个用户再删除！");
return;
}	
//保留一个超级管理用户名
CString szName=pList->GetItemText(nSel,0);
if(szName=="admin")
return;
CString str;
str.Format ("确定删除帐号\"%s\"吗？",szName);
if(AfxMessageBox(str,MB_YESNO)==IDYES)
pList->DeleteItem (nSel);
}

void CPriorDlg::OnMod() 
{
CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
POSITION pos=pList->GetFirstSelectedItemPosition();
int nSel=pList->GetNextSelectedItem(pos);
if(nSel<0)
{
	AfxMessageBox("请选择一个用户再修改！");
	return;
}
SUser u;
GetDlgItemText(IDC_PASS,u.sPass,sizeof(u.sPass));
pList->SetItemText(nSel,1,u.sPass );
CString szName=pList->GetItemText (nSel,0);
//如果是admin账户则只允许修改密码
if(szName=="admin")
return;
GetDlgItemText(IDC_PRIOR,u.sPrior ,sizeof(u.sPrior ));
pList->SetItemText (nSel,2,u.sPrior );
}
