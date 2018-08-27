// Width.cpp : 实现文件
//

#include "stdafx.h"
#include "application555.h"
#include "Width.h"
#include "afxdialogex.h"


// CWidth 对话框

IMPLEMENT_DYNAMIC(CWidth, CDialog)

CWidth::CWidth(CWnd* pParent /*=NULL*/)
	: CDialog(CWidth::IDD, pParent)
	, m_nWidth(2)
{

}

CWidth::~CWidth()
{
}

void CWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LINE_WIDTH, m_nWidth);
	DDX_Control(pDX, IDC_SLIDER, m_slider);
}


BEGIN_MESSAGE_MAP(CWidth, CDialog)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CWidth 消息处理程序


BOOL CWidth::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_slider.SetRange(0, 50);
	m_slider.SetTicFreq(1);
	m_slider.SetPos(m_nWidth);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CWidth::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	m_nWidth = m_slider.GetPos();
	UpdateData(FALSE);
}
int CWidth::GetWidth()
{
	return m_nWidth;
}
