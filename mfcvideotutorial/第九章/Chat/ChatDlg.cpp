// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"

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
// CChatDlg dialog

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatDlg)
	DDX_Control(pDX, IDC_HIST, m_hist);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialog)
	//{{AFX_MSG_MAP(CChatDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatDlg message handlers

BOOL CChatDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CHARFORMAT cf={sizeof(cf)};
	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_BOLD;
	cf.crTextColor=RGB(0,255,0);
	cf.yHeight=240;
	strcpy(cf.szFaceName,"隶书");
	m_hist.SetDefaultCharFormat (cf);
	m_hist.SetWindowText ("【系统】欢迎进入LQM聊天室");
	//追加文字
	int nLen=m_hist.GetTextLength();
    m_hist.SetSel (-1,-1);
	m_hist.ReplaceSel ("\r\n【提醒】警惕聊托，骗子，请勿透露联系方式！");
	//选择追加文字并设置字体
	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_BOLD|CFM_UNDERLINE;
	cf.dwEffects=CFE_UNDERLINE;
	strcpy(cf.szFaceName,"宋体");
	cf.yHeight=180;
	cf.crTextColor=RGB(255,0,0);
	m_hist.SetSel (nLen,-1);
	m_hist.SetWordCharFormat (cf);
	m_hist.SetSel (-1,-1);


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

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatDlg::OnPaint() 
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
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChatDlg::OnOK() 
{
//追加聊天人信息并设置格式
    CHARFORMAT cf={sizeof(cf)};
	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_UNDERLINE;
	cf.crTextColor=RGB(255,0,255);
	cf.yHeight=280;
	strcpy(cf.szFaceName,"隶书");
	int nLen=m_hist.GetTextLength ();
	m_hist.SetSel (-1,-1);
	m_hist.ReplaceSel (_T("\r\n你对X X X 说:"));
	m_hist.SetSel(nLen,-1);
	m_hist.SetSelectionCharFormat (cf);
    //追加聊天内容并设置格式
	nLen=m_hist.GetTextLength();
	CString szText;
	GetDlgItemText(IDC_INPUT,szText);
	m_hist.SetSel(-1,-1);
	m_hist.ReplaceSel ("\r\n"+szText);
	cf.dwMask=CFM_COLOR|CFM_FACE|CFM_SIZE|CFM_UNDERLINE;
	cf.crTextColor=RGB(0,0,255);
	cf.yHeight=180;
	strcpy(cf.szFaceName,"宋体");
	m_hist.SetSel (nLen,-1);
	m_hist.SetSelectionCharFormat (cf);
	m_hist.SetSel(-1,-1);
	SetDlgItemText(IDC_INPUT,NULL);
	

//	CDialog::OnOK();
}
