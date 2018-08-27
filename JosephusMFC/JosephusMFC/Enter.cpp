// Enter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JosephusMFC.h"
#include "Enter.h"
#include "afxdialogex.h"


// Enter �Ի���

IMPLEMENT_DYNAMIC(Enter, CDialog)

Enter::Enter(CWnd* pParent /*=NULL*/)
	: CDialog(Enter::IDD, pParent)
{

}

Enter::~Enter()
{
}

void Enter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Enter, CDialog)
	ON_BN_CLICKED(IDOK, &Enter::OnBnClickedOk)
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Enter ��Ϣ�������


void Enter::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialog::OnOK();
}


void Enter::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (!m_dcBack)     //���ļ��м���һ�ű���ͼ
		m_dcBack.LoadBitmap(IDB_BITMAP1);
	//����һ�źͿͻ�����ͬ��С���ڴ滭��
	if (m_dcMem)
		m_dcMem.DeleteDC();
	m_dcMem.Create(cx, cy, &CClientDC(this));
	m_dcMem.StretchBlt(0, 0, cx, cy, &m_dcBack, 0, 0,m_dcBack.Width(), m_dcBack.Height(), SRCCOPY);
	Invalidate(FALSE);
	// TODO:  �ڴ˴������Ϣ����������
}


void Enter::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	dc.BitBlt(0, 0, m_dcMem.Width(), m_dcMem.Height(), &m_dcMem, 0, 0, SRCCOPY);

	//CPen pen1(PS_SOLID, 2, RGB(0, 255, 0));
	//CPen*pOldPen = dc.SelectObject(&pen1);
	//	CPen pen2(PS_DOT,1,RGB(255,0,0));
	//	dc.SelectObject (&pen2);
	//   dc.Ellipse (150,100,200,150);
	// CPaintDC pDC(this);
	CFont ft1;
	ft1.CreatePointFont(400, _T("����"));
	CFont*pOldFont = dc.SelectObject(&ft1);
	dc.TextOut(150, -6, _T("��Լɪ������"));
	//dc.TextOut(270, 125, _T("ÿһ���˶��ĵ㶼��������㲻�������"));
	dc.SelectObject(pOldFont);

	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}
