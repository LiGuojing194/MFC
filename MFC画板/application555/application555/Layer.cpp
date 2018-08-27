#include "stdafx.h"
#include "Layer.h"


CLayer::CLayer()
{
	m_nStatus = STU_NORMAL;
	m_clText = 0x000000;
	m_clBack = 0xfffffff;
	m_nWidth = 2;
}


CLayer::~CLayer()
{
}
