// tm.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include<stdio.h>
#include<time.h>
#include"MyTime.h"
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
/*	time_t tt=time(NULL);
	tm*pt=localtime(&tt);
	int nYear=pt->tm_year +1990;
	int nMonth=pt->tm_mon +1;
	int nDay=pt->tm_mday ;
	int nHour=pt->tm_hour ;
	int nMin=pt->tm_min ;
	int nSec=pt->tm_sec ;
	char s[200];
	sprintf(s,"当前时间：%d年%02d月%02d日%02d:%02d:%02d",nYear,nMonth,nDay,nHour,nMin,nSec);
	MessageBox(NULL,s,"提示",0);
*/
	CMyTime t=CMyTime::GetCurrentTime ();
   int nyear=t.Getyear();
	char s[100];
	sprintf(s,"今年是%d.",nyear);
	MessageBox(NULL,s,"温馨提示",0);
	return 0;
}



