#pragma once
#include "Layer.h"
class CLine :
	public CLayer
{
	CPoint m_ps, m_pe;
	BOOL Track(CPoint point);
	void OnDraw(CDC *pDC);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
    void OnMouseMove(UINT nFlags, CPoint point,CDC*pDC=NULL);
	void OffSet(int cx, int cy);
public:
	CLine();
	virtual ~CLine();
};

