#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle()
{
	m_rect.SetRect(-1, -1, -1, -1);
}


CRectangle::~CRectangle()
{
}

void CRectangle::OnDraw(CDC *pDC)
{
	CPen pen(PS_SOLID, m_nWidth, m_clText);
	CPen*pPen = pDC->SelectObject(&pen);
	if (m_clBack > 0xffffff)
	{
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->Rectangle(m_rect);
	}
	else
	{
		CBrush brush;
		brush.CreateSolidBrush(m_clBack);
		pDC->SelectObject(&brush);
		pDC->Rectangle(m_rect);
	}
	pDC->SelectObject(pPen);
	if (m_nStatus == STU_SELECT)
	{
		CPoint pt = m_rect.CenterPoint();
		pDC->FillSolidRect(m_rect.left - 5, pt.y - 5, 10, 10, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(m_rect.right - 5, pt.y - 5, 10, 10, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(pt.x, m_rect.top - 5, 10, 10, GetSysColor(COLOR_HIGHLIGHT));
		pDC->FillSolidRect(pt.x - 5, m_rect.bottom - 5, 10, 10, GetSysColor(COLOR_HIGHLIGHT));
	}
}
void CRectangle::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_rect.TopLeft() = point;
}
void CRectangle::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_rect.BottomRight() = point;
	m_rect.NormalizeRect();
}
void CRectangle::OnMouseMove(UINT nFlags, CPoint point, CDC*pDC)
{
	if (!pDC)
		return;
	if (nFlags&MK_LBUTTON)
	{
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SetROP2(R2_NOTXORPEN);
		if (m_rect.right > -1)
		{
			pDC->Rectangle(m_rect);
		}
		m_rect.BottomRight() = point;
		pDC->Rectangle(m_rect);
	}
}
BOOL CRectangle::Track(CPoint point)
{
	return(m_rect.PtInRect(point));
}

void CRectangle::OffSet(int cx, int cy)
{
	m_rect.OffsetRect(cx, cy);
}
