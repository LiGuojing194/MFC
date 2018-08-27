#pragma once
#include"Member.h"
class Ring
{
public:
	int m_nScale;//圈的大小
	Member*m_pStart;//开始报数的成员位置
	int m_nLoop;//报数循环数
	Member*m_pMenber;//成员
	void BuildRing();//
	void Run();
	Ring(int scale,int start,int loop);
	~Ring();
};

