// Enter.cpp : 实现文件
//

#include "stdafx.h"
#include "JosephusMFC.h"
#include "Enter.h"
#include "afxdialogex.h"


// Enter 对话框

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


// Enter 消息处理程序


void Enter::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialog::OnOK();
}


void Enter::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);
	if (!m_dcBack)     //从文件中加载一张背景图
		m_dcBack.LoadBitmap(IDB_BITMAP1);
	//创建一张和客户区相同大小的内存画布
	if (m_dcMem)
		m_dcMem.DeleteDC();
	m_dcMem.Create(cx, cy, &CClientDC(this));
	m_dcMem.StretchBlt(0, 0, cx, cy, &m_dcBack, 0, 0,m_dcBack.Width(), m_dcBack.Height(), SRCCOPY);
	Invalidate(FALSE);
	// TODO:  在此处添加消息处理程序代码
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
	ft1.CreatePointFont(400, _T("楷体"));
	CFont*pOldFont = dc.SelectObject(&ft1);
	dc.TextOut(150, -6, _T("解约瑟夫环问题"));
	//dc.TextOut(270, 125, _T("每一个运动的点都描绘着永恒不变的真心"));
	dc.SelectObject(pOldFont);

	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}
