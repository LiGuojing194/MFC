// Ellip.cpp: implementation of the CEllip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly2.h"
#include "Ellip.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllip::CEllip()
{
  m_rect.SetRect (-1,-1,-1,-1);
}

CEllip::~CEllip()
{

}
void CEllip::OnLButtonDown (UINT nFlags,CPoint point)
{
  m_rect.left=point.x;
  m_rect.top=point.y;

}
void CEllip::OnMouseMove (UINT nFlags,CPoint point,CDC*pDC)
{
  if(!(nFlags&MK_LBUTTON))
	  return;
   pDC->SetROP2( R2_NOT);//绘制新线段过程使用反色技术
   pDC->SelectStockObject (NULL_BRUSH);
  if(m_rect.right>=0)
  {
	  pDC->Ellipse(m_rect);
  }
  m_rect.right=point.x;
  m_rect.bottom=point.y;
  pDC->Ellipse(m_rect);
}
void CEllip::OnLButtonUp (UINT nFlags,CPoint point)
{
  m_rect.right=point.x;
  m_rect.bottom=point.y;
  m_rect.NormalizeRect();
}
void CEllip::OnDraw (CDC*pDC)
{
  pDC->Ellipse(m_rect);
  if(m_nStatus==STU_SELECT)
  {//当选择处于选择状态，线段两个端点显示
	  pDC->FillSolidRect(m_rect.left-3,m_rect.top-3,6,6,::GetSysColor (COLOR_HIGHLIGHT));
	  pDC->FillSolidRect(m_rect.right-3,m_rect.top-3,6,6,::GetSysColor (COLOR_HIGHLIGHT));
	  pDC->FillSolidRect(m_rect.left-3,m_rect.bottom-3,6,6,::GetSysColor (COLOR_HIGHLIGHT));
      pDC->FillSolidRect(m_rect.right-3,m_rect.bottom-3,6,6,::GetSysColor (COLOR_HIGHLIGHT));

  }
}
void CEllip::Select(CPoint point)
{
  if(m_rect.PtInRect(point))
	  m_nStatus=STU_SELECT;
  else
	  m_nStatus=STU_NORMAL;

}
void CEllip::Offset(int x,int y)
{
  m_rect.OffsetRect(x,y);
}
BOOL CEllip::Track(CPoint point)
{
	return m_rect.PtInRect (point);
}
