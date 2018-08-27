// vdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vd.h"
#include "vdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVdDlg dialog

CVdDlg::CVdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVdDlg)
	m_bEngl = TRUE;
	m_bJapa = FALSE;
	m_dtJoin = COleDateTime::GetCurrentTime();
	m_bKorea = FALSE;
	m_szName = _T("");
	m_szNumb = _T("");
	m_bRuss = FALSE;
	m_nSex = 0;
	m_nEduca = 1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVdDlg)
	DDX_Control(pDX, IDC_DEL, m_del);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Check(pDX, IDC_ENGL, m_bEngl);
	DDX_Check(pDX, IDC_JAPA, m_bJapa);
	DDX_DateTimeCtrl(pDX, IDC_JOIN, m_dtJoin);
	DDX_Check(pDX, IDC_KOREA, m_bKorea);
	DDX_Text(pDX, IDC_NAME, m_szName);
	DDX_Text(pDX, IDC_NUMB, m_szNumb);
	DDX_Check(pDX, IDC_RUSS, m_bRuss);
	DDX_Radio(pDX, IDC_SEX, m_nSex);
	DDX_Radio(pDX, IDC_EDUCATION, m_nEduca);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVdDlg, CDialog)
	//{{AFX_MSG_MAP(CVdDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVdDlg message handlers

BOOL CVdDlg::OnInitDialog()
{
	//m_list.SetBkColor (RGB(255,255,0));
	CDialog::OnInitDialog();
    m_list.SetBkColor (RGB(255,255,0));
    m_list.SetTextColor (RGB(0,0,255));
	m_list.SetTextBkColor (RGB(0,255,0));
    m_add.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON1));//????????????????????????????????????????????
//	m_add.SetIcon (::LoadIcon (hInstance,IDI_ICON1));
	//m_del.SetBitmap (LoadImage(NULL,IDB_BITMAP1));//？??????如何成功加载位图？
    m_list.InsertColumn (0,"工号",0,80);
    m_list.InsertColumn (1,"姓名",0,80);
    m_list.InsertColumn (2,"性别",0,60);
    m_list.InsertColumn (3,"学历",0,80);
    m_list.InsertColumn (4,"入职",0,80);
    m_list.InsertColumn (5,"外语",0,80);
	m_list.SetExtendedStyle (LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

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

void CVdDlg::OnPaint() 
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
HCURSOR CVdDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVdDlg::OnAdd() 
{
UpdateData();
int nCount=m_list.GetItemCount ();
m_list.InsertItem (nCount,m_szNumb);
m_list.SetItemText (nCount,1,m_szName);
m_list.SetItemText (nCount,2,m_nSex?"女":"男");
char*p[]={"高中","大学","硕士","博士"};
m_list.SetItemText (nCount,3,p[m_nEduca]);
CString str;
if(m_bEngl)str+="英";
if(m_bJapa)str+="日";
if(m_bKorea)str+="韩";
if(m_bRuss)str+="俄";
if(str.IsEmpty ())str+="无";
m_list.SetItemText (nCount,5,str);
str.Format ("%d-%d-%d",m_dtJoin.GetYear (),m_dtJoin.GetMonth (),m_dtJoin.GetDay ());
m_list.SetItemText (nCount,4,str);
}

void CVdDlg::OnDel() 
{
 POSITION pos=m_list.GetFirstSelectedItemPosition();
 if(!pos)
 {
    AfxMessageBox("请选择一行再删除！");
	return;

 }
 int nSel=m_list.GetNextSelectedItem(pos);
 CString str=m_list.GetItemText(nSel,0);
 str="确认删除"+str+"号信息吗？";
 if(AfxMessageBox(str,MB_YESNO)==IDYES)
	 m_list.DeleteItem(nSel);
}

void CVdDlg::OnMod() 
{
POSITION pos=m_list.GetFirstSelectedItemPosition();
if(!pos)
{
  AfxMessageBox("请选择一行再修改！");
  return;
}	
int nSel=m_list.GetNextSelectedItem(pos);
UpdateData();
int nCount=m_list.GetItemCount();
m_list.SetItemText(nSel,0,m_szNumb);
m_list.SetItemText (nSel,1,m_szName);
m_list.SetItemText(nSel,2,m_nSex?"女":"男");
char*p[]={"高中","大学","硕士","博士"};
m_list.SetItemText (nSel,3,p[m_nEduca]); 
CString str;
if(m_bEngl)str+="英";
if(m_bJapa)str+="日";
if(m_bKorea)str+="韩";
if(m_bRuss)str+="俄";
if(str.IsEmpty ())str+="无";
m_list.SetItemText(nSel,5,str);
str.Format ("%d-%d-%d",m_dtJoin.GetYear (),m_dtJoin.GetMonth(),m_dtJoin.GetDay ());
m_list.SetItemText(nSel,4,str);
}

BOOL CVdDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	switch(pWnd->GetDlgCtrlID ())
	{
	case IDC_ADD:
		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_HELP));
		return TRUE;
	case IDC_LIST:
		SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
		return TRUE;

	}
	
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
