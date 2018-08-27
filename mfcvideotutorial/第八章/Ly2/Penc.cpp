// Penc.cpp: implementation of the CPenc class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly2.h"
#include "Penc.h"
#include<math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPenc::CPenc()
{

}

CPenc::~CPenc()
{

}
void CPenc::OnLButtonDown(UINT nFlags,CPoint point)
{
   m_point.Add (point);
}
void CPenc::OnMouseMove(UINT nFlags,CPoint point,CDC*pDC)
{

  int nSize=m_point.GetSize ();
  if(!nSize)
	  return;
  if(nFlags&MK_LBUTTON)
  {
    CPoint &pt=m_point[nSize-1];
	int cx=pt.x-point.x;
	int cy=pt.y-point.y;
	if(sqrt(cx*cx+cy*cy)>2)
		m_point.Add(point);
  }
 
  
  pDC->Polyline (m_point.GetData (),m_point.GetSize());


 /*  int i=0;
   int nSize=m_point.GetSize ();
   pDC->MoveTo (m_point[0]);
   while(i<nSize)
  {
     pDC->LineTo(m_point[i]);
		 ++i;
  }*/

}
void CPenc::OnLButtonUp(UINT nFlags,CPoint point)
{
   m_point.Add (point);
}
void CPenc::OnDraw(CDC*pDC)
{
  int i=0;
  int nSize=m_point.GetSize ();
  if(!nSize)
	  return;
 /* pDC->MoveTo (m_point[0]);
  while(i<nSize)
  {
     pDC->LineTo(m_point[i]);
		 ++i;
  }*/
  pDC->Polyline (m_point.GetData (),m_point.GetSize());
  //Invalidate(FALSE);为什么系统会无法识别我的刷新函数
}
void CPenc::Select(CPoint point)
{

}
void CPenc::Offset(int x,int y)
{

}
BOOL CPenc::Track(CPoint point)
{
	int i=0,nSize=m_point.GetSize();
	while(i<nSize)
	{
	   CPoint& pt=m_point[i];
	   int cx=pt.x-point.x ;
	   int cy=pt.y-point.y;
	   if(sqrt(cx*cx+cy*cy)<15)
		   return TRUE;
	   ++i;
	}
 return FALSE;
}

