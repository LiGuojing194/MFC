#pragma once
#include"Member.h"
class Ring
{
public:
	int m_nScale;//Ȧ�Ĵ�С
	Member*m_pStart;//��ʼ�����ĳ�Աλ��
	int m_nLoop;//����ѭ����
	Member*m_pMenber;//��Ա
	void BuildRing();//
	void Run();
	Ring(int scale,int start,int loop);
	~Ring();
};

