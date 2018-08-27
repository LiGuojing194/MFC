// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__BB908163_D33D_499C_A38F_C37D2B3FB5E7__INCLUDED_)
#define AFX_LINE_H__BB908163_D33D_499C_A38F_C37D2B3FB5E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CLine : public CLayer  
{
	CPoint m_pts,m_ptn;//记录线段的起点的终点
	CPoint m_last;   //用于显示绘制过程
	virtual void OnLButtonDown(UINT nFlags,CPoint point);
	virtual void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL);
	virtual void OnLButtonUp(UINT nFlags,CPoint point);
	virtual void OnDraw(CDC*pDC);

	virtual void Select(CPoint point);
	virtual void Offset(int x,int y);
	virtual BOOL Track(CPoint point);

public:
	CLine();
	virtual ~CLine();

};

#endif // !defined(AFX_LINE_H__BB908163_D33D_499C_A38F_C37D2B3FB5E7__INCLUDED_)
