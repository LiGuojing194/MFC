#include "stdafx.h"
#include "Line.h"


CLine::CLine()
{
	m_pe = m_ps =CPoint(-1,-1);
}


CLine::~CLine()
{
}
void CLine::OnDraw(CDC *pDC)
{
	CPen pen(PS_SOLID, m_nWidth, m_clText);
	CPen*pPen = pDC->SelectObject(&pen);
	pDC->MoveTo(m_ps);
	pDC->LineTo(m_pe);
	pDC->SelectObject(pPen);
	if (m_nStatus == STU_SELECT)
	{
		pDC->FillSolidRect(m_ps.x-5,m_ps.y-5,10,10,GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_pe.x - 5, m_pe.y - 5,10,10,GetSysColor(COLOR_HIGHLIGHT));
	}
}
void CLine::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ps = point;
}
void CLine::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pe = point;
}
void CLine::OnMouseMove(UINT nFlags, CPoint point, CDC*pDC)
{
	if (!pDC)
		return;
	//CPen pen(PS_SOLID, m_nWidth, m_clText);
	if (nFlags&MK_LBUTTON)
	{
		pDC->SetROP2(R2_NOTXORPEN);
		if (m_pe.x > -1)
		{
			pDC->MoveTo(m_ps);
			pDC->LineTo(m_pe);
		}
		pDC->MoveTo(m_ps);
		pDC->LineTo(point);
		m_pe = point;
	}
}
BOOL CLine::Track(CPoint point)
{//点到直线的距离
	CRect rect(m_ps,m_pe);
	rect.NormalizeRect();
	return rect.PtInRect(point);
}


void CLine::OffSet(int cx, int cy)
{
	m_pe.Offset(cx,cy);
	m_ps.Offset(cx,cy);
}
