// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{//在构造函数中初始化成员变量
	m_ptn=m_pts=CPoint(-1,-1);


}

CLine::~CLine()
{

}
void CLine::OnLButtonDown (UINT nFlags,CPoint point)
{
  m_pts=point;

}
void CLine::OnMouseMove (UINT nFlags,CPoint point,CDC*pDC)
{
  if(!(nFlags&MK_LBUTTON))
	  return;
   pDC->SetROP2( R2_NOT);//绘制新线段过程使用反色技术
  if(m_ptn.x>=0)
  {//两次反色，对上次移动留下的反色线复原
	  pDC->MoveTo (m_pts);
	  pDC->LineTo (m_ptn);
  }
  pDC->MoveTo (m_pts);
  pDC->LineTo (m_ptn);
  m_ptn=point;


}
bvoid CLine::OnLButtonUp (UINT nFlags,CPoint point)
{
  m_ptn=point;
}
void CLine::OnDraw (CDC*pDC)
{
  pDC->MoveTo (m_pts);
  pDC->LineTo(m_ptn);
  if(m_nStatus==STU_SELECT)
  {//当选择处于选择状态，线段两个端点显示
	  pDC->FillSolidRect(m_pts.x-3,m_pts.y-3,6,6,::GetSysColor (COLOR_HIGHLIGHT));
	  pDC->FillSolidRect (m_ptn.x-3,m_ptn.y-3,6,6,::GetSysColor(COLOR_HIGHLIGHT));
  }
}
void CLine::Select(CPoint point)
{
  if(Track(point))
	  m_nStatus=STU_SELECT;
  else
	  m_nStatus=STU_NORMAL;

}
void CLine::Offset(int x,int y)
{
  m_pts.Offset (x,y);
  m_ptn.Offset(x,y);
}
BOOL CLine::Track(CPoint point)
{
	CRect rect(m_pts,m_ptn);
	rect.NormalizeRect ();
	return rect.PtInRect (point);
}