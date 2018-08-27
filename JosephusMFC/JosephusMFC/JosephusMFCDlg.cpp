
// JosephusMFCDlg.cpp : ʵ���ļ�
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


// CJosephusMFCDlg �Ի���



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


// CJosephusMFCDlg ��Ϣ�������

BOOL CJosephusMFCDlg::OnInitDialog()
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
	m_list_log.InsertColumn(0, _T("ʱ��"), LVCFMT_LEFT, 90);// ������ 
	m_list_log.InsertColumn(1, _T("����"), LVCFMT_LEFT, 300);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CJosephusMFCDlg::OnPaint()
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
HCURSOR CJosephusMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//Ring ring(m_nScaleDlg, m_nStartDlg, m_nLoopDlg);
void CJosephusMFCDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	UpdateData();
	if (m_nScaleDlg < 1)
	{
		MessageBox(_T("��Ա�������벻С��1��"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("Լɪ�򻷹���ʧ��--������С��1"));
		return;
	}
	if (m_nStartDlg<1 || m_nStartDlg>m_nScaleDlg)
	{
		MessageBox(_T("��ʼ������λ�ñ������������ķ�Χ�ڣ�"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("Լɪ�򻷹���ʧ��--��ʼλ���趨Խ��"));
		return;
	}
	if (m_nLoopDlg<1)
	{
		MessageBox(_T("ѭ�������벻С��1��"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("Լɪ�򻷹���ʧ��--ѭ����С��1"));
		return;
	}
    m_nBuildCount++;
	m_nLastScale = m_nScaleDlg;
	m_pMenberDlg = new Member[m_nScaleDlg];
	Ring ring(m_nScaleDlg, m_nStartDlg, m_nLoopDlg);//�˴������ring,�������������������������������ݽ���������������ڲ鿴��ť����Ϣӳ�亯�����޷��鿴������
	ring.BuildRing();
	ring.Run();
	MessageBox(_T("Լɪ�򻷹����ɹ���"));
	CTime tm = CTime::GetCurrentTime();
	CString str = tm.Format("%X");
	int nRow = m_list_log.InsertItem(0, str);
	m_list_log.SetItemText(nRow, 1, _T("Լɪ�򻷹����ɹ���"));
	for (int i = 0; i < m_nScaleDlg; i++)
	{
		m_pMenberDlg[i] = ring.m_pMenber[i];
	}
	//m_pMenberDlg = ring.m_pMenber;
	CString str1,str2;
	str1.Format(L"��%d�ι�������������%d  ��ʼ��ţ�%d  ѭ������%d  ���һ���˳�����%d��",m_nBuildCount,m_nScaleDlg,m_nStartDlg,m_nLoopDlg,ring.m_pStart->m_nNumber);
	m_ListOutput.SetHorizontalExtent(550);
	this->m_ListOutput.AddString(str1);
	for (int i = 0; i < m_nScaleDlg; i++)
	{
		str2.Format(L"��Ա��ţ� %d    �˳���ţ�%d", i+1, m_pMenberDlg[i].m_nOutNumber);
		this->m_ListOutput.AddString(str2);
	}
	m_nScaleDlg = 0;
	m_nStartDlg = 0;
	m_nLoopDlg = 0;
	UpdateData(FALSE);
    tm = CTime::GetCurrentTime();
    str = tm.Format("%X");
    nRow = m_list_log.InsertItem(0, str);
	m_list_log.SetItemText(nRow, 1, _T("Լɪ�����гɹ���"));

}


void CJosephusMFCDlg::OnBnClickedClear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	this->m_ListOutput.ResetContent();
}


void CJosephusMFCDlg::OnBnClickedLookfor()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (!m_pMenberDlg)
	{
		MessageBox(_T("���ȹ�����Լɪ�򻷣�"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("�鿴�˳����ʧ��--δ����Լɪ��"));
		return;
	}
	UpdateData();
	if (m_nFindDlg<1 || m_nFindDlg>m_nLastScale)
	{
		MessageBox(_T("�������ӦΪ����0,����������������������"));
		CTime tm = CTime::GetCurrentTime();
		CString str = tm.Format("%X");
		int nRow = m_list_log.InsertItem(0, str);
		m_list_log.SetItemText(nRow, 1, _T("�鿴�˳����ʧ��--���ҷ�ΧԽ��"));
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
	m_list_log.SetItemText(nRow, 1, _T("�鿴�˳�����ɹ���"));
}


void CJosephusMFCDlg::OnBnClickedHelp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Help*dlg = new Help();
	dlg->Create(IDD_HELP); //����һ����ģ̬�Ի���  
	dlg->ShowWindow(SW_SHOWNORMAL); //��ʾ��ģ̬�Ի���  
	//dlg.ShowWindow(SW_SHOWNORMAL);

}


void CJosephusMFCDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
