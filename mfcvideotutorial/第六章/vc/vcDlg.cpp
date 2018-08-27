// vcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vc.h"
#include "vcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVcDlg dialog

CVcDlg::CVcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVcDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_DEPT, m_combo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVcDlg, CDialog)
	//{{AFX_MSG_MAP(CVcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVcDlg message handlers

BOOL CVcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_list.InsertColumn(0,"工号",0,100);
	m_list.InsertColumn(1,"姓名",0,100);
    m_list.InsertColumn(2,"部门",0,100);
    m_combo.AddString("请选择部门");
	m_combo.AddString("行政部");
	m_combo.AddString("财务部");
	m_combo.AddString("市场部");
	m_combo.AddString("测试部");
	m_combo.AddString("开发部");
    m_combo.SetCurSel(0);
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

void CVcDlg::OnPaint() 
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
HCURSOR CVcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVcDlg::OnAdd() 
{
  int nSel=m_combo.GetCurSel ();
  if(!nSel)
  {
    AfxMessageBox("请选择部门再添加！");
	return;
  }
 CString str;
 GetDlgItemText(IDC_NUMB,str);
 int nCount=m_list.GetItemCount ();
 m_list.InsertItem(nCount,str);
 GetDlgItemText(IDC_NAME,str);
 m_list.SetItemText (nCount,1,str);
 m_combo.GetLBText (nSel,str);
 m_list.SetItemText (nCount,2,str);
}

void CVcDlg::OnDel() 
{
POSITION pos=m_list.GetFirstSelectedItemPosition ();
int nSel=m_list.GetNextSelectedItem(pos);
if(nSel<0)
{
	AfxMessageBox("请选择列表中的一条消息再删除！");
	return;
}
CString str=m_list.GetItemText (nSel,0);
str="确定要删除"+str;
str+="号信息吗？";
if(AfxMessageBox(str,MB_YESNO)==IDYES)
   m_list.DeleteItem (nSel);
}

void CVcDlg::OnMod() 
{
  POSITION pos=m_list.GetFirstSelectedItemPosition ();
  int nSel=m_list.GetNextSelectedItem (pos);
  if(nSel<0)
  {
     AfxMessageBox("请选择列表中的一条信息再修改！");
	 return;
  }
  CString str=m_list.GetItemText (nSel,0);
  str="确定要修改"+str;
  str+="号信息吗？";
  if(AfxMessageBox(str,MB_YESNO)==IDNO)
	  return;
  GetDlgItemText(IDC_NAME,str);
  m_list.SetItemText (nSel,1,str);
  GetDlgItemText(IDC_DEPT,str);
  m_list.SetItemText(nSel,2,str);

}
