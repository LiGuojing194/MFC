// RegDlg.cpp : implementation file
//

#include "stdafx.h"
#include "动态心型线.h"
#include "RegDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegDlg dialog


CRegDlg::CRegDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegDlg)
	DDX_Control(pDX, IDC_BUTTON5, m_open);
	DDX_Control(pDX, IDC_BUTTON4, m_yu4);
	DDX_Control(pDX, IDC_BUTTON3, m_yu3);
	DDX_Control(pDX, IDC_BUTTON2, m_yu2);
	DDX_Control(pDX, IDC_BUTTON1, m_yu1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegDlg, CDialog)
	//{{AFX_MSG_MAP(CRegDlg)
	ON_BN_CLICKED(IDC_BACK, OnBack)
	ON_WM_DRAWITEM()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegDlg message handlers

BOOL CRegDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	m_dc1.LoadBitmap(IDB_BITMAP2);
//	SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
    m_open.SetIcon (AfxGetApp()->LoadIcon (IDI_ICON5));

	//SetDialogBkColor(RGB(255,0,0),RGB(0,0,255));
	//创建三个分页子窗口，并显示第一个分页
	i=0;
	m_p1.Create(IDD_DIALOG1,this);
	m_p2.Create (IDD_DIALOG2,this);
	m_p1.ShowWindow (SW_SHOW);
	m_nSel=0;
	  m_yu1.ShowWindow(SW_HIDE);
       m_yu2.ShowWindow(SW_HIDE);
       m_yu3.ShowWindow(SW_HIDE);
       m_yu4.ShowWindow(SW_HIDE);
	return TRUE;  // return TRUE unless you set the focus to a 
}

void CRegDlg::SelectPage()
{
	int i=0;
   CWnd*ps[]={&m_p1,&m_p2};
   while(i<sizeof(ps)/sizeof(ps[0]))//只显示一个页面
	   ps[i++]->ShowWindow (i==m_nSel?SW_SHOW:SW_HIDE);
      
   //给当前显示的页面设置焦点
   ps[m_nSel]->SetFocus();//激活或禁用步骤按钮
   GetDlgItem(IDOK)->EnableWindow(m_nSel<1);
   GetDlgItem(IDC_BACK)->EnableWindow(m_nSel);

}

void CRegDlg::OnBack() 
{
	// TODO: Add your control notification handler code here
		if(m_nSel)
  {
     --m_nSel;
	 SelectPage();
  }

}

void CRegDlg::OnOK() 
{
	// TODO: Add extra validation here
	if(m_nSel<1)
  {
     ++m_nSel;
	 SelectPage();
  }
/*	if(m_nSel==0)
	{
	   m_yu1.ShowWindow(SW_SHOW);
	   Sleep(500);
	   m_yu2.ShowWindow(SW_SHOW);
	   Sleep(500);
	   m_yu3.ShowWindow(SW_SHOW);
	   Sleep(500);
	   m_yu4.ShowWindow(SW_SHOW);
	 }*/
//	CDialog::OnOK();
}

void CRegDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{	if(nIDCtl==IDCANCEL)
	{
	  CDC dc;
	  CRect rect,rect1;
	  dc.Attach (lpDrawItemStruct->hDC );
	  rect=lpDrawItemStruct->rcItem ;
	  dc.Draw3dRect (&rect,RGB(255,0,0),RGB(0,0,255));//蓝，白
	  dc.FillSolidRect (&rect,RGB(225,225,100));//色
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
      dc.SetBkColor (RGB(150,150,100));
	  dc.SetTextColor (RGB(0,255,0));//红

	  TCHAR buffer[MAX_PATH];
	  ZeroMemory(buffer,MAX_PATH);
	  ::GetWindowText (lpDrawItemStruct->hwndItem ,buffer,MAX_PATH);
	  dc.DrawText (buffer,&rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	  dc.Detach ();

	}
//	if(nIDCtl==IDCANCEL)
	if(nIDCtl==IDOK||nIDCtl==IDC_BACK)
	{
	  CDC dc;
	  CRect rect,rect1;
	  dc.Attach (lpDrawItemStruct->hDC );
	  rect=lpDrawItemStruct->rcItem ;
	  dc.Draw3dRect (&rect,RGB(255,0,0),RGB(0,0,0));//蓝，白
	  dc.FillSolidRect (&rect,RGB(0,255,255));//色
	  rect.DeflateRect(2,2);
	  rect1=rect;
	  UINT state=lpDrawItemStruct->itemState ; 
      rect1.DeflateRect(4,4);
      if(state&ODS_FOCUS) dc.DrawFocusRect (rect1);
	  if((state&ODS_SELECTED))
	  {
		//dc.DrawFocusRect (rect1);
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

void CRegDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for paintin
	dc.BitBlt (0,0,m_dcMem1.Width(),m_dcMem1.Height(),&m_dcMem1,0,0,SRCCOPY);
//	m_dc.BitTrans(590,120,m_dc.Width(),m_dc.Height(),&dc,0,0,RGB(255,0,0));	
	// Do not call CDialog::OnPaint() for painting messages
}

void CRegDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	if(!m_dcBack1)     //从文件中加载一张背景图
		m_dcBack1.LoadBitmap(IDB_BITMAP4);
	//创建一张和客户区相同大小的内存画布
	if(m_dcMem1)
      m_dcMem1.DeleteDC();
	m_dcMem1.Create(cx,cy,&CClientDC(this));
	//当窗口大小发生变化时，在内存DC中拉伸背景图
	m_dcMem1.StretchBlt(0,0,cx,cy,&m_dcBack1,0,0,
		m_dcBack1.Width(),m_dcBack1.Height(),SRCCOPY);
	 /*  m_yu1.ShowWindow(SW_HIDE);
       m_yu2.ShowWindow(SW_HIDE);
       m_yu3.ShowWindow(SW_HIDE);
       m_yu4.ShowWindow(SW_HIDE);*/
	
	Invalidate(FALSE);

	
}
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
void CRegDlg::OnButton5() 
{
	i=(i+1)%2;
	if(i)
    PlaySound((LPCTSTR)IDR_WAVE1,AfxGetInstanceHandle(),SND_RESOURCE|SND_ASYNC|SND_LOOP);
	else
		PlaySound(NULL,NULL,SND_ASYNC);

	   m_yu1.ShowWindow(SW_SHOW);
	   Sleep(1000);
	   m_yu2.ShowWindow(SW_SHOW);
	   Sleep(1000);
	   m_yu3.ShowWindow(SW_SHOW);
	   Sleep(1000);
	   m_yu4.ShowWindow(SW_SHOW);
}

