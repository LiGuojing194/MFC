
// OPPEx2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OPPEx2.h"
#include "OPPEx2Dlg.h"
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


// COPPEx2Dlg 对话框



COPPEx2Dlg::COPPEx2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COPPEx2Dlg::IDD, pParent)
	, m_Name(_T(""))
	, m_Sid(_T(""))
	, m_Value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COPPEx2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListCon);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Sid);
	DDX_Text(pDX, IDC_EDIT3, m_Value);
}

BEGIN_MESSAGE_MAP(COPPEx2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &COPPEx2Dlg::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &COPPEx2Dlg::OnSelchangeList1)
	ON_BN_CLICKED(IDC_SHOW, &COPPEx2Dlg::OnBnClickedShow)
	ON_BN_CLICKED(IDC_ADD, &COPPEx2Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DELETE, &COPPEx2Dlg::OnBnClickedDelete)
	ON_EN_CHANGE(IDC_NAME, &COPPEx2Dlg::OnEnChangeName)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// COPPEx2Dlg 消息处理程序

BOOL COPPEx2Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void COPPEx2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COPPEx2Dlg::OnPaint()
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
HCURSOR COPPEx2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COPPEx2Dlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void COPPEx2Dlg::OnSelchangeList1()
{
	// TODO:  在此添加控件通知处理程序代码
	 m_Listid = this->m_ListCon.GetCurSel();


}


void COPPEx2Dlg::OnBnClickedShow()
{
	// TODO:  在此添加控件通知处理程序代码
	CString strAll, strGrade;
	this->m_ListCon.GetText(m_Listid, strAll);
	//strGrade = Find()
	int place=strAll.Find(CString("成绩："));
	int length = strAll.GetLength();
	strGrade = strAll.Right(length - place);
	MessageBox(strGrade, 0, MB_OK|MB_ICONINFORMATION);

}


void COPPEx2Dlg::OnBnClickedAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	//GetDlgItemText(IDC_NAME, m_Name);
	//GetDlgItemText(IDC_SID, m_Sid);
	//GetDlgItemText(IDC_VALUE, m_Value);
	//SetDlgItemText(IDC_NAME, CString(""));
	//SetDlgItemText(IDC_SID, CString(""));
	//SetDlgItemText(IDC_VALUE, CString(""));
	UpdateData();
	CString str;
	str = (CString)"姓名：" + m_Name + ", 学号：" + m_Sid + ", 成绩：" + this->m_Value;
	this->m_ListCon.AddString(str);
	m_Name = CString("");
	m_Sid = CString("");
	m_Value = CString("");


}




void COPPEx2Dlg::OnBnClickedDelete()
{
	// TODO:  在此添加控件通知处理程序代码
	this->m_ListCon.DeleteString(this->m_Listid);

}


void COPPEx2Dlg::OnEnChangeName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void COPPEx2Dlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	this->m_ListCon.DeleteString(this->m_Listid);
	//CDialogEx::OnClose();
}
