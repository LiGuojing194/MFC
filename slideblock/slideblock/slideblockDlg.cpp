
// slideblockDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "slideblock.h"
#include "slideblockDlg.h"
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


// CslideblockDlg �Ի���



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


// CslideblockDlg ��Ϣ�������

BOOL CslideblockDlg::OnInitDialog()
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
	m_CSlider1.SetRange(0,255);
	m_CSlider2.SetRange(0,255);
	m_CSlider3.SetRange(0,255);
	m_CSlider1.SetTicFreq(5);
	m_CSlider2.SetTicFreq(5);
	m_CSlider3.SetTicFreq(5);
	m_CProgressCtrl.SetRange(0,90);
	m_CProgressCtrl.SetStep(5);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CslideblockDlg::OnPaint()
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
HCURSOR CslideblockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CslideblockDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

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
