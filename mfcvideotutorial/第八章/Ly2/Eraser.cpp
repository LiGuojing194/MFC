// Eraser.cpp: implementation of the CEraser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly2.h"
#include "Eraser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEraser::CEraser()
{
   // ::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));
}

CEraser::~CEraser()
{

}
void CEraser::OnLButtonDown(UINT nFlags,CPoint point)
{
 p.Add (point);  

}
void CEraser::OnMouseMove(UINT nFlags,CPoint point,CDC*pDC)
{
   // ::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));
/*	if(nFlags&MK_LBUTTON)
	{
		pDC->FillSolidRect (point.x-7,point.y-7,15,15,RGB(255,255,255));
     p=point;
	}*/
	 int nSize=p.GetSize ();
  if(!nSize)
	  return;
  if(nFlags&MK_LBUTTON)
  {
    CPoint &pt=p[nSize-1];
	int cx=pt.x-point.x;
	int cy=pt.y-point.y;
	if(sqrt(cx*cx+cy*cy)>5)
		p.Add(point);
    pDC->FillSolidRect (point.x-10,point.y-10,20,20,RGB(255,255,255));

  }
 

}
void CEraser::OnLButtonUp(UINT nFlags,CPoint point)
{

}
void CEraser::OnDraw(CDC*pDC)
{
  int i=0;
  int nSize=p.GetSize ();
  if(!nSize)
	  return;
  while(i<nSize)
  {
     pDC->FillSolidRect (p[i].x-10,p[i].y-10,20,20,RGB(255,255,255));
	 i++;

  }

}
void CEraser::Select(CPoint point)
{

}
void CEraser::Offset(int x,int y)
{

}
BOOL CEraser::Track(CPoint point)
{
 return FALSE;
}

