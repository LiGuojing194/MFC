// Ellip1.h: interface for the CEllip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIP1_H__9536B30C_9B43_4330_A4D4_F0D53E362741__INCLUDED_)
#define AFX_ELLIP1_H__9536B30C_9B43_4330_A4D4_F0D53E362741__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class 
 : public CLayer  
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

#endif // !defined(AFX_ELLIP1_H__9536B30C_9B43_4330_A4D4_F0D53E362741__INCLUDED_)
