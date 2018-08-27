#include "stdafx.h"
#include "Pencil.h"
#include<math.h>


CPencil::CPencil()
{
}


CPencil::~CPencil()
{
}
void CPencil::OnDraw(CDC *pDC)
{
	int i = 0, nSize = m_arr.GetSize();
	if (!nSize)
		return;
	CPen pen(PS_SOLID, m_nWidth, m_clText);
	CPen*pPen = pDC->SelectObject(&pen);
	pDC->Polyline(m_arr.GetData(),m_arr.GetSize());
	pDC->SelectObject(pPen);
	/*pDC->MoveTo(m_arr[0]);
	while (i < nSize)
	{
		pDC->LineTo(m_arr[i]);
		i++;
	}*/
	if (m_nStatus == STU_SELECT)
	{
		CPoint pt = m_arr[0];
		pDC->FillSolidRect(pt.x - 5, pt.y - 5,5,5,GetSysColor(COLOR_HIGHLIGHT));
		pt = m_arr[nSize-1];
		pDC->FillSolidRect(pt.x - 5, pt.y - 5, 5, 5, GetSysColor(COLOR_HIGHLIGHT));
	}

}
void CPencil::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_arr.Add(point);
}
void CPencil::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_arr.Add(point);
}
void CPencil::OnMouseMove(UINT nFlags, CPoint point, CDC*pDC)
{
	int nSize = m_arr.GetSize();
	if (!nSize)
		return;

	if (nFlags&MK_LBUTTON)
	{
		CPoint pt = m_arr[nSize - 1];
		double cx = pt.x - point.x;
		double cy = pt.y - point.y;
		pDC->MoveTo(pt);
		pDC->LineTo(point);
		if (sqrt(cx*cx+cy*cy)>10)
			m_arr.Add(point);
	}
}
BOOL CPencil::Track(CPoint point)
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize)
	{
		CPoint&pt = m_arr[i++];
		double cx = point.x - pt.x;
		double cy = point.y - pt.y;
		if (sqrt(cx*cx + cy*cy) < 15)
		{
			return TRUE;
		}

	}
	return FALSE;
}
void CPencil::OffSet(int cx, int cy)
{
	int i = 0, nSize = m_arr.GetSize();
	while (i < nSize)
	{
		m_arr[i++].Offset(cx,cy);
	}
}
	