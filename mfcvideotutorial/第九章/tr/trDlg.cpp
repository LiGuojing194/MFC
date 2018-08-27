// trDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tr.h"
#include "trDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrDlg dialog

CTrDlg::CTrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrDlg)
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrDlg, CDialog)
	//{{AFX_MSG_MAP(CTrDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelchangedTree)
	ON_EN_CHANGE(IDC_SALA, OnChangeSala)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, OnItemchangedList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrDlg message handlers

BOOL CTrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_bFlag=FALSE;
	m_list.InsertColumn(0,"工号",0,80);
	m_list.InsertColumn(1,"姓名",0,80);
	m_list.InsertColumn(2,"工资",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);	
	HTREEITEM hRoot=m_tree.InsertItem ("总公司");
	HTREEITEM hItem=m_tree.InsertItem ("baojy.com",hRoot);
    m_tree.InsertItem ("行政部",hItem);
	m_tree.InsertItem ("市场部",hItem);
	m_tree.InsertItem ("就业部",hItem);
	m_tree.Expand(hRoot,TVE_EXPAND);
	m_tree.Expand(hItem,TVE_EXPAND);
    hItem=m_tree.InsertItem ("richmain.net",hRoot);
	m_tree.InsertItem ("行政部",hItem);
    m_tree.InsertItem ("人事部",hItem);
    m_tree.InsertItem ("开发部",hItem);
    m_tree.InsertItem ("财务部",hItem);
    m_tree.Expand(hItem,TVE_EXPAND);




	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
int CTrDlg::GetDepth (HTREEITEM hItem)
{
  int i=0;
  while(hItem)
  {
     hItem=m_tree.GetParentItem (hItem);
	 ++i;
  }
  return i;
}
CString CTrDlg::GetPath(HTREEITEM hItem)
{
   CString str;
   while(hItem)
   {
      str=m_tree.GetItemText(hItem)+"\\"+str;
	  hItem=m_tree.GetParentItem(hItem);
   }
   return str;
}
void CTrDlg::Load()
{
   m_list.DeleteAllItems ();
   HTREEITEM hItem=m_tree.GetSelectedItem();
   int nDep=GetDepth(hItem);
   if(nDep<3)
       return;
   CString szPath=GetPath(hItem);
   CFile file;
   if(!file.Open(szPath+"memb.dat",CFile::modeRead))
	   return;
   SInfo info;
   int i=0;
   CString str;
   while(file.Read(&info,sizeof(info))>0)
   {
      str.Format("%d",info.nNumb);
	  m_list.InsertItem (i,str);
	  m_list.SetItemText (i,1,info.sName );
	  str.Format ("%0.2f",info.fSala );
	  m_list.SetItemText (i,2,str );
	  i++;

   }
   
}

BOOL CTrDlg::MakeDir (CString &szPath)
{
  int i=0;
  while((i=szPath.Find('\\',i))>0)
	  CreateDirectory(szPath.Left(i++),NULL);
  return TRUE;

}

void CTrDlg::OnAdd() 
{
CString str;
int i=0;
int nCount=m_list.GetItemCount();
GetDlgItemText(IDC_NUMB,str);
while(i<nCount)
{//检查工号是否存在
   if(m_list.GetItemText(i,0)==str)
   {
     AfxMessageBox("工号已存在！");
	 return;

   }
   ++i;

}
m_list.InsertItem (i,str);
GetDlgItemText(IDC_NAME,str);
m_list.SetItemText (i,1,str);
GetDlgItemText(IDC_SALA,str);
m_list.SetItemText (i,2,str);
m_bFlag=TRUE;
}

void CTrDlg::OnSave() 
{
  CString szPath;
  GetDlgItemText(IDC_PATH,szPath);
  CString szFile=szPath+"memb.dat";
  CFileFind ff;
  if(!ff.FindFile (szFile))
	  MakeDir(szPath);
  CFile file;
  if(!file.Open(szFile,CFile::modeCreate|CFile::modeWrite))
  {
     AfxMessageBox("保存时出错！");
	 return;
  }
  int i=0,nCount=m_list.GetItemCount ();
  SInfo info;
  while(i<nCount)
  {
     info.nNumb =atoi(m_list.GetItemText (i,0));
	 m_list.GetItemText(i,1,info.sName ,sizeof(info.sName ));
	 info.fSala =(float)atof(m_list.GetItemText(i,2));
	 file.Write (&info,sizeof(info));
	 ++i;
  }
  m_bFlag=FALSE;
}
void CTrDlg::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* p= (NM_TREEVIEW*)pNMHDR;
    HTREEITEM hItem=p->itemNew.hItem;
	int nDep=GetDepth(hItem);
	GetDlgItem(IDC_ADD)->EnableWindow(nDep==3);
	GetDlgItem(IDC_DEL)->EnableWindow(nDep==3);
	GetDlgItem(IDC_SAVE)->EnableWindow(nDep==3);
	if(m_bFlag)
    {
	   if(IDYES==AfxMessageBox("列表数据已经更改好，是否保存？",
		   MB_YESNO|MB_ICONQUESTION))
		   OnSave();
	   m_bFlag=FALSE;
	}
    SetDlgItemText(IDC_PATH,GetPath(hItem));
	Load();
	*pResult = 0;
}

void CTrDlg::OnChangeSala() 
{//获取新编辑的文字中，如果有非数字则进行清理
	CString szText;
	GetDlgItemText(IDC_SALA,szText);
	CEdit*pEdit=(CEdit*)GetDlgItem(IDC_SALA);
	int nStart,nEnd;
	pEdit->GetSel(nStart,nEnd);
	int i=szText.GetLength();
	BOOL bFlag=FALSE;//文字清理过的标志
	while(i--)
	{
	   char c=szText[i];
	   if(c=='.')  continue;
	   if(c>='0'&&c<='9')    continue;
	   szText.Delete (i);
	   bFlag=TRUE;
	}
    if(bFlag)
	{
	   SetDlgItemText(IDC_SALA,szText);
	   pEdit->SetSel(nStart,nEnd);
	}
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CTrDlg::OnItemchangedList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* p= (NM_LISTVIEW*)pNMHDR;
    int nItem=p->iItem;
	if(nItem<0)
		return;
	CString str=m_list.GetItemText (nItem,0);
	SetDlgItemText(IDC_NUMB,str);
	str=m_list.GetItemText (nItem,1);
	SetDlgItemText(IDC_NAME,str);
	str=m_list.GetItemText (nItem,2);
	SetDlgItemText(IDC_SALA,str);
	*pResult = 0;
}
