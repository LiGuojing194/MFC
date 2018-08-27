// MdcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mdc.h"
#include "MdcDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMdcDlg dialog

CMdcDlg::CMdcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMdcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMdcDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMdcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMdcDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMdcDlg, CDialog)
	//{{AFX_MSG_MAP(CMdcDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMdcDlg message handlers

BOOL CMdcDlg::OnInitDialog()
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

void CMdcDlg::OnPaint() 
{
  //将内存DC中缩放后的图片输出到客户区
	CPaintDC dc(this);//decice context for painting
	dc.BitBlt (0,0,m_dcMem.Width(),m_dcMem.Height (),&m_dcMem,0,0,SRCCOPY);


}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMdcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMdcDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
    if(!m_dcBack)     //从文件中加载一张背景图
		m_dcBack.LoadBitmap("./002.bmp");
	//创建一张和客户区相同大小的内存画布
	if(m_dcMem)
      m_dcMem.DeleteDC();
	m_dcMem.Create(cx,cy,&CClientDC(this));
	//当窗口大小发生变化时，在内存DC中拉伸背景图
	m_dcMem.StretchBlt(0,0,cx,cy,&m_dcBack,0,0,
		m_dcBack.Width(),m_dcBack.Height(),SRCCOPY);
	Invalidate(FALSE);

}
