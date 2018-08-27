// MyTime.h: interface for the CMyTime class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTIME_H__DD0EC1BE_EEC9_4E21_9977_A4CD41695DFA__INCLUDED_)
#define AFX_MYTIME_H__DD0EC1BE_EEC9_4E21_9977_A4CD41695DFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include<time.h>
class CMyTime  
{
public:
	int Getyear()const;
	time_t m_time;
	static CMyTime  GetCurrentTime();
	CMyTime();
	virtual ~CMyTime();

};

#endif // !defined(AFX_MYTIME_H__DD0EC1BE_EEC9_4E21_9977_A4CD41695DFA__INCLUDED_)
