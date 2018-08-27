// MyTime.cpp: implementation of the CMyTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyTime.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyTime::CMyTime()
{

}

CMyTime::~CMyTime()
{

}

CMyTime CMyTime::GetCurrentTime()
{
	CMyTime t;
	t.m_time= time(NULL);
	return t;

}

int CMyTime::Getyear() const
{
	//m_time=123;这是错误的，不可以修改类成员变量的值，只能读取；
	struct tm*pt=localtime(&m_time);
	return pt->tm_year +1900;
}
