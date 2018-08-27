// Layer.cpp: implementation of the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly2.h"
#include "Layer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include"Line.h"
#include"Ellip.h"
#include"Penc.h"
#include"Eraser.h"
CLayer::CLayer()
{
  m_nStatus=STU_DRAWING;
}

CLayer::~CLayer()
{

}
CLayer*CLayer::Create(int nType)
{
// switch(nType)
 //{
// case ID_DRAW_LINE:
//	 return new CLine;
// case ID_DRAW_ELLIP:
//	 return new CEllip;
 //}
//	new CLine;
	switch(nType)
	{
	case ID_DRAW_LINE:
		return new CLine;
	case ID_DRAW_ELLIP:
		return new CEllip;
	case ID_DRAW_PENC:
		return new CPenc;
	case ID_DRAW_ERASER:
		 //::SetCursor (AfxGetApp()->LoadCursor (IDC_CURSOR1));
		 return new CEraser;
	}
 return NULL;
}
