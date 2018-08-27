#pragma once
#include "Layer.h"
class CPencil :
	public CLayer
{
	CArray<CPoint, CPoint>m_arr;
	BOOL Track(CPoint point);
	void OnDraw(CDC *pDC);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point,CDC*pDC=NULL);
	void OffSet(int cx,int cy);
public:

	CPencil();
	virtual ~CPencil();
};

