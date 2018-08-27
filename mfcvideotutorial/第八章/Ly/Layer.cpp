// Layer.cpp: implementation of the CLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Ly.h"
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
#include"Ellip1.h"
CLayer::CLayer()
{//Ĭ�ϻ�ͼ״̬�ǻ滭
  m_nStatus=STU_DRAWING;


}

CLayer::~CLayer()
{

}
CLayer*CLayer::Create(int nType)
{
/* switch(nType)
 {
 case ID_DRAW_LINE:
	 return new CLine;
 case ID_DRAW_ELLIP:
	 return new CEllip;
 }
 return NULL;*/
}
