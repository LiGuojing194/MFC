// cDlg.cpp : implementation file
//

#include "stdafx.h"
#include "c.h"
#include "cDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCDlg dialog

CCDlg::CCDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCDlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCDlg, CDialog)
	//{{AFX_MSG_MAP(CCDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCDlg message handlers

BOOL CCDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_sock.Create();
   if(!m_sock.Connect("172.26.24.55",8668))
   {
     AfxMessageBox("连接失败；无法连接服务器，请检查你的网络连接");
	 EndDialog(IDCANCEL);
	 return FALSE;
   }
   m_list.InsertColumn(0,"工号",0,100);
   m_list.InsertColumn(1,"姓名",0,100);
   m_list.InsertColumn(2,"工资",0,100);
  // OnRefresh();

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

void CCDlg::OnPaint() 
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
HCURSOR CCDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCDlg::OnAdd() 
{//先发送协议编号再发送一条信息数据到服务器端
	int nCmd=INF_ADD;
	m_sock.Send (&nCmd,sizeof(nCmd));
	SData data={GetDlgItemInt(IDC_NUMB)};
    GetDlgItemText(IDC_NAME,data.sName ,sizeof(data.sName ));
	CString str;
	GetDlgItemText(IDC_SALA,str);
	data.fSala =(float)atof(str);
	m_sock.Send(&data,sizeof(data));
	OnRefresh();
	
}

void CCDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}


void CCDlg::OnRefresh()
{//发送完协议编号后，先接收数据总数再逐条接收每条具体数据
	int nCmd=INF_BROW;
	m_sock.Send (&nCmd,sizeof(nCmd));
    int nCount=0,i=0;
	m_sock.Receive (&nCount,sizeof(nCount));
    m_list.DeleteAllItems ();
	SData data;
	CString str;
	while(i<nCount)
	{//从服务器端接收每条数据，并将内容插入到列表控件中显示
		m_sock.Receive(&data,sizeof(data));
		str.Format ("%d",data.nNumb );
		m_list.InsertItem (i,str);
		m_list.SetItemText (i,1,data.sName  );
		str.Format ("%0.2f",data.fSala );
		m_list.SetItemText (i,2,str);
		++i;
	    
	
	
	}
}
