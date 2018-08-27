// FontDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Font.h"
#include "FontDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFontDlg dialog

CFontDlg::CFontDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFontDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFontDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFontDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFontDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFontDlg, CDialog)
	//{{AFX_MSG_MAP(CFontDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFontDlg message handlers

BOOL CFontDlg::OnInitDialog()
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

void CFontDlg::OnPaint() 
{
	CPaintDC dc(this);//device context for painting
	dc.TextOut (10,10,"使用默认字体输出文字");
	//从对话框模板中获取字体
	CFont*pFont=GetFont();
	Normal(&dc,pFont);
	Height(&dc,pFont);
	Weight(&dc,pFont);
	Width(&dc,pFont);
	Others(&dc,pFont);
	Escape(&dc,pFont);
	SetColors(&dc);
	CreateFont(&dc);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFontDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CFontDlg::Normal (CDC*pDC,CFont*pFont)
{
 pFont=pDC->SelectObject (pFont);
 pDC->TextOut (10,30,"使用对话框字体输出！");
 pDC->SelectObject (pFont);//恢复默认字体
}
void CFontDlg::Height (CDC*pDC,CFont*pFont)
{
  LOGFONT lf;
  pFont->GetLogFont (&lf);
  lf.lfHeight*=2;
  CFont font;
  font.CreateFontIndirect(&lf);
  pFont=pDC->SelectObject (&font);
  pDC->TextOut (10,50,"测试字体的高度加倍");
  pDC->SelectObject (pFont);
}
void CFontDlg::Weight (CDC*pDC,CFont*pFont)
{
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	lf.lfWeight =700;
	CFont font;
	font.CreateFontIndirect (&lf);
	pFont=pDC->SelectObject (&font);
	pDC->TextOut (10,80,"测试粗字体");
	pDC->SelectObject(pFont);
}
void CFontDlg::Width (CDC*pDC,CFont*pFont)
{
 LOGFONT lf;
 pFont->GetLogFont (&lf);
 lf.lfWidth =lf.lfHeight ;
 CFont font;
 font.CreateFontIndirect (&lf);
 pFont=pDC->SelectObject(&font);
 pDC->TextOut (10,100,"测试字体的宽度");
 pDC->SelectObject (pFont);
}
void CFontDlg::Others (CDC*pDC,CFont*pFont)
{
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	lf.lfItalic =TRUE;
	lf.lfUnderline=TRUE;
	lf.lfStrikeOut =TRUE;
	CFont font;
	font.CreateFontIndirect (&lf);
	pFont=pDC->SelectObject (&font);
	pDC->TextOut (10,120,"测试斜体，下划线和删除线");
	pDC->SelectObject (pFont);
}
void CFontDlg::Escape (CDC*pDC,CFont*pFont)
{
  LOGFONT lf;
  pFont->GetLogFont (&lf);
  lf.lfEscapement =200;
  CFont font;
  font.CreateFontIndirect(&lf);
  pDC->SelectObject (&font);
  pDC->TextOut (10,180,"测试字符串的倾斜程度");
  pDC->SelectObject (pFont);
}
void CFontDlg::SetColors (CDC*pDC)
{
  COLORREF oldText=pDC->SetTextColor (RGB(225,0,0));
  pDC->TextOut (10,200,"字体颜色");
COLORREF oldBack=pDC->SetBkColor (RGB(0,0,225));
pDC->TextOut (80,200,"背景颜色");
int nOldMode=pDC->SetBkMode(TRANSPARENT);
pDC->TextOut (150,200,"背景透明");
pDC->SetTextColor(oldText);
pDC->SetBkColor(oldBack);
pDC->SetBkMode(nOldMode);
}
void CFontDlg::CreateFont(CDC*pDC)
{
CFont ft1;
ft1.CreatePointFont(100,"幼园");
CFont*pOldFont=pDC->SelectObject(&ft1);
pDC->TextOut(10,220,"简单创建字体的方法");
pDC->SelectObject(pOldFont);
LOGFONT lf={20};
lf.lfCharSet=GB2312_CHARSET;
lf.lfWeight=400;
strcpy(lf.lfFaceName,"隶书");
CFont ft2;
ft2.CreateFontIndirect (&lf);
pDC->SelectObject(&ft2);
pDC->TextOut(10,240,"完整创建字体的方法");
}