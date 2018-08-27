// practiceCWndDlg.cpp : implementation file
//

#include "stdafx.h"
#include "practiceCWnd.h"
#include "practiceCWndDlg.h"
#include"mybutton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPracticeCWndDlg dialog

CPracticeCWndDlg::CPracticeCWndDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPracticeCWndDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPracticeCWndDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPracticeCWndDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPracticeCWndDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPracticeCWndDlg, CDialog)
	//{{AFX_MSG_MAP(CPracticeCWndDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPracticeCWndDlg message handlers

BOOL CPracticeCWndDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    HWND hWnd=::GetDlgItem (m_hWnd,IDC_EDIT1);
	m_edit.Attach(hWnd);
	hWnd=::GetDlgItem (m_hWnd,IDC_BUTTON1);
	m_dest.SubclassWindow (hWnd);
    m_cret.SubclassDlgItem (IDC_BUTTON2,this);
    m_list.CreateEx(WS_EX_CLIENTEDGE,"SysListViEW32",NULL,WS_CHILD|WS_VISIBLE|LVS_REPORT,CRect(30,90,310,250), this,8921);	
    m_list.InsertColumn (0,"ѧ��",0,100);
	m_list.InsertColumn (1,"����",0,100);
	m_list.InsertColumn (2,"����",0,100);


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

void CPracticeCWndDlg::OnPaint() 
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
HCURSOR CPracticeCWndDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPracticeCWndDlg::OnButton1() 
{
DestroyWindow();	
}

void CPracticeCWndDlg::OnButton2() //�����б�ؼ�
{
// m_list.Create("Edit","�Һ��ҵľ�ǿ",WS_VISIBLE|WS_CHILD,CRect(10,80,300,300),this,1111);
//m_list.CreateEx(WS_EX_CLIENTEDGE,"Static","��һ�Σ�Ϊ�Լ����",WS_CHILD|WS_VISIBLE|LVS_REPORT,CRect(20,50,300,300), this,8921);	
}

void CPracticeCWndDlg::OnButton3() //ȡ��ָ�룬ָ��ת���ɾ��
{
	CWnd*pwnd=GetDlgItem(IDOK);
/*	if(pwnd)//�Զ�ת����ָ��ת���ɾ�����ж�
	pwnd->DestroyWindow ();*/
	HWND hWnd=pwnd->m_hWnd ;//ȡ�����
	if(HWND)
		pwnd->DestroyWindow ();

	
}

void CPracticeCWndDlg::OnButton4() //���ת��Ϊ����
{
	HWND hWnd=::GetDlgItem (m_hWnd,IDOK);//����ȫ�ֺ�����ֱ��ȡ���ؼ����
	CWnd*p=CWnd::FromHandle (hWnd);//�����ת��Ϊһ����ʱ�Ե�ָ��
	p->SetWindowText ("��ʱ����");//��ʱ�Ե�ָ��ֻ�����ڵ�ǰ����ʹ��
}

void CPracticeCWndDlg::OnButton5() 
{
m_edit.SetWindowText("������Ч!");
	//SetDlgItemText(IDC_EDIT1,"LALA");
}

void CPracticeCWndDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	m_dest.UnsubclassWindow ();
	m_edit.Detach ();
}

void CPracticeCWndDlg::OnButton6() 
{
DWORD deStyle=m_edit.GetStyle();
m_edit.ModifyStyle (0,LVS_NOSORTHEADER|LVS_SHOWSELALWAYS);	
}

void CPracticeCWndDlg::OnButton7() 
{
DWORD deExStyle=m_edit.GetExStyle ();
m_edit.ModifyStyleEx (0,WS_EX_DLGMODALFRAME|WS_EX_CLIENTEDGE);//͹�����ݷ��
CRect rect;
m_edit.GetWindowRect(rect);//��ȡ�ؼ���ǰ����λ�ã�������Ļ����ϵ��������
ScreenToClient(rect);
rect.InflateRect(3,3);
m_edit.MoveWindow(rect);
Invalidate();//�ƺ�ֻ�����͹����	
}
