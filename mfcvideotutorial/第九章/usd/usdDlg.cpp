// usdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "usd.h"
#include "usdDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsdDlg dialog

CUsdDlg::CUsdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUsdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUsdDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUsdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUsdDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUsdDlg, CDialog)
	//{{AFX_MSG_MAP(CUsdDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, OnDblclkList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUsdDlg message handlers

BOOL CUsdDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_list.InsertColumn(0,"帐号",0,80);
	m_list.InsertColumn(1,"昵称",0,80);
	m_list.InsertColumn(2,"性别",0,80);
    m_list.InsertColumn(3,"生日",0,80);
	m_list.InsertColumn(4,"血型",0,80);
	m_list.InsertColumn(5,"故乡",0,80);
	m_list.InsertColumn(6,"电话",0,80);
	m_list.InsertColumn(7,"电邮",0,80);
	m_list.InsertColumn(8,"地址",0,80);
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUsdDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CUsdDlg::OnPaint() 
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
HCURSOR CUsdDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
#include"RegDlg.h"
//#include"Page1.h"
//#include"Page2.h"
//#include"Page3.h"

void CUsdDlg::OnAdd() 
{
	CRegDlg dlg;
	if(IDCANCEL==dlg.DoModal ())
        return;
	CString str;
	int i=m_list.GetItemCount ();
	m_list.InsertItem(i,dlg.m_p1 .m_szNumb);
	m_list.SetItemText (i,1,dlg.m_p1.m_szName );
	m_list.SetItemText (i,2,dlg.m_p1.m_nSex==0?"男":"女");
	COleDateTime time=dlg.m_p2 .m_birth ;
	str.Format ("%d-%02d-%02d",time.GetYear (),time.GetMonth (),time.GetDay ());
	m_list.SetItemText(i,3,str);

	char*ps[]={"A","B","0","AB","其他"};
	m_list.SetItemText (i,4,ps[dlg.m_p2 .m_nBlood]);
	m_list.SetItemText (i,5,dlg.m_p2 .m_szHome);
	m_list.SetItemText (i,6,dlg.m_p3 .m_szTel);
	m_list.SetItemText (i,7,dlg.m_p3 .m_szEmail);
	m_list.SetItemText (i,8,dlg.m_p3 .m_szAdd );

    


	
}
#include"ModDlg.h"
void CUsdDlg::OnMod() 
{
	int nSel=m_list.GetSelectionMark();
	if(nSel<0)
	{
	  AfxMessageBox("请选择一行再修改");
	  return;
	}
	CString str;
	CModDlg dlg;
	dlg.m_p1.m_szNumb =m_list.GetItemText (nSel,0);
	dlg.m_p1.m_szName =m_list.GetItemText (nSel,1);
	str=m_list.GetItemText (nSel,2);
	dlg.m_p1 .m_nSex =str=="女";
	str=m_list.GetItemText (nSel,3);
	dlg.m_p2 .m_birth .ParseDateTime (str,VAR_DATEVALUEONLY);
	str=m_list.GetItemText (nSel,4);
	LPCSTR ps[]={"A","B","O","AB","其他"};
	int i=-1;
	while(++i<sizeof(ps)/sizeof(ps[0]))
		if(ps[i]==str)
			break;
		dlg.m_p2.m_nBlood=i;
	dlg.m_p2.m_szHome =m_list.GetItemText (nSel,5);
   	dlg.m_p3.m_szTel =m_list.GetItemText (nSel,6);
	dlg.m_p3.m_szEmail =m_list.GetItemText (nSel,7);
	dlg.m_p3.m_szAdd=m_list.GetItemText (nSel,8);
    //在弹出对话框之前，将选中列表项内的数据全部传入各个分页
	if(IDCANCEL==dlg.DoModal ())
         return;
	//对话框确定之后，将修改后的各个分页的数据再覆盖回选中列表项
	m_list.SetItemText(nSel,0,dlg.m_p1.m_szNumb );
	m_list.SetItemText(nSel,1,dlg.m_p1.m_szName);
	m_list.SetItemText(nSel,2,dlg.m_p1.m_nSex==0?"男":"女" );
	COleDateTime time=dlg.m_p2 .m_birth;
	str.Format ("%d-%02d-%02d",time.GetYear(),time.GetMonth (),time.GetDay ());
	m_list.SetItemText(nSel,4,ps[dlg.m_p2.m_nBlood ]);
	m_list.SetItemText(nSel,5,dlg.m_p2.m_szHome);
	m_list.SetItemText(nSel,6,dlg.m_p3.m_szTel);
	m_list.SetItemText(nSel,7,dlg.m_p3.m_szEmail);
	m_list.SetItemText(nSel,8,dlg.m_p3.m_szAdd);







	
}

void CUsdDlg::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
   OnMod();	
	*pResult = 0;
}
