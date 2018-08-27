// BltDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Blt.h"
#include "BltDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBltDlg dialog

CBltDlg::CBltDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBltDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBltDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBltDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBltDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBltDlg, CDialog)
	//{{AFX_MSG_MAP(CBltDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBltDlg message handlers

BOOL CBltDlg::OnInitDialog()
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

void CBltDlg::OnPaint() 
{
	CPaintDC dc(this);
	CBitmap bmp;
	bmp.LoadBitmap (IDB_BITMAP1);
	BITMAP bm;
	bmp.GetBitmap (&bm);
	//创建兼容内存DC并选择背景图；
	CDC mdc;
	mdc.CreateCompatibleDC (&dc);
	//mdc.CreateComparibleDC(&dc);
	mdc.SelectObject (&bmp);
	//完整输出整张图片
	dc.BitBlt (0,0,bm.bmWidth ,bm.bmHeight,&mdc,0,0,SRCCOPY);
	//cong1/3的位置开始输出右下角2/3大小的图片
	dc.BitBlt (bm.bmWidth +10,10,bm.bmWidth *2/3,bm.bmHeight*2/3,&mdc,bm.bmWidth /3,bm.bmHeight /3,SRCCOPY);
	//dc.BitBlt (bm.bmWidth *2-60,bm.bmHeight -25,bm.bmWidth *2/3,bm.bmHeight*2/3,&mdc,bm.bmWidth/3 ,bm.bmHeight/3,SRCCOPY);

	//使用默认算法将图像压缩一半
	dc.StretchBlt (10,bm.bmHeight+10,bm.bmWidth /2,bm.bmHeight /2,&mdc,0,0,bm.bmWidth ,bm.bmHeight ,SRCCOPY);
	//更换压缩算法提高压缩后的图片品质
	dc.SetStretchBltMode (COLORONCOLOR);
	dc.StretchBlt (bm.bmWidth/2+20 ,bm.bmHeight +10,bm.bmWidth/2,bm.bmHeight /2,&mdc,0,0,bm.bmWidth ,bm.bmHeight ,SRCCOPY);
    //左右对称的压缩
	dc.StretchBlt (bm.bmWidth +30,bm.bmHeight +10,bm.bmWidth /2,bm.bmHeight /2,&mdc,bm.bmWidth ,0,-bm.bmWidth ,bm.bmHeight ,SRCCOPY);
	//左右对称的压缩
	dc.StretchBlt (bm.bmWidth*2-60,bm.bmHeight-60 ,bm.bmWidth ,bm.bmHeight,&mdc,bm.bmWidth ,0 ,-bm.bmWidth ,bm.bmHeight ,SRCCOPY);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBltDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
