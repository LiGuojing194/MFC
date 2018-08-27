// PenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Pen.h"
#include "PenDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPenDlg dialog

CPenDlg::CPenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPenDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPenDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPenDlg, CDialog)
	//{{AFX_MSG_MAP(CPenDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPenDlg message handlers

BOOL CPenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

void CPenDlg::OnPaint() 
{
CPaintDC dc(this);
//Ĭ�ϻ��ʺ�ɫ���Ϊһ
dc.MoveTo (20,20);
dc.LineTo (120,20);
//ͨ�����캯������һ������
CPen pn1(PS_SOLID,4,RGB(255,0,0));
CPen*pOldPen=dc.SelectObject (&pn1);
dc.MoveTo (20,30);
dc.LineTo (120,30);
//ͨ��CreatePen����һ������
CPen pn2;
pn2.CreatePen(PS_DASHDOT,1,RGB(0,0,255));
dc.SelectObject (&pn2);
dc.MoveTo (20,40);
dc.LineTo (120,40);
//ͨ��Ĭ�ϻ��ʻ�һ������
dc.SelectObject(pOldPen);
dc.Rectangle (140,20,240,100);
//��һ�����ߵľ���
dc.SelectObject(&pn2);
dc.Rectangle (20,50,120,100);
//��һ���ޱ߿�ľ���
CPen pn3(PS_NULL,1,RGB(255,0,255));
dc.SelectObject (&pn3);
dc.Rectangle(20,110,120,200);
	//�ȼ۵��ޱ߿���䷽��
dc.FillSolidRect (140,110,100,90,RGB(255,0,255));
//�ڻ�ͼ��ɺ󣬻ָ�ѡ��Ĭ�ϻ���
dc.SelectObject (pOldPen);
 CDialog::OnPaint();
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPenDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
