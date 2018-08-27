// ModDlg.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "ModDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModDlg dialog


CModDlg::CModDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CModDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModDlg)
	DDX_Control(pDX, IDC_TAB, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModDlg, CDialog)
	//{{AFX_MSG_MAP(CModDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, OnSelchangeTab)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModDlg message handlers

BOOL CModDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_tab.InsertItem (0,"基本资料");
	m_tab.InsertItem (1,"更多资料");
	m_tab.InsertItem (2,"联系方式");
	//获取Tab控件中央区域
	CRect rect,rt;
	m_tab.GetWindowRect (rect);
	ScreenToClient(rect);
	m_tab.GetItemRect(0,rt);
	rect.top +=rt.Height ()+2;
	//四周向中央缩进2排序，露出Tab边缘
	rect.DeflateRect(2,2);
	//四周向中央创建三个子页窗口
    m_p1.Create(IDD_PAGE1,this);
	m_p1.MoveWindow (rect);
    m_p2.Create(IDD_PAGE2,this);
	m_p2.MoveWindow (rect);
    m_p3.Create(IDD_PAGE3,this);
	m_p3.MoveWindow (rect);
   //并显示第一页
	m_p1.ShowWindow(SW_SHOW);
	m_p1.SetFocus ();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CModDlg::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
  int nSel=m_tab.GetCurSel();
  CWnd*ps[]={&m_p1,&m_p2,&m_p3};
  int i=0;
  while(i<sizeof(ps)/sizeof(ps[0]))
	  ps[i++]->ShowWindow (i==nSel?SW_SHOW:SW_HIDE);
  ps[nSel]->SetFocus ();
	*pResult = 0;
}

void CModDlg::OnOK() 
{
int i=0;
CWnd*ps[]={&m_p1,&m_p2,&m_p3};
while(i<sizeof(ps)/sizeof(ps[0]))
ps[i++]->UpdateData();
	CDialog::OnOK();
}
