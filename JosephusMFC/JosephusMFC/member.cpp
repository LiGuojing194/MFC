#include "stdafx.h"
#include "member.h"


Member::Member(int x,int y)
{
	m_nNumber = x;
	m_nOutNumber = y;
	m_pLeft = nullptr;
	m_pRight = nullptr;
}


Member::~Member()
{
}
