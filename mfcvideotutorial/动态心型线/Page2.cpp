// Page2.cpp : implementation file
//

#include "stdafx.h"
#include "动态心型线.h"
#include "Page2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2 dialog


CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialog(CPage2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2)
	DDX_Control(pDX, IDC_BUTTON2, m_sorrow);
	DDX_Control(pDX, IDC_BUTTON1, m_happy);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2, CDialog)
	//{{AFX_MSG_MAP(CPage2)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2 message handlers

void CPage2::OnOK() 
{
   	GetParent()->PostMessage (WM_COMMAND,IDOK);
}

void CPage2::OnCancel() 
{
   	GetParent()->PostMessage (WM_COMMAND,IDOK);
}

void CPage2::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.BitBlt (0,0,m_dcMem2.Width(),m_dcMem2.Height(),&m_dcMem2,0,0,SRCCOPY);

	
	// Do not call CDialog::OnPaint() for painting messages
}

void CPage2::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!m_dcBack2)     //从文件中加载一张背景图
		m_dcBack2.LoadBitmap(IDB_BITMAP7);
	//创建一张和客户区相同大小的内存画布
	if(m_dcMem2)
      m_dcMem2.DeleteDC();
	m_dcMem2.Create(cx,cy,&CClientDC(this));
	//当窗口大小发生变化时，在内存DC中拉伸背景图
	m_dcMem2.StretchBlt(0,0,cx,cy,&m_dcBack2,0,0,
		m_dcBack2.Width(),m_dcBack2.Height(),SRCCOPY);
	Invalidate(FALSE);

	
}

BOOL CPage2::OnInitDialog() 
{
	CDialog::OnInitDialog();
	//m_happy.SetBitmap (AfxGetApp()->Load(IDI_ICON1));
		m_happy.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON1));
	    m_sorrow.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON2));

   	SetTimer(1,500,NULL);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPage2::OnMouseMove(UINT nFlags, CPoint point) 
{
	  /*BOOL x;
	  CRect Rect1,Rect2;
	  m_happy.GetWindowRect(&Rect1);
	  ScreenToClient(&Rect1);
      m_sorrow.GetWindowRect(&Rect2);
	  ScreenToClient(&Rect2);
	  if((Rect2.PtInRect (point)))
	  {
	   m_happy.MoveWindow(Rect2);
    	m_sorrow.MoveWindow (Rect1);
	  }
	   //m_sorrow.SetWindowText ("happy");*/
	
	CDialog::OnMouseMove(nFlags, point);
}

void CPage2::OnTimer(UINT nIDEvent) 
{
	CRect Rect1,Rect2;
	  m_happy.GetWindowRect(&Rect1);
	  ScreenToClient(&Rect1);
      m_sorrow.GetWindowRect(&Rect2);
	  ScreenToClient(&Rect2);
	m_happy.MoveWindow(Rect2);
    	m_sorrow.MoveWindow (Rect1);
	CDialog::OnTimer(nIDEvent);
}

void CPage2::OnButton2() 
{
KillTimer(1);
//m_sorrow.SetWindowText ("cheer up!");	
	m_sorrow.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON3));
    m_happy.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON4));
	AfxMessageBox("Cheer up,真心希望你能快乐！(^.^)\n\tMy Buddy!",MB_OK|MB_ICONWARNING);

}

void CPage2::OnButton1() 
{
	KillTimer(1);
    m_sorrow.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON1));
    AfxMessageBox("我很高兴你很开心↖(^ω^)↗\n\tMy Buddy!",MB_OK|MB_ICONWARNING);
	
}
