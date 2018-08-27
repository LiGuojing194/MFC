// Si1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Si1.h"
#include "Si1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSi1Dlg dialog

CSi1Dlg::CSi1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSi1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSi1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSi1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSi1Dlg)
	DDX_Control(pDX, IDC_NATION, m_comb);
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSi1Dlg, CDialog)
	//{{AFX_MSG_MAP(CSi1Dlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSi1Dlg message handlers
extern CSi1App theApp;
BOOL CSi1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	UINT nIDs[]={IDI_KOR,IDI_JAPAN,IDI_USA,IDI_CAN,IDI_UK};
	m_iList.Create (16,16,ILC_COLOR32|ILC_MASK,8,4);
	int i=0;
	while(i<sizeof(nIDs)/sizeof(nIDs[0]))
		m_iList.Add(theApp.LoadIcon (nIDs[i++]));
	m_list.SetImageList (&m_iList,LVSIL_SMALL);
	m_list.InsertColumn (0,"工号",0,120);
	m_list.InsertColumn (1,"姓名",0,100);
	m_list.InsertColumn (2,"国籍",0,100);
	m_comb.SetCurSel (0);
	m_hList.Create(16,16,ILC_COLOR32|ILC_MASK,2,4);
	CBitmap   b1,b2;//加载两张位图
    b1.LoadBitmap(IDB_ASCENT);
    b2.LoadBitmap(IDB_DESCENT);
    

	//添加到图像列表中，透明色指定白色
	m_hList.Add(&b1,RGB(255,255,255));
	m_hList.Add(&b2,RGB(255,255,255));
	CHeaderCtrl*pHeader=m_list.GetHeaderCtrl();
	pHeader->SetImageList(&m_hList);
	m_nCol=-1;
	m_bOrder=FALSE;
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

void CSi1Dlg::OnPaint() 
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
HCURSOR CSi1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSi1Dlg::OnAdd() 
{
  CString str;
  int nSel=m_comb.GetCurSel ();
  GetDlgItemText(IDC_NUMB,str);
  int i=m_list.GetItemCount ();
  m_list.InsertItem (i,str,nSel);//在插入列表项时插入图标索引
  GetDlgItemText(IDC_NAME,str);
  m_list.SetItemText (i,1,str);
  m_comb.GetLBText(nSel,str);
  m_list.SetItemText (i,2,str);
  

}

void CSi1Dlg::OnMod() 
{
   if(!m_list.GetSelectedCount ())
   {
      AfxMessageBox("请选择一条记录再修改");
	  return;
   }
   int nSel=m_list.GetSelectionMark ();
   CString str;    //一般编号不改变
   GetDlgItemText(IDC_NAME,str);
   m_list.SetItemText (nSel,1,str);
   LVITEM li={LVIF_IMAGE};//////
   li.iItem=nSel;
   li.iImage=m_comb.GetCurSel ();
   m_list.SetItem(&li);//修改时重新设置该行图标
   m_comb.GetLBText(li.iImage,str);
   m_list.SetItemText(nSel,2,str);
}
