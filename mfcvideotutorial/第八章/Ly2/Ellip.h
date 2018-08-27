// Ellip.h: interface for the CEllip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIP_H__5B40E870_11C4_479A_8D80_4F8D81F48087__INCLUDED_)
#define AFX_ELLIP_H__5B40E870_11C4_479A_8D80_4F8D81F48087__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CEllip : public CLayer  
{
	CRect m_rect;
    void OnLButtonDown(UINT nFlags,CPoint point);
	void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL);
	void OnLButtonUp(UINT nFlags,CPoint point);
	void OnDraw(CDC*pDC);

	void Select(CPoint point);
	void Offset(int x,int y);
	BOOL Track(CPoint point);

public:
	CEllip();
	virtual ~CEllip();

};

#endif // !defined(AFX_ELLIP_H__5B40E870_11C4_479A_8D80_4F8D81F48087__INCLUDED_)
