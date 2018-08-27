// xdcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "xdc.h"
#include "xdcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXdcDlg dialog

CXdcDlg::CXdcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CXdcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CXdcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXdcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CXdcDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CXdcDlg, CDialog)
	//{{AFX_MSG_MAP(CXdcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCPAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ACTIVATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXdcDlg message handlers

BOOL CXdcDlg::OnInitDialog()
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

void CXdcDlg::OnPaint() 
{//����dc����ʱ�Զ�����BeginPaint()����
	CPaintDC dc(this);
	//����������
	dc.Rectangle (0,0,40,40);
	dc.Rectangle (80,80,120,120);
	//��һ����
	dc.MoveTo (20,20);
	dc.LineTo (100,100);
    dc.Ellipse (150,150,300,300);

}//����dc����ʱ�Զ�����EndPaint��������׼�ͻ��˻滭��

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CXdcDlg::OnQueryDragIcon()
{

	return (HCURSOR) m_hIcon;
}

void CXdcDlg::OnNcPaint() 
{//����dc����ʱ�Զ�����GetWindowDC����
	CWindowDC dc(this);
	CRect rect;
	GetWindowRect(rect);
	dc.Rectangle (0,0,rect.Width (),rect.Height ());
	char str[200];
	sprintf(str,"�ǿͻ����ռ䣨%d,%d,%d,%d��",rect.left ,rect.top ,rect.bottom );
	dc.SetTextColor(RGB(255,0,0));//��������Ϊ��ɫ
	dc.TextOut (5,5,str,strlen(str));//�������

	// Do not call CDialog::OnNcPaint() for painting messages
}//����dc����ʱ�Զ�����ReleaseDC����

void CXdcDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{//����dc����ʱ�Զ�����GetDC����
	CClientDC dc(this);
	//��һ��Բ��
    dc.Ellipse(point.x-10,point.y-10,point.x+10,point.y+10);
    //�ͷŻ滭�����������GetDC�ɶ�ʹ��
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}//����dc����ʱ�Զ�����ReleaseDC������

void CXdcDlg::OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized) 
{
	CDialog::OnActivate(nState, pWndOther, bMinimized);
	
	// TODO: Add your message handler code here
	
}
