
// mfcoppp4Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mfcoppp4.h"
#include "mfcoppp4Dlg.h"
#include "afxdialogex.h"
#include"Student.h"
#include<map>
using namespace std;

map<CString, Student>mapstudent;

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


// Cmfcoppp4Dlg �Ի���



Cmfcoppp4Dlg::Cmfcoppp4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Cmfcoppp4Dlg::IDD, pParent)
	, m_Id(_T("0"))
	, m_Name(_T("Jhon"))
	, m_Sub1(0)
	, m_Sub2(0)
	, m_Sub3(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cmfcoppp4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_GRADE, m_Grade);
	DDX_Text(pDX, IDC_ID, m_Id);
	DDX_Control(pDX, IDC_LIST_LOG, m_Log);
	DDX_Text(pDX, IDC_NAME, m_Name);
	DDX_Control(pDX, IDC_TREE1, m_Tree);
	DDX_Text(pDX, IDC_SUB1, m_Sub1);
	DDX_Text(pDX, IDC_SUB2, m_Sub2);
	DDX_Text(pDX, IDC_SUB3, m_Sub3);
	DDX_Control(pDX, IDC_LIST_INQUIRY, m_Inquiry);
}

BEGIN_MESSAGE_MAP(Cmfcoppp4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &Cmfcoppp4Dlg::OnBnClickedAdd)
//	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &Cmfcoppp4Dlg::OnSelchangedTree1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, &Cmfcoppp4Dlg::OnDblclkTree1)
	ON_BN_CLICKED(IDC_RESET, &Cmfcoppp4Dlg::OnBnClickedReset)
	ON_BN_CLICKED(IDC_CLEAR, &Cmfcoppp4Dlg::OnBnClickedClear)
END_MESSAGE_MAP()


// Cmfcoppp4Dlg ��Ϣ�������

BOOL Cmfcoppp4Dlg::OnInitDialog()
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
	this->m_Tree.ModifyStyle(0, TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT);
	root = this->m_Tree.InsertItem(_T("�꼶"));

	root1 = this->m_Tree.InsertItem(_T("һ�꼶"), root);
	root2 = this->m_Tree.InsertItem(_T("���꼶"), root);
	root3 = this->m_Tree.InsertItem(_T("���꼶"), root);
	this->m_Tree.Expand(root,TVE_EXPAND);

	m_Inquiry.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_ONECLICKACTIVATE);
	m_Inquiry.InsertColumn(0, _T("����"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(1, _T("ѧ��"), LVCFMT_LEFT, 80);
	m_Inquiry.InsertColumn(2, _T("�꼶"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(3, _T("Sub1"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(4, _T("Sub2"), LVCFMT_LEFT, 60);
	m_Inquiry.InsertColumn(5, _T("Sub3"), LVCFMT_LEFT, 60);

	m_Grade.SetCurSel(0);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Cmfcoppp4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cmfcoppp4Dlg::OnPaint()
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
HCURSOR Cmfcoppp4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Cmfcoppp4Dlg::OnBnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	int n = m_Grade.GetCurSel();
	char*p[] = {"һ�꼶","���꼶","���꼶"};
	/*int nCount = m_Inquiry.GetItemCount();
	m_Inquiry.InsertItem(nCount, m_Name);
	m_Inquiry.SetItemText(nCount, 1, m_Id);
	m_Inquiry.SetItemText(nCount, 2, CString(p[n]));
	CString grade;
	grade.Format(L"%ld", m_Sub1); 
	m_Inquiry.SetItemText(nCount, 3,grade );
	grade.Format(L"%ld", m_Sub2);
	m_Inquiry.SetItemText(nCount, 4, grade);
	grade.Format(L"%ld", m_Sub3);
	m_Inquiry.SetItemText(nCount, 5, grade);*/

	Student stud;
	stud.grade = p[n];
	stud.id = m_Id;
	stud.name = m_Name;
	stud.sub1 = m_Sub1;
	stud.sub2 = m_Sub2;
	stud.sub3 = m_Sub3;

	mapstudent[m_Name] = stud;

	switch (n)
	{
	case 0: this->m_Tree.InsertItem(m_Name, root1); this->m_Tree.Expand(root1, TVE_EXPAND); break;
	case 1: this->m_Tree.InsertItem(m_Name, root2); this->m_Tree.Expand(root2, TVE_EXPAND); break;
	case 2: this->m_Tree.InsertItem(m_Name, root3); this->m_Tree.Expand(root3, TVE_EXPAND); break;
	}
	//CString s;
	//s.Format(_T("%lf"),m_Sub2);
	//SetDlgItemText(IDC_SUB1,s);
	////AfxMessageBox(m_Sub1);



	CTime tm = CTime::GetCurrentTime();
    CString str = tm.Format("%X DATA ADD");
	m_Log.AddString(str);
	
}


//void Cmfcoppp4Dlg::OnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	
//	*pResult = 0;
//}


void Cmfcoppp4Dlg::OnDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_Inquiry.DeleteAllItems();
	HTREEITEM treeItemSel = m_Tree.GetSelectedItem();
	CString choice = m_Tree.GetItemText(treeItemSel);
	Student temp = mapstudent[choice];
	int nCount = m_Inquiry.GetItemCount();
	m_Inquiry.InsertItem(nCount, temp.name);
	m_Inquiry.SetItemText(nCount, 1, temp.id);
	m_Inquiry.SetItemText(nCount, 2, temp.grade);
	CString grade;
	grade.Format(_T("%lf"), temp.sub1);
	m_Inquiry.SetItemText(nCount, 3, grade);
	grade.Format(_T("%lf"), temp.sub2);
	m_Inquiry.SetItemText(nCount, 4, grade);
	grade.Format(L"%lf", temp.sub3);
	m_Inquiry.SetItemText(nCount, 5, grade);

	double aver = (temp.sub1 + temp.sub2 + temp.sub3) / 3;
	grade.Format(_T("The average grade of this student is %lf."), aver);
	AfxMessageBox(grade);

	CTime tm = CTime::GetCurrentTime();
	CString str = tm.Format("%X TREE DOUBLE CLICKED");
	m_Log.AddString(str);
	*pResult = 0;
}


void Cmfcoppp4Dlg::OnBnClickedReset()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//SetDlgItemText(IDC_NAME, _T("Jhon"));
	//SetDlgItemText(IDC_ID, _T("0"));
	//SetDlgItemInt(IDC_SUB1, 0);
	//SetDlgItemInt(IDC_SUB2, 0);
	//SetDlgItemInt(IDC_SUB3, 0);
	m_Id = "0";
	m_Name = "Jhon";
	m_Sub1 = 0;
	m_Sub2 = 0;
	m_Sub3 = 0;
	m_Grade.SetCurSel(0);
	UpdateData(FALSE);



	CTime tm = CTime::GetCurrentTime();
	CString str = tm.Format("%X DATA RESRT");
	m_Log.AddString(str);
}


void Cmfcoppp4Dlg::OnBnClickedClear()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_Log.ResetContent();
}
