// 动态心型线Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "动态心型线.h"
#include "动态心型线Dlg.h"
#include"math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDlg dialog

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyDlg, CDialog)
	//{{AFX_MSG_MAP(CMyDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_WM_SETCURSOR()
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDlg message handlers

BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_dc.LoadBitmap(IDB_BITMAP1);
	SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
   // GetDlgItem(IDOK)->EnableWindow
	//SetTimer(1,500,NULL);

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
int j=0;
void CMyDlg::OnPaint() 
{
	CPaintDC dc(this);
	dc.BitBlt (0,0,m_dcMem.Width(),m_dcMem.Height(),&m_dcMem,0,0,SRCCOPY);
	m_dc.BitTrans(590,120,m_dc.Width(),m_dc.Height(),&dc,0,0,RGB(255,0,0));
	CPen pen1(PS_SOLID,2,RGB(0,255,0)); 
	CPen*pOldPen=dc.SelectObject (&pen1);
	dc.Ellipse (100,100,150,150);
//	CPen pen2(PS_DOT,1,RGB(255,0,0));
//	dc.SelectObject (&pen2);
 //   dc.Ellipse (150,100,200,150);
	// CPaintDC pDC(this);
	CFont ft1;
	ft1.CreatePointFont(200,"楷体");
    CFont*pOldFont=dc.SelectObject (&ft1);
	dc.TextOut (270,100,"最短的圆心距绘出世间最远的距离");
	dc.TextOut(270,125,"每一个运动的点都描绘着永恒不变的真心");
    dc.SelectObject (pOldPen);

	SetTimer(1,100,NULL);
}
HCURSOR CMyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
double i=0;
void CMyDlg::OnTimer(UINT nIDEvent) 
{

  //Invalidate();
   CClientDC dcm(this),pdc(this);
   CPen pen2(PS_DOT,1,RGB(225,0,100));
   CPen pen3(PS_SOLID,2,RGB(255,0,0));
   CPen*pOldPen=dcm.SelectObject (&pen2);
   pdc.SelectObject (&pen3);
  // dc.Ellipse (150,100,200,150);

   double x,y,x1,x2,y1,y2,j;
   if(i<6.283)
   {
     x=50.0*cos(i);
     y=50.0*sin(i);
	 dcm.Ellipse (x+100,y+100,x+150,y+150);
	 for(j=0;j<i;j+=6.283/1000)
	 {
	  x1=(int)(25*(2*cos(j)-cos(2*j)))+125;
	  y1=(int)(25*(2*sin(j)-sin(2*j)))+125;
	  x2=(int)(25*(2*cos(j+0.06283/10)-cos(2*(j+0.06283/10))))+125;
	  y2=(int)(25*(2*sin(j+0.06283/10)-sin(2*(j+0.06283/10))))+125;
	  pdc.MoveTo (x1,y1);
	  pdc.LineTo(x2,y2);
	 }
     i+=0.06283;
	 // Sleep(500);
	 // Invalidate();
   }
   else
   {
	   //j=1;
	 //  OnPaint();
   // CPaintDC p(this);
	//CFont ft1;
	//ft1.CreatePointFont(100,"楷体");
//	CFont*pOldFont=p.SelectObject (&ft1);
//	dcm.TextOut (100,20,"最短的圆心距绘出世间最远的距离");
	Sleep(3000);

	i=0;
	Invalidate();
   }
   
//	CDialog::OnTimer(nIDEvent);
}

void CMyDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
    if(!m_dcBack)     //从文件中加载一张背景图
		m_dcBack.LoadBitmap(IDB_BITMAP6);
	//创建一张和客户区相同大小的内存画布
	if(m_dcMem)
      m_dcMem.DeleteDC();
	m_dcMem.Create(cx,cy,&CClientDC(this));
	//当窗口大小发生变化时，在内存DC中拉伸背景图
	m_dcMem.StretchBlt(0,0,cx,cy,&m_dcBack,0,0,
		m_dcBack.Width(),m_dcBack.Height(),SRCCOPY);
	Invalidate(FALSE);

	
}

BOOL CMyDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	
	return TRUE;
}

