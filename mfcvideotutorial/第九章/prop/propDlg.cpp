// propDlg.cpp : implementation file
//

#include "stdafx.h"
#include "prop.h"
#include "propDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropDlg dialog

CPropDlg::CPropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPropDlg, CDialog)
	//{{AFX_MSG_MAP(CPropDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropDlg message handlers

BOOL CPropDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.InsertColumn(0,"帐号",0,80);
	m_list.InsertColumn(1,"昵称",0,80);
	m_list.InsertColumn(2,"性别",0,60);
	m_list.InsertColumn(3,"生日",0,80);
	m_list.InsertColumn(4,"血型",0,80);
	m_list.InsertColumn(5,"故乡",0,80);
	m_list.InsertColumn(6,"电话",0,80);
	m_list.InsertColumn(7,"电邮",0,80);
	m_list.InsertColumn(8,"地址",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	



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

void CPropDlg::OnPaint() 
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
HCURSOR CPropDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"
void CPropDlg::OnAdd() 
{
	CPage1 p1;
	CPage2 p2;
	CPage3 p3;
	CPropertySheet sh;
	sh.AddPage(&p1);
	sh.AddPage(&p2);
	sh.AddPage (&p3);
	sh.SetWizardMode ();
	if(IDCANCEL==sh.DoModal())
		return;
    CString str;
	int i=m_list.GetItemCount();
	m_list.InsertItem(i,p1.m_szNumb);
	m_list.SetItemText(i,1,p1.m_szName );
	m_list.SetItemText(i,2,p1.m_nSex==0?"男":"女");
	COleDateTime time=p2.m_nbirth ;
	str.Format ("%d-%02d-%02d",time.GetYear (),time.GetMonth(),time.GetDay ());
	m_list.SetItemText(i,3,str);
	LPCSTR ps[]={"A","B","O","AB","其他"};
	m_list.SetItemText(i,4,ps[p2.m_nBlood ]);
	m_list.SetItemText(i,5,p2.m_szHome );
	m_list.SetItemText(i,6,p3.m_szTel );
	m_list.SetItemText(i,7,p3.m_szEmail );
	m_list.SetItemText(i,8,p3.m_szAdd );
}

void CPropDlg::OnMod() 
{
   int nSel=m_list.GetSelectionMark ();
   if(nSel<0)
   {
       AfxMessageBox("请选择一行再修改");
	   return;
   }
   CString str;
   CPage1 p1;
   CPage2 p2;
   CPage3 p3;
   CPropertySheet sh("修改资料");
   sh.AddPage (&p1);
   sh.AddPage (&p2);
   sh.AddPage (&p3);
   p1.m_szNumb=m_list.GetItemText (nSel,0);
   p1.m_szName=m_list.GetItemText (nSel,1);
   str=m_list.GetItemText (nSel,2);
   p1.m_nSex =str=="女";
   str=m_list.GetItemText (nSel,3);
   p2.m_nbirth.ParseDateTime(str,VAR_DATEVALUEONLY);
   str=m_list.GetItemText (nSel,4);
   LPCSTR ps[]={"A","B","O","AB","其他"};
   int i=-1;
   while(++i<sizeof(ps)/sizeof(ps[0]))
	   if(ps[i]==str)
		   break;
	   p2.m_nBlood =i;
	   p2.m_szHome =m_list.GetItemText (nSel,5);
	   p3.m_szTel =m_list.GetItemText (nSel,6);
       p3.m_szEmail =m_list.GetItemText (nSel,7);
	   p3.m_szAdd =m_list.GetItemText (nSel,8);
	   //在弹出对话框前，将选中列表项内的数据全部传入各个分页
	   if(IDCANCEL==sh.DoModal ())
		   return;
	   //对话框确定之后，将修改后的各个分页的数据再覆盖回选中列表项
	   m_list.SetItemText (nSel,0,p1.m_szNumb );
	   m_list.SetItemText (nSel,1,p1.m_szName );
	   m_list.SetItemText (nSel,2,p1.m_nSex==0?"男":"女");
	   COleDateTime time=p2.m_nbirth;
	   str.Format ("%d-%02d-%02d",time.GetYear(),time.GetMonth (),time.GetDay ());
	   m_list.SetItemText (nSel,3,str);
	   m_list.SetItemText (nSel,4,ps[p2.m_nBlood]);
	   m_list.SetItemText (nSel,5,p2.m_szHome );
	   m_list.SetItemText (nSel,6,p3.m_szTel );
       m_list.SetItemText (nSel,7,p3.m_szEmail );
	   m_list.SetItemText (nSel,8,p3.m_szAdd );


}

void CPropDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   OnMod();//双击列表项进行修改
	
	*pResult = 0;
}
