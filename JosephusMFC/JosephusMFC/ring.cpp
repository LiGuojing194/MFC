#include "stdafx.h"
#include "ring.h"


Ring::Ring(int scale,int start,int loop)
{
	m_nScale = scale;
	m_nLoop = loop;
	m_pMenber = new Member[scale];
	m_pStart = &m_pMenber[start-1];
}
void Ring::BuildRing()
{
	for (int i = 0; i < m_nScale; i++)
	{
		m_pMenber[i].m_nNumber = i + 1;
		if (i==0)
		{
			m_pMenber[i].m_pLeft = &m_pMenber[m_nScale - 1];
			m_pMenber[i].m_pRight = &m_pMenber[i + 1];
		}
		else if (i == m_nScale - 1)
		{
			m_pMenber[i].m_pLeft = &m_pMenber[i - 1];
			m_pMenber[i].m_pRight = &m_pMenber[0];
		}
		else
		{
			m_pMenber[i].m_pLeft = &m_pMenber[i - 1];
			m_pMenber[i].m_pRight = &m_pMenber[i + 1];
		}
	}
}
void Ring::Run()
{
	int count = 0;
	while (m_nScale > 1)
	{
		count++;
		for (int j = 0; j < m_nLoop-1; j++)
		{
			m_pStart = m_pStart->m_pRight;
		}
		m_pStart->m_nOutNumber = count;
		m_pStart->m_pLeft->m_pRight = m_pStart->m_pRight;
		m_pStart->m_pRight->m_pLeft = m_pStart->m_pLeft;
		m_pStart = m_pStart->m_pRight;
		m_nScale--;
	}
	m_pStart->m_nOutNumber = ++count;
	//cout << "The last member is the No.";
	//cout << m_pStart->m_nNumber << endl;
	//for (int k = 0; k < count; k++)
		//cout << m_pMenber[k].m_nOutNumber << endl;
}


Ring::~Ring()
{
	delete[]m_pMenber;
}
