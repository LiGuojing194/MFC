// myfirstMFCDlg.cpp : implementation file
//

#include "stdafx.h"
#include "myfirstMFC.h"
#include "myfirstMFCDlg.h"

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
// CMyfirstMFCDlg dialog

CMyfirstMFCDlg::CMyfirstMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyfirstMFCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyfirstMFCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyfirstMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyfirstMFCDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyfirstMFCDlg, CDialog)      //��Ϣӳ�亯��
	//{{AFX_MSG_MAP(CMyfirstMFCDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DEL, OnDel)
	ON_BN_CLICKED(IDC_MOD, OnMod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyfirstMFCDlg message handlers
//OnInitDialog��ʼ���Ի�����ϢWM_INITDIALOG���Ի���δ��ʾ������ʱ����׼������
BOOL CMyfirstMFCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);      //��ȡ�ؼ�ָ�����
	pList->InsertColumn(0,"���ţ�",LVCFMT_LEFT,120);
	pList->InsertColumn(1,"������",LVCFMT_LEFT,120);
	pList->InsertColumn(2,"���ʣ�",LVCFMT_LEFT,120);
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

void CMyfirstMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyfirstMFCDlg::OnPaint() 
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
HCURSOR CMyfirstMFCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyfirstMFCDlg::OnAdd() 
{
	CString szNumb,szName,szSala;
	GetDlgItemText(IDC_NUMB,szNumb);
	GetDlgItemText(IDC_NAME,szName);
	GetDlgItemText(IDC_SALA,szSala);
    CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int nCount=pList->GetItemCount();
	pList->InsertItem(nCount,szNumb);
	pList->SetItemText(nCount,1,szName);
	pList->SetItemText(nCount,2,szSala);
	// TODO: Add your control notification handler code here
	
}

void CMyfirstMFCDlg::OnDel() 
{
	// TODO: Add your control notification handler code here
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int nSel=pList->GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox("��ѡ���б��е�Ա��������ɾ��!");
	    return;
	}
	pList->DeleteItem(nSel);
}

void CMyfirstMFCDlg::OnMod() 
{
	// TODO: Add your control notification handler code here
	CListCtrl*pList=(CListCtrl*)GetDlgItem(IDC_LIST);
	int nSel=pList->GetSelectionMark();
	if(nSel<0)
	{
		AfxMessageBox("��ѡ���б��е�Ա���������޸�");
	    return;
	}
	CString szNumb,szName,szSala;
	GetDlgItemText(IDC_NUMB,szNumb);
	GetDlgItemText(IDC_NAME,szName);
	GetDlgItemText(IDC_SALA,szSala);
	pList->SetItemText(nSel,0,szNumb);
	pList->SetItemText(nSel,1,szName);
	pList->SetItemText(nSel,2,szSala);
}
