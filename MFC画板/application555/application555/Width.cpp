// Width.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "application555.h"
#include "Width.h"
#include "afxdialogex.h"


// CWidth �Ի���

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


// CWidth ��Ϣ�������


BOOL CWidth::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_slider.SetRange(0, 50);
	m_slider.SetTicFreq(1);
	m_slider.SetPos(m_nWidth);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CWidth::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	m_nWidth = m_slider.GetPos();
	UpdateData(FALSE);
}
int CWidth::GetWidth()
{
	return m_nWidth;
}