HBRUSH CMyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==CTLCOLOR_STATIC)//所有静态控件的颜色
	{
	  pDC->SetTextColor (RGB(0,0,0));//所有静态文本颜色
	  pDC->SetBkColor (RGB(166,243,248));
	  hbr=(HBRUSH)CreateSolidBrush(RGB(0,120,255));//返回画刷
	}
/*	if(pWnd->GetDlgCtrlID ()==IDC_BUTTON1)
	{
	  CFont font;
	  font.CreatePointFont (300,_T("Helevetica"),NULL);
	  pDC->SelectObject (&font);
	  pDC->SetTextColor (RGB(255,0,0));//所有静态文本颜色
	  pDC->SetBkColor (RGB(166,243,248));
	 // pDC->TextOut ("");
	  hbr=(HBRUSH)CreateSolidBrush(RGB(220,120,0));//返回画刷
 
	
	}*/

	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMyDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	//	if(nIDCtl==IDOK||nIDCtl==IDC_BUTTON1)//
	if(nIDCtl==IDCANCEL)
	{
	  CDC dc;
	  CRect rect,rect1;
	  dc.Attach (lpDrawItemStruct->hDC );
	  rect=lpDrawItemStruct->rcItem ;
	  dc.Draw3dRect (&rect,RGB(255,0,0),RGB(0,0,255));//蓝，白
	  dc.FillSolidRect (&rect,RGB(225,100,220));//色
	  rect.DeflateRect(2,2);
	  rect1=rect;
	  rect1.DeflateRect(4,4);
     // if(state) dc.DrawFocusRect (rect1);
      UINT state=lpDrawItemStruct->itemState ;
	  if(state&ODS_FOCUS) dc.DrawFocusRect (rect1);
	  if((state&ODS_SELECTED))
	  {
	    dc.DrawEdge(&rect,EDGE_SUNKEN,BF_RECT);
		//dc.DrawFocusRect (rect1);

	  }
	  else
	  {
		dc.DrawEdge(&rect,EDGE_RAISED,BF_RECT);
	  }
      dc.SetBkColor (RGB(150,150,200));
	  dc.SetTextColor (RGB(255,255,0));//红

	  TCHAR buffer[MAX_PATH];
	  ZeroMemory(buffer,MAX_PATH);
	  ::GetWindowText (lpDrawItemStruct->hwndItem ,buffer,MAX_PATH);
	  dc.DrawText (buffer,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	  dc.Detach ();

	}
//	if(nIDCtl==IDCANCEL)
	if(nIDCtl==IDOK||nIDCtl==IDC_BUTTON1)
	{
	  CDC dc;
	  CRect rect,rect1;
	  dc.Attach (lpDrawItemStruct->hDC );
	  rect=lpDrawItemStruct->rcItem ;
	  dc.Draw3dRect (&rect,RGB(255,0,0),RGB(0,0,0));//蓝，白
	  dc.FillSolidRect (&rect,RGB(0,255,255));//色
	  rect.DeflateRect(2,2);
	  rect1=rect;
     // dc.DrawFocusRect (&rect);
	  UINT state=lpDrawItemStruct->itemState ; 
	  //if(state) dc.DrawFocusRect (rect1);
      rect1.DeflateRect(4,4);
      if(state&ODS_FOCUS) dc.DrawFocusRect (rect1);
	  if((state&ODS_SELECTED))
	  {
		dc.DrawFocusRect (rect1);
        dc.DrawEdge(&rect,EDGE_SUNKEN,BF_RECT);
	  }
	  else
	  {
		dc.DrawEdge(&rect,EDGE_RAISED,BF_RECT);
	  }
      dc.SetBkColor (RGB(130,220,200));
	  dc.SetTextColor (RGB(50,0,255));//红

	  TCHAR buffer[MAX_PATH];
	  ZeroMemory(buffer,MAX_PATH);
	  ::GetWindowText (lpDrawItemStruct->hwndItem ,buffer,MAX_PATH);
	  dc.DrawText (buffer,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	  dc.Detach ();

	}

	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
#include"RegDlg.h"
void CMyDlg::OnOK() 
{
	ShowWindow(SW_HIDE);
	CRegDlg dlg;
	if(IDCANCEL==dlg.DoModal())
	{
		ShowWindow(SW_SHOW);
        return;
	}
	   
	//CDialog::OnOK();
}
