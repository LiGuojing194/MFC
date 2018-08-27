
// slideblockDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "slideblock.h"
#include "slideblockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CslideblockDlg 对话框



CslideblockDlg::CslideblockDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CslideblockDlg::IDD, pParent)
	, m_SliderV1(0)
	, m_SliderV2(0)
	, m_SliderV3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CslideblockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_SliderV1);
	DDX_Text(pDX, IDC_EDIT2, m_SliderV2);
	DDX_Text(pDX, IDC_EDIT3, m_SliderV3);
	DDX_Control(pDX, IDC_PROGRESS1, m_CProgressCtrl);
	DDX_Control(pDX, IDC_SLIDER1, m_CSlider1);
	DDX_Control(pDX, IDC_SLIDER2, m_CSlider2);
	DDX_Control(pDX, IDC_SLIDER3, m_CSlider3);
}

BEGIN_MESSAGE_MAP(CslideblockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CslideblockDlg 消息处理程序

BOOL CslideblockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_CSlider1.SetRange(0,255);
	m_CSlider2.SetRange(0,255);
	m_CSlider3.SetRange(0,255);
	m_CSlider1.SetTicFreq(5);
	m_CSlider2.SetTicFreq(5);
	m_CSlider3.SetTicFreq(5);
	m_CProgressCtrl.SetRange(0,90);
	m_CProgressCtrl.SetStep(5);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CslideblockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CslideblockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CslideblockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CslideblockDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	this->m_SliderV1 = this->m_CSlider1.GetPos();
	this->m_SliderV2 = this->m_CSlider2.GetPos();
	this->m_SliderV3 = this->m_CSlider3.GetPos();

	UpdateData(FALSE);

	if (this->m_CSlider1.GetPos() == 0 && this->m_CProgressCtrl.GetPos() <= 30)
	{
		this->m_CProgressCtrl.SetPos(30);
	}

	if (this->m_CSlider2.GetPos() == 255 && this->m_CProgressCtrl.GetPos() <= 60)
	{
		this->m_CProgressCtrl.SetPos(60);
	}

	if (this->m_CSlider3.GetPos() == 125 && this->m_CProgressCtrl.GetPos() <= 90)
	{
		this->m_CProgressCtrl.SetPos(90);
	}


}
