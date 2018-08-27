// Eraser.h: interface for the CEraser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ERASER_H__EEDF7FB3_66DA_4B8C_8F2B_D5F185A55274__INCLUDED_)
#define AFX_ERASER_H__EEDF7FB3_66DA_4B8C_8F2B_D5F185A55274__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CEraser : public CLayer  
{
	CArray<CPoint,CPoint>p;//所有点的集合

	void OnLButtonDown(UINT nFlags,CPoint point);
	void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL);
	void OnLButtonUp(UINT nFlags,CPoint point);
	void OnDraw(CDC*pDC);
	void Select(CPoint point);
	void Offset(int x,int y);
	BOOL Track(CPoint point);

public:
	CEraser();
	virtual ~CEraser();

};

#endif // !defined(AFX_ERASER_H__EEDF7FB3_66DA_4B8C_8F2B_D5F185A55274__INCLUDED_)
