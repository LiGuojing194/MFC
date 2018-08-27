// uDlg.cpp : implementation file
//

#include "stdafx.h"
#include "u.h"
#include "uDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUDlg dialog

CUDlg::CUDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUDlg, CDialog)
	//{{AFX_MSG_MAP(CUDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDlg message handlers

BOOL CUDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    if(!m_sock.Create(8828,SOCK_DGRAM))
	{
	   CString str;
	   str.Format ("创建Soket时出错：%d",GetLastError());
	   AfxMessageBox(str);
	}
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

void CUDlg::OnPaint() 
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
HCURSOR CUDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CUDlg::OnOK() 
{
CString szIP,szText;
GetDlgItemText(IDC_INPUT,szText);
if(szText.IsEmpty ())
{
   AfxMessageBox("请输入要发送的文字");
   return;
}	
GetDlgItemText(IDC_IP,szIP);
if(szIP.IsEmpty ())
{
    AfxMessageBox("请输入对方主机的IP");
	return;
}
UINT nPort=GetDlgItemInt(IDC_PORT);
m_sock.SendTo(szText,szText.GetLength (),nPort,szIP);
//	CDialog::OnOK();
CString str;
str.Format ("你对%s说：\r\n%s\r\n",szIP,szText);
//CWnd*pDlg=AfxGetMainWnd();
CEdit*pEdit=(CEdit*)GetDlgItem(IDC_HIST);
pEdit->SetSel(pEdit->GetWindowTextLength(),-1);
pEdit->ReplaceSel (str);
}
