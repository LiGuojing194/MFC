#pragma once
enum Status
{
	STU_NORMAL,STU_SELECT
};
class CLayer
{
public:
	int m_nStatus;
	COLORREF m_clText, m_clBack;
	int m_nWidth;
	//virtual void Serialize(CArchive& ar)=0;
	virtual void OffSet(int cx,int cy)=0;
	virtual BOOL Track(CPoint point)=0;
	virtual void OnDraw(CDC *pDC)=0;//纯虚函数，无函数体
	virtual void OnLButtonDown(UINT nFlags, CPoint point)=0;
	virtual void OnLButtonUp(UINT nFlags, CPoint point)=0;
	virtual void OnMouseMove(UINT nFlags, CPoint point,CDC*pDC=NULL)=0;

	CLayer();
	virtual ~CLayer();
};

