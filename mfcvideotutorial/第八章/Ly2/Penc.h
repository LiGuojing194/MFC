// Penc.h: interface for the CPenc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PENC_H__DCFBD30F_FA97_43DE_BBDC_E98F680A61C4__INCLUDED_)
#define AFX_PENC_H__DCFBD30F_FA97_43DE_BBDC_E98F680A61C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Layer.h"

class CPenc : public CLayer  
{
	CArray<CPoint,CPoint>m_point;//所有点的集合
	
	void OnLButtonDown(UINT nFlags,CPoint point);
	void OnMouseMove(UINT nFlags,CPoint point,CDC*pDC=NULL);
	void OnLButtonUp(UINT nFlags,CPoint point);
	void OnDraw(CDC*pDC);
	void Select(CPoint point);
	void Offset(int x,int y);
	BOOL Track(CPoint point);
	
public:
	CPenc();
	virtual ~CPenc();

};

#endif // !defined(AFX_PENC_H__DCFBD30F_FA97_43DE_BBDC_E98F680A61C4__INCLUDED_)
