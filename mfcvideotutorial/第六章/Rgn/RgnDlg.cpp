// RgnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Rgn.h"
#include "RgnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRgnDlg dialog

CRgnDlg::CRgnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRgnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRgnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRgnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRgnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRgnDlg, CDialog)
	//{{AFX_MSG_MAP(CRgnDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRgnDlg message handlers

BOOL CRgnDlg::OnInitDialog()
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

void CRgnDlg::OnPaint() 
{
  CPaintDC dc(this);
  //加载位图资源并获取位图高宽
  CBitmap bmp;
  bmp.LoadBitmap (IDB_BITMAP1);
  BITMAP bm;
  bmp.GetBitmap (&bm);
  int cx=bm.bmWidth ;
  int cy=bm.bmHeight ;
  //创建兼容的内存DC并选择背景图
  CDC mdc;
  mdc.CreateCompatibleDC (&dc);
  mdc.SelectObject (&bmp);
  //根据多点坐标创建一个不规则区域
  POINT pts[]={{20,16},{110,56},{144,16},{166,52},{250,20},{240,100},{250,180},{150,160},{32,180},{52,100}};
  CRgn rg1;
  rg1.CreatePolygonRgn (pts,sizeof(pts)/sizeof(POINT),WINDING);
  //根据选择的区域输出图片
  dc.SelectObject (&rg1);
  dc.BitBlt (0,0,cx,cy,&mdc,0,0,SRCCOPY);
  //建立一个圆角矩形区域
  CRgn rg2;
  int nLeft=cx-50;
  int nTop=cy-50;
  rg2.CreateRoundRectRgn (nLeft,nTop,nLeft+cx,nTop+cy,32,32);
  //根据选择的区域输出图片
  dc.SelectObject(&rg2);
  dc.BitBlt(nLeft,nTop,cx,cy,&mdc,0,0,SRCCOPY);
  rg1.CombineRgn (&rg1,&rg2,RGN_OR);
  SetWindowRgn(rg1,TRUE);

}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRgnDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

UINT CRgnDlg::OnNcHitTest(CPoint point) 
{
	UINT nHitTest=CDialog::OnNcHitTest (point);	
	if(nHitTest==HTCLIENT)
		nHitTest=HTCAPTION;
	return nHitTest;
}
