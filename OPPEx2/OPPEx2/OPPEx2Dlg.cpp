
// OPPEx2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OPPEx2.h"
#include "OPPEx2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// COPPEx2Dlg �Ի���



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


// COPPEx2Dlg ��Ϣ�������

BOOL COPPEx2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void COPPEx2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR COPPEx2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void COPPEx2Dlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void COPPEx2Dlg::OnSelchangeList1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	 m_Listid = this->m_ListCon.GetCurSel();


}


void COPPEx2Dlg::OnBnClickedShow()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString strAll, strGrade;
	this->m_ListCon.GetText(m_Listid, strAll);
	//strGrade = Find()
	int place=strAll.Find(CString("�ɼ���"));
	int length = strAll.GetLength();
	strGrade = strAll.Right(length - place);
	MessageBox(strGrade, 0, MB_OK|MB_ICONINFORMATION);

}


void COPPEx2Dlg::OnBnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//GetDlgItemText(IDC_NAME, m_Name);
	//GetDlgItemText(IDC_SID, m_Sid);
	//GetDlgItemText(IDC_VALUE, m_Value);
	//SetDlgItemText(IDC_NAME, CString(""));
	//SetDlgItemText(IDC_SID, CString(""));
	//SetDlgItemText(IDC_VALUE, CString(""));
	UpdateData();
	CString str;
	str = (CString)"������" + m_Name + ", ѧ�ţ�" + m_Sid + ", �ɼ���" + this->m_Value;
	this->m_ListCon.AddString(str);
	m_Name = CString("");
	m_Sid = CString("");
	m_Value = CString("");


}




void COPPEx2Dlg::OnBnClickedDelete()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->m_ListCon.DeleteString(this->m_Listid);

}


void COPPEx2Dlg::OnEnChangeName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void COPPEx2Dlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	this->m_ListCon.DeleteString(this->m_Listid);
	//CDialogEx::OnClose();
}
