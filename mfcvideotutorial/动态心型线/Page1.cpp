// Page1.cpp : implementation file
//

#include "stdafx.h"
#include "动态心型线.h"
#include "Page1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1 dialog


CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1, CDialog)
	//{{AFX_MSG_MAP(CPage1)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1 message handlers

void CPage1::OnOK() 
{
  GetParent()->PostMessage (WM_COMMAND,IDOK);	
//	CDialog::OnOK();
}

void CPage1::OnCancel() 
{
	 
	GetParent()->PostMessage (WM_COMMAND,IDCANCEL);	
    CDialog::OnCancel();
}

void CPage1::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	dc.BitBlt (0,0,m_dcMem1.Width(),m_dcMem1.Height(),&m_dcMem1,0,0,SRCCOPY);
   // SetTimer(2,3000,NULL);
	
	// Do not call CDialog::OnPaint() for painting messages
}

void CPage1::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
		if(!m_dcBack1)     //从文件中加载一张背景图
		m_dcBack1.LoadBitmap(IDB_BITMAP5);
	//创建一张和客户区相同大小的内存画布
	if(m_dcMem1)
      m_dcMem1.DeleteDC();
	m_dcMem1.Create(cx,cy,&CClientDC(this));
	//当窗口大小发生变化时，在内存DC中拉伸背景图
	m_dcMem1.StretchBlt(0,0,cx,cy,&m_dcBack1,0,0,
		m_dcBack1.Width(),m_dcBack1.Height(),SRCCOPY);
	Invalidate(FALSE);

	
}
//#include"RegDlg.h"
void CPage1::OnTimer(UINT nIDEvent) 
{
	  // m_yu1.ShowWindow(SW_SHOW);
	  // Sleep(500);
	  // m_yu2.ShowWindow(SW_SHOW);
	  // Sleep(500);
	  // m_yu3.ShowWindow(SW_SHOW);
	  // Sleep(500);
	  // m_yu4.ShowWindow(SW_SHOW);
      //KillTimer(2);
	
	CDialog::OnTimer(nIDEvent);
}
