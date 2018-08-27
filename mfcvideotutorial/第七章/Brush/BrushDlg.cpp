// BrushDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Brush.h"
#include "BrushDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrushDlg dialog

CBrushDlg::CBrushDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBrushDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBrushDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBrushDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBrushDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBrushDlg, CDialog)
	//{{AFX_MSG_MAP(CBrushDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBrushDlg message handlers

BOOL CBrushDlg::OnInitDialog()
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

void CBrushDlg::OnPaint() 
{
  CPaintDC dc(this);
  //使用默认画刷画一个矩形（黑框白底）
  dc.Rectangle(20,20,120,120);
  //使用蓝色实心填充一个椭圆
  CBrush brl(RGB(0,0,255));
  CBrush*pOldBrush=dc.SelectObject (&brl);
  dc.Ellipse(140,20,240,100);
  //使用红色阴影线填充一个圆角矩形
  CBrush br2(HS_FDIAGONAL,RGB(255,0,0));
  dc.SelectObject(&br2);
  //并结合画笔绘制边框
  CPen pen(PS_SOLID,3,RGB(255,0,255));
  CPen*pOldPen=dc.SelectObject(&pen);
  dc.RoundRect (260,20,300,100,25,25);
  //使用小位图平铺在一个多边形内
  CPen pen3(PS_SOLID,3,RGB(0,0,255));
  dc.SelectObject (&pen3);
  CBitmap bmp;
  bmp.LoadBitmap (IDB_BITMAP1);
  CBrush br3(&bmp);
  dc.SelectObject (&br3);
  POINT pt[]={{40,130},{160,130},{240,240},{20,240},{120,300}};
  dc.Polygon(pt,5);
  //使用无填充的画刷画一个空心的半月弦
  CPen pen2(PS_SOLID,3,RGB(255,255,0));
  dc.SelectObject (&pen2);
  CBrush br4;
  LOGBRUSH lb={BS_NULL};
  br4.CreateBrushIndirect (&lb);
  dc.SelectObject (&br4);
  dc.Chord (CRect(140,120,350,240),CPoint(260,240),CPoint(140,100));
  //在绘图完成后，恢复选择默认画刷和画笔
  dc.SelectObject (pOldBrush);
  dc.SelectObject (pOldPen);

  CDialog::OnPaint();
}//以上画笔画刷和位图对象，在离开时自动执行析构函数并释放句柄资源

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBrushDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
