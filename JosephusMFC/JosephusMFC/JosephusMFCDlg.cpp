
// JosephusMFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JosephusMFC.h"
#include "JosephusMFCDlg.h"
#include "afxdialogex.h"
#include"ring.h"
#include"Help.h"

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


// CJosephusMFCDlg 对话框



CJosephusMFCDlg::CJosephusMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJosephusMFCDlg::IDD, pParent)
	, m_nScaleDlg(0)
	, m_nStartDlg(0)
	, m_nLoopDlg(0)
	, m_nFindDlg(0)
	, m_nResultDlg(0)
{
	m_pMenberDlg = nullptr;
	m_nBuildCount = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJosephusMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SCALE, m_nScaleDlg);
	DDX_Text(pDX, IDC_START, m_nStartDlg);
	DDX_Text(pDX, IDC_LOOP, m_nLoopDlg);
	DDX_Text(pDX, IDC_FIND, m_nFindDlg);
	DDX_Text(pDX, IDC_RESULT, m_nResultDlg);
	DDX_Control(pDX, IDC_LIST_OUTPUT, m_ListOutput);
	DDX_Control(pDX, IDC_LIST_LOG, m_list_log);
}

BEGIN_MESSAGE_MAP(CJosephusMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CJosephusMFCDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CLEAR, &CJosephusMFCDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_LOOKFOR, &CJosephusMFCDlg::OnBnClickedLookfor)
	ON_BN_CLICKED(IDC_HELP, &CJosephusMFCDlg::OnBnClickedHelp)
	ON_BN_CLICKED(IDCANCEL, &CJosephusMFCDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CJosephusMFCDlg 消息处理程序

BOOL CJosephusMFCDlg::OnInitDialog()
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
	m_list_log.InsertColumn(0, _T("时间"), LVCFMT_LEFT, 90);// 插入列 
	m_list_log.InsertColumn(1, _T("操作"), LVCFMT_LEFT, 300);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CJosephusMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJosephusMFCDlg::OnPaint()
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
HCURSOR CJosephusMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Ring ring(m_nScaleDlg, m_nStartDlg, m_nLoopDlg);
void CJosephusMFCDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	UpdateData();
	if (m_nScaleDlg < 1)
	{
		MessageBox(_T("成员总数必须不小于1！"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("约瑟夫环构建失败--总人数小于1"));
		return;
	}
	if (m_nStartDlg<1 || m_nStartDlg>m_nScaleDlg)
	{
		MessageBox(_T("开始报数的位置必须在总人数的范围内！"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("约瑟夫环构建失败--起始位置设定越界"));
		return;
	}
	if (m_nLoopDlg<1)
	{
		MessageBox(_T("循环数必须不小于1！"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("约瑟夫环构建失败--循环数小于1"));
		return;
	}
    m_nBuildCount++;
	m_nLastScale = m_nScaleDlg;
	m_pMenberDlg = new Member[m_nScaleDlg];
	Ring ring(m_nScaleDlg, m_nStartDlg, m_nLoopDlg);//此处定义的ring,出了这个函数将被析构，析构后的数据将被清除，所以我在查看按钮的消息映射函数里无法查看数据了
	ring.BuildRing();
	ring.Run();
	MessageBox(_T("约瑟夫环构建成功！"));
	CTime tm = CTime::GetCurrentTime();
	CString str = tm.Format("%X");
	int nRow = m_list_log.InsertItem(0, str);
	m_list_log.SetItemText(nRow, 1, _T("约瑟夫环构建成功！"));
	for (int i = 0; i < m_nScaleDlg; i++)
	{
		m_pMenberDlg[i] = ring.m_pMenber[i];
	}
	//m_pMenberDlg = ring.m_pMenber;
	CString str1,str2;
	str1.Format(L"第%d次构建。总人数：%d  开始序号：%d  循环数：%d  最后一个退出的是%d号",m_nBuildCount,m_nScaleDlg,m_nStartDlg,m_nLoopDlg,ring.m_pStart->m_nNumber);
	m_ListOutput.SetHorizontalExtent(550);
	this->m_ListOutput.AddString(str1);
	for (int i = 0; i < m_nScaleDlg; i++)
	{
		str2.Format(L"成员编号： %d    退出序号：%d", i+1, m_pMenberDlg[i].m_nOutNumber);
		this->m_ListOutput.AddString(str2);
	}
	m_nScaleDlg = 0;
	m_nStartDlg = 0;
	m_nLoopDlg = 0;
	UpdateData(FALSE);
    tm = CTime::GetCurrentTime();
    str = tm.Format("%X");
    nRow = m_list_log.InsertItem(0, str);
	m_list_log.SetItemText(nRow, 1, _T("约瑟夫环运行成功！"));

}


void CJosephusMFCDlg::OnBnClickedClear()
{
	// TODO:  在此添加控件通知处理程序代码
	this->m_ListOutput.ResetContent();
}


void CJosephusMFCDlg::OnBnClickedLookfor()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!m_pMenberDlg)
	{
		MessageBox(_T("请先构建好约瑟夫环！"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("查看退出情况失败--未构建约瑟夫环"));
		return;
	}
	UpdateData();
	if (m_nFindDlg<1 || m_nFindDlg>m_nLastScale)
	{
		MessageBox(_T("查找序号应为大于0,不大于总人数的正整数！"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("查看退出情况失败--查找范围越界"));
		return;
	}
	for(int i = 0; i < m_nLastScale; i++ )
	{
		if (m_nFindDlg == m_pMenberDlg[i].m_nOutNumber)
		{
			m_nResultDlg = i+1;
			break;
		}
	}
	UpdateData(FALSE);
	CTime tm = CTime::GetCurrentTime();
	CString str = tm.Format("%X");
	int nRow = m_list_log.InsertItem(0, str);
	m_list_log.SetItemText(nRow, 1, _T("查看退出情况成功！"));
}


void CJosephusMFCDlg::OnBnClickedHelp()
{
	// TODO:  在此添加控件通知处理程序代码
	Help*dlg = new Help();
	dlg->Create(IDD_HELP); //创建一个非模态对话框  
	dlg->ShowWindow(SW_SHOWNORMAL); //显示非模态对话框  
	//dlg.ShowWindow(SW_SHOWNORMAL);

}


void CJosephusMFCDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
